# HangMan2

# Introduction
- Sinh viên thực hiện: Nguyễn Duy Hưng 
- MSSV: 20020108
- Lớp: QH-2020-I/CQ-I-C-B

# Nội dung: 
Bài tập lớn : Game (Môn học: Lập trình nâng cao, INT2215 1) 

# Tên trò chơi: 
Hangman2
Ý tưởng bài tập lớn:
- Phát triển, cải tiến từ phiên bản console
- Thêm nhiều level cho người chơi
- Hướng đến việc cho mọi người luyện tập tiếng anh

# Chức năng năng chính:

## Menu (Màn hình chính):
- CHƠI (PLAY)
- BEST SCORE
- Hướng dẫn chơi (HOW TO PLAY)
- Thoát game (EXIT GAME)

## Qúa trình chơi
Khi người chơi chọn "PLAY", màn hình sẽ hiện ra 5 level với các mức độ từ dễ đến khó, độ khó được chia ra theo số lượng từ vựng có trong file từ vựng và số lượng chữ cái xuất hiện trong từ. Bởi vậy, sẽ không tránh khỏi việc có thể người sẽ gặp trường hợp phải đoán từ lạ ở mức độ dễ, nhưng lại đoán từ dễ ở mức độ khó. Nhưng càng chơi, mức độ lại thể hiện đúng với số điểm mà người chơi có thể dành được. Ở đây tên của 5 level lần lượt là:
- Very easy
- Easy
- Medium
- Hard
- Extremely hard

## Từ vựng 
Em có sử dụng 3 file từ vựng với số lượng từ khác nhau để có thể phân cấp độ cho các level:
- vocab_easy: 500 từ
- vocab_medium: 1500 từ
- vocav_hard: 3000 từ

## Thông báo
Tùy vào số lượt đoán còn lại, sẽ có những dòng text cùng với những âm thanh khác nhau(khi chọn đúng/sai) bao gồm:
- Thông báo đoán đúng, sai
- Hiển thị các chữ cái đã đoán
- Cảnh báo khi số lượt đoán còn 5

## Xử lý sự kiện
Sau mỗi lượt đoán từ, số điểm của người chơi sẽ được hiển thị, hệ thống sẽ ghi nhận xem số điểm của người chơi có đạt được hay phá được kỉ lục (best score) của game hay không, nếu có sẽ hiện ra thông báo.

Sau đó sẽ đến với thông báo muốn chơi tiếp hay không. Nếu chọn có, người chơi sẽ được quay lại để chọn level và tiếp tục thực hiện như trên, nếu chọn không thì người chơi sẽ trở về màn hình chính.

## Điểm đạt được khi trả lời đúng 1 câu tương ứng với level
- Very easy: 1
- Easy: 2
- Medium: 3
- Hard: 4
- Extremely Hard: 5

# Animation:
- Hình ảnh
- Âm thanh
- Chuyển cảnh
- Đổ bóng

# Demo:
Mọi người có thêm xem demo game [tại đây](https://www.youtube.com/watch?v=Z3XwjhtQjno&t=2s)
