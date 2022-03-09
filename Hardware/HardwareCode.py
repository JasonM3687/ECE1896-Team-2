from picamera import PiCamera
from time import sleep
import RPi.GPIO as GPIO
import sys
sys.path.append('../')
import rgb1602
import os
import serial

lcd=rgb1602.RGB1602(16,2)

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(40, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(38, GPIO.OUT)

camera = PiCamera()
camera.rotation = 0

i=1
camera.start_preview()
lcd.setRGB(0,0,0)

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()

while i < 10:
    if os.path.exists('/home/pi/Desktop/Pictures/image%s.jpg' % i):
        os.remove('/home/pi/Desktop/Pictures/image%s.jpg' % i)
    else:
        break
    i += 1

while True:
    if GPIO.input(40) == GPIO.HIGH:
        lcd.setRGB(0,0,255)
        print("Taking Picture")
        lcd.printout("Picture Taken   ")
        GPIO.output(38, GPIO.HIGH)
        camera.capture('/home/pi/Desktop/Pictures/image%s.jpg' % i)
        if os.path.exists('/home/pi/Desktop/Pictures/image%s.jpg' % i):
            ser.write(str(7).encode('utf-8'))
        else:
            break;
        
        sleep(1)

    else:
        GPIO.output(38, GPIO.LOW)
        lcd.clear()
        lcd.setRGB(0,0,0)

        i += 1
camera.stop_preview()
