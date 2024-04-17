# firstgame
 LTNC-FirstGame

(1)
    Họ Tên : Nguyễn Văn Hoà
    Lớp : K68-CA2
    MSV : 23021556

(2)
    Chủ đề game: Flappy bird

(3)
    Ngưỡng điểm cho là xứng đáng: ngưỡng 8.5 thậm chí là 9-10

(4) Lý do: Trong game này có

    - Đầy đủ những tính năng mà cô hướng dẫn : ảnh, âm thanh, text, animation,  background trôi, xử lý va chạm,... nhưng có phát triển thêm;

    - Phát triển thêm chương trình : Menu, chọn nhân vật, chơi lại, điểm ván vừa chơi, điểm kỉ lục, pause game, exit;

    - Đồ hoạ ở mức ổn;

    - Có sử dụng thêm thuật toán :

        + Mô tả ngắn gọn như sau : Toàn bộ chương trình khi chơi là một mảng 2 chiều, mỗi ô được thêm vào 1 hình ảnh, khi bay nếu chạm vào 1 ô mà ô đấy có lưu hình ảnh cái ống (flappy bird) hay hai phần viền trên dưới thì chết và khi bay qua ô ống đấy mà không chạm vào thì được cộng điểm;

        + Phần load image có gán thêm rect của từng ảnh để khi load từng ô hình ảnh sẽ được đặt ở vị trí chính xác;

        + Phần background trôi có dùng thuật toán theo cách riêng (có làm trước khi cô hướng dẫn bài background trôi) : nôm na là cô sử dụng 2 background nối liền nhau chạy từ trái sang phải còn chương trình của em là những ô hình ảnh nối tiếp nhau được phát liên tục trên màn hình;

        + Phần sprite cũng có dùng theo cách riêng : cô dùng mảng 2 chiều còn em chỉ dùng 1 chiều;

        + Xử lý khi nhảy : về trục Ox thì khi nhấn nút nhảy sẽ cộng vào một giá trị rất nhỏ cho đến khi đến một giá trị nhất định sẽ thôi cộng (tránh trường hợp cộng cả một giá trị lớn nhìn sẽ là thành một góc vuông do di chuyển lên theo trục Ox trước rồi đến Oy);

        + Xử lý thời gian : Bình thường tại một vòng lặp sẽ chạy rất nhanh dẫn đến trường hợp chim sẽ bay rất nhanh nên để xử lý thì cuối vòng lặp phải sử dụng SDL_Delay để chậm lại 1 thời gian xác định (có tính toán trong phần cuối hàm main);

        + Điểm kỉ lục : Nếu điểm ván vừa chơi lớn hơn điểm kỉ lục thì cập nhật không thì thôi;

    - Tự học, tự tham khảo sau đó HOÀN TOÀN tự code phát triển chương trình;

    - Học và tham khảo tại 3 nguồn chính sau:
        + Bài hướng dẫn của cô
        + Lazyfoo
        + Một vài nguồn khác nhưng chỉ là một chút nên em không nhớ trong số đó có link kênh sau
            Link : https://www.youtube.com/@PhatTrienPhanMem123AZ

