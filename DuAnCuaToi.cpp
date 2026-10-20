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
}Sach;

Sach ds[MAX];	
	int n = 0;
	int NextId = 1;
	
void docDong(const char *loiNhac, char *buf, int size){
	printf("%s", loiNhac);
	if(!fgets(buf,size,stdin)){buf[0] = 0; return;}
	buf[strcspn(buf,"\n")] = 0;
	for (int i=0; buf[i]; i++)
	if (buf[i] == '|') buf[i] = '';
}
int docSo(const char *loiNhac) {
	char buf[32], *end;
	while (1) {
		printf("%s", loiNhac);
	if(!fgets(buf,sizeof(buf),stdin)) return 0;
	long x = strtol(buf, &end, 10);
	if (end != buf && (*end == '\n' || *end == '\0')) return(int)x;
		printf("Vui long nhap so!\n");
	}
}
void luuFile()
	
	
void themSach()
	void hienThi()
	void timSachTheoId()
	void timSachTheoTen()
	void muonSach()
	void traSach()
	
	int main() {
	int chon;
	do {
		printf("\n====Quan Ly Thu Vien====\n"
		"1. Them Sach\n"
		"2. Hien thi tat ca\n"
		"3. Tim theo id\n"
		"4. Tim theo ten\n"
		"5. Muon Sach\n"
		"6. Tra Sach\n"
		"7. Luu file\n"
		"0. Thoat\n");
	chon = docSo("chon: ");
	switch(chon){
		case 1: themSach();
		break;
		case 2: hienThi();
		break;
		case 3: timSachTheoId();
		break;
		case 4: timSachTheoTen();
		break;
		case 5: muonSach();
		break;
		case 6: traSach();
		break;
		case 7: luuFile();
		break;
		case 0: luuFile();
		printf("Tam biet va hen gap lai quy khach");
		break;
		default: printf("lua chon khong hop le!\n");
		
	}
}while(chon!=0);
	return 0;
}
