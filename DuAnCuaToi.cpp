#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define FILE_NAME "thuvien.txt"

typedef struct {
    int id;
    char ten[50];
    char tacGia[50];
    int daMuon;
    char nguoiMuon[50];
} Sach;

Sach ds[MAX];
int n = 0;
int nextId = 1;

void docDong(const char *loiNhac, char *buf, int size) {
    printf("%s", loiNhac);
    if (!fgets(buf, size, stdin)) { buf[0] = 0; return; }
    buf[strcspn(buf, "\n")] = 0;
    for (int i = 0; buf[i]; i++)
        if (buf[i] == '|') buf[i] = ' ';
}

int docSo(const char *loiNhac) {
    char buf[32], *end;
    while (1) {
        printf("%s", loiNhac);
        if (!fgets(buf, sizeof(buf), stdin)) return 0;
        long x = strtol(buf, &end, 10);
        if (end != buf && (*end == '\n' || *end == '\0')) return (int)x;
        printf("Vui long nhap so!\n");
    }
}

void toLower(char *dst, const char *src) {
    int i;
    for (i = 0; src[i]; i++) dst[i] = (char)tolower((unsigned char)src[i]);
    dst[i] = 0;
}

int timTheoId(int id) {
    for (int i = 0; i < n; i++)
        if (ds[i].id == id) return i;
    return -1;
}

void inMotSach(int i) {
    printf("%-4d | %-25s | %-20s | ", ds[i].id, ds[i].ten, ds[i].tacGia);
    if (ds[i].daMuon) printf("Da muon (%s)\n", ds[i].nguoiMuon);
    else printf("Con\n");
}

void luuFile() {
    FILE *f = fopen(FILE_NAME, "w");
    if (!f) { printf("Khong mo duoc file de ghi!\n"); return; }
    for (int i = 0; i < n; i++)
        fprintf(f, "%d|%s|%s|%d|%s\n", ds[i].id, ds[i].ten, ds[i].tacGia,
                ds[i].daMuon, ds[i].nguoiMuon);
    fclose(f);
    printf("Da luu %d cuon sach vao %s\n", n, FILE_NAME);
}

void docFile() {
    FILE *f = fopen(FILE_NAME, "r");
    if (!f) return;
    char line[256];
    while (n < MAX && fgets(line, sizeof(line), f)) {
        Sach s;
        s.nguoiMuon[0] = 0;
        int kq = sscanf(line, "%d|%49[^|]|%49[^|]|%d|%49[^\n]",
                        &s.id, s.ten, s.tacGia, &s.daMuon, s.nguoiMuon);
        if (kq >= 4) {
            ds[n++] = s;
            if (s.id >= nextId) nextId = s.id + 1;
        }
    }
    fclose(f);
    printf("Da doc %d cuon sach tu %s\n", n, FILE_NAME);
}

void themSach() {
    if (n >= MAX) { printf("Thu vien day!\n"); return; }
    Sach s;
    docDong("Ten sach: ", s.ten, sizeof(s.ten));
    if (s.ten[0] == 0) { printf("Ten sach khong duoc de trong!\n"); return; }
    docDong("Tac gia: ", s.tacGia, sizeof(s.tacGia));
    if (s.tacGia[0] == 0) strcpy(s.tacGia, "Khuyet danh");
    s.id = nextId++;
    s.daMuon = 0;
    s.nguoiMuon[0] = 0;
    ds[n++] = s;
    printf("Da them sach co id = %d\n", s.id);
}

void hienThi() {
    if (n == 0) { printf("Thu vien trong.\n"); return; }
    printf("%-4s | %-25s | %-20s | %s\n", "ID", "Ten", "Tac gia", "Trang thai");
    for (int i = 0; i < n; i++) inMotSach(i);
}

void timSachTheoId() {
    int vt = timTheoId(docSo("Nhap id sach: "));
    if (vt == -1) printf("Khong tim thay!\n");
    else inMotSach(vt);
}

void timSachTheoTen() {
    char tuKhoa[50], a[50], b[50];
    docDong("Nhap tu khoa: ", tuKhoa, sizeof(tuKhoa));
    toLower(a, tuKhoa);
    int dem = 0;
    for (int i = 0; i < n; i++) {
        toLower(b, ds[i].ten);
        if (strstr(b, a)) { inMotSach(i); dem++; }
    }
    if (dem == 0) printf("Khong tim thay sach nao.\n");
}

void muonSach() {
    int vt = timTheoId(docSo("Nhap id sach can muon: "));
    if (vt == -1) { printf("Khong tim thay!\n"); return; }
    if (ds[vt].daMuon) { printf("Sach da duoc muon boi %s!\n", ds[vt].nguoiMuon); return; }
    docDong("Ten nguoi muon: ", ds[vt].nguoiMuon, sizeof(ds[vt].nguoiMuon));
    if (ds[vt].nguoiMuon[0] == 0) { printf("Ten nguoi muon khong duoc de trong!\n"); return; }
    ds[vt].daMuon = 1;
    printf("Muon thanh cong!\n");
}

void traSach() {
    int vt = timTheoId(docSo("Nhap id sach can tra: "));
    if (vt == -1) { printf("Khong tim thay!\n"); return; }
    if (!ds[vt].daMuon) { printf("Sach nay dang o trong thu vien, khong can tra!\n"); return; }
    ds[vt].daMuon = 0;
    ds[vt].nguoiMuon[0] = 0;
    printf("Tra sach thanh cong!\n");
}

void xoaSach() {
    int vt = timTheoId(docSo("Nhap id sach can xoa: "));
    if (vt == -1) { printf("Khong tim thay!\n"); return; }
    if (ds[vt].daMuon) { printf("Sach dang duoc muon, khong the xoa!\n"); return; }
    for (int i = vt; i < n - 1; i++) ds[i] = ds[i + 1];
    n--;
    printf("Da xoa sach!\n");
}

int main() {
    docFile();
    int chon;
    do {
        printf("\n===== QUAN LY THU VIEN =====\n"
               "1. Them sach\n"
               "2. Hien thi tat ca\n"
               "3. Tim theo id\n"
               "4. Tim theo ten\n"
               "5. Muon sach\n"
               "6. Tra sach\n"
               "7. Xoa sach\n"
               "8. Luu file\n"
               "0. Thoat (tu dong luu)\n");
        chon = docSo("Chon: ");
        switch (chon) {
            case 1: themSach(); break;
            case 2: hienThi(); break;
            case 3: timSachTheoId(); break;
            case 4: timSachTheoTen(); break;
            case 5: muonSach(); break;
            case 6: traSach(); break;
            case 7: xoaSach(); break;
            case 8: luuFile(); break;
            case 0: luuFile(); printf("Tam biet!"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);
    return 0;
}
