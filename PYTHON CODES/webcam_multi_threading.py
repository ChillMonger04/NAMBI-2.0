import cv2
import threading

# Function for capturing video from webcam 1
def webcam1():
    cap1 = cv2.VideoCapture(0)
    while True:
        ret, frame1 = cap1.read()
        cv2.imshow("Webcam 1", frame1)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cap1.release()
    cv2.destroyAllWindows()

# Function for capturing video from webcam 2
def webcam2():
    cap2 = cv2.VideoCapture(2)
    while True:
        ret, frame2 = cap2.read()
        cv2.imshow("Webcam 2", frame2)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    cap2.release()
    cv2.destroyAllWindows()

# Create and start thread for webcam 1
thread1 = threading.Thread(target=webcam1)
thread1.start()

# Create and start thread for webcam 2
thread2 = threading.Thread(target=webcam2)
thread2.start()
