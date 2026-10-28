------------------------ HỆ THỐNG QUẢN LÝ THƯ VIỆN  -----------------------------

1. Giới thiệu đề tài 
-----------------------
Tên đề tài: xây dựng chương trình quản lý thư viện bằng ngôn ngữ C.

 Chương trinh hỗ trợ công việc quản lý trong thư viện, bao gồm các chức năng thêm sách,
 hiển thị danh sách, tìm sách, mượn sách, trả sách, xóa sách và lưu tệp dữ liệu vào 
 thuvien.txt

2. Thành viên và phân công 
-----------------------------
Lê Việt Hoàng (NHÓM TRƯỞNG) - Quản lí toàn bộ dự án, code chính của dự án.
Nguyễn Thị NGọc PHượng - Bổ sung thông tin cho code, readme và thuyết trình cho dự án.

3. CÁC CHỨC NĂNG
-------------------

3.1 Thêm sách :
- Nhập tên sách và tác giả
- Tên sách không được để trống.
- Nếu không nhập tác giả, chương trình gán "Khuyết danh".
- Mỗi sách được cấp 1 ID tự động.

3.2 Hiển thị tất cả: 
- Hiển thị ID, tên sách, tác giả và trạng thái mượn sách.

3.3 Tìm sách theo ID :
- Tìm và hiển thị sách có ID tương ứng.

3.4 Tìm sách theo tên:
- Tìm sách bằng từ khóa nằm trong tên sách.
- Việc tìm kiếm không phân biệt chữ hoa và chữ thường đối với các ký tự được hàm 
tolower() xử lý theo locale hiện tại.

3.5 Mượn sách:
- Nhập ID sách và tên người mượn.
- Không cho mượn sách không tồn tại, sách đã được mượn hoặc để trống 
tên người mượn.

3.6 Trả sách:
- Nhập ID sách.
- Cập nhật sách về trạng thái còn trong thư viện.

3.7 Xóa sách :
- Xóa sách theo ID sách.
- Không xóa sách đang được mượn.

3.8 Lưu tệp:
- Ghi danh sách sách hiện tại vào tệp thuvien.txt.

3.0 Thoát chương trình:
- Tự lưu dữ liệu trước khi kết thúc chương trình.


3. Công nghệ sử dụng
Ngôn ngữ lập trình: C.
Trình biên dịch: Dev C
Môi trường phát triển: Dev C


4. Cấu trúc dự án
Warehouse-Inventory-Management-System/
├── main.c
├── README.md
└── .vscode/
    └── tasks.json
5. Yêu cầu hệ thống
Để chạy chương trình, cần chuẩn bị:

Visual Studio Code.
Extension C/C++ của Microsoft.
Trình biên dịch GCC đã được cài đặt và cấu hình trong PATH.
6. Hướng dẫn cài đặt và chạy chương trình
Bước 1: Mở thư mục dự án
Mở thư mục chứa mã nguồn bằng Visual Studio Code.

Bước 2: Biên dịch chương trình
Mở Terminal tại thư mục dự án và chạy lệnh:

gcc main.c -o warehouse
Bước 3: Chạy chương trình
Trên Windows:

.\warehouse.exe
Trên Linux hoặc macOS:

./warehouse
7. Hướng dẫn sử dụng
Khởi chạy chương trình.
Chọn chức năng tương ứng trong menu.
Nhập thông tin sản phẩm theo yêu cầu.
Thực hiện các thao tác quản lý hàng hóa.
Chọn chức năng thoát để kết thúc chương trình.
8. Cấu trúc dữ liệu
Mỗi sản phẩm có thể bao gồm các thông tin:

Mã sản phẩm.
Tên sản phẩm.
Số lượng.
Đơn giá.
9. Mục tiêu dự án
Vận dụng kiến thức cơ bản về lập trình C.
Thực hành sử dụng struct, mảng, hàm và vòng lặp.
Xây dựng các chức năng CRUD: thêm, xem, sửa và xóa dữ liệu.
Làm quen với quy trình quản lý nhập xuất hàng hóa.
10. Hướng phát triển
Lưu dữ liệu vào tệp để sử dụng lại sau khi tắt chương trình.
Bổ sung chức năng tìm kiếm sản phẩm.
Sắp xếp danh sách sản phẩm.
Kiểm tra dữ liệu đầu vào và xử lý lỗi.
Thống kê số lượng hàng tồn kho và lịch sử nhập xuất.
