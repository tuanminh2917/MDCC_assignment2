import cv2
import random

# Mở video đầu vào
cap = cv2.VideoCapture('Assignment800k.mkv')  # đổi thành file của bạn nếu khác
fps = cap.get(cv2.CAP_PROP_FPS)
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

# Thông tin thời gian
drop_start_time = 10  # giây
drop_start_frame = int(drop_start_time * fps)

# Tạo đối tượng ghi video đầu ra
fourcc = cv2.VideoWriter_fourcc(*'vp90')  
out = cv2.VideoWriter('temp_output70.mkv', fourcc, fps, (width, height))

frame_id = 0
while True:
    ret, frame = cap.read()
    if not ret:
        break

    if frame_id < drop_start_frame:
        # Giữ nguyên các frame trong 10s đầu
        out.write(frame)
    else:
        # Bắt đầu từ giây thứ 10: bỏ ngẫu nhiên 10% frame
        if random.random() > 0.70:
            out.write(frame)

    frame_id += 1

cap.release()
out.release()
print("✅ Đã giả lập mất gói từ giây thứ 10 và lưu vào 'temp_output70.mkv'")
