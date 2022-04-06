#ECE 1896 - Senior Design 
#Team 2

import os
import cv2
import sys
import math
import time
import random
import rgb1602
import serial
import numpy as np
sys.path.append('../')
import PIL.Image as pil
import RPi.GPIO as GPIO
from array import *
from time import sleep
from picamera import PiCamera
from os.path import expanduser
from PIL import Image, ImageOps

################### LCD/Camera Set Up ######################### 
lcd=rgb1602.RGB1602(16,2)

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(40, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(38, GPIO.OUT)

camera = PiCamera()
camera.rotation = 0
lcd.setRGB(0,0,0)
#########################################################

def lcd_digits():
    digits = []
    with open('Inference.txt') as my_file:
        digits = np.loadtxt(my_file, delimiter="\n")
    parsed_digits = str(digits).replace('.','')
    parsed_digits = str(parsed_digits).replace('[','')
    parsed_digits = str(parsed_digits).replace(']','')
    
    lcd.printout(str(parsed_digits))
    
    #for i in range(len(parsed_digits)):
        #ser.write(str(parsed_digits[i]).encode('utf-8'))
        
        
def take_picture_switch():
    x = 0
    while x == 0:
        if GPIO.input(40) == GPIO.HIGH:
            lcd.setRGB(0,0,255)
            print("Taking Picture")
            lcd.printout("Picture Taken   ")
            GPIO.output(38, GPIO.HIGH)
            camera.capture('/home/pi/Desktop/Pi_Pics/image.jpg')
            camera.stop_preview()
            x = 1
            sleep(1)
            lcd.clear()
            sleep(1)

        else:
            GPIO.output(38, GPIO.LOW)
            lcd.clear()
            lcd.setRGB(0,0,0)
    
# Take picture with raspberry pi
def take_picture():
    camera.start_preview()
    #sleep(10)
    camera.capture('/home/pi/Desktop/Pi_Pics/image.jpg')
    camera.stop_preview()
    
    image = cv2.imread('/home/pi/Desktop/Pi_Pics/image.jpg')
    
    return image

def purge_directory(directory):
    # Read the hand written mnist digits directory and count the number of images
    files = 0
    for path in os.listdir(directory):
        # check if current path is a file
        if os.path.isfile(os.path.join(directory, path)):
            files += 1
     # Purge mnist image output directory
    for y in range(files):
        if (y+1 <= files ):
            os.remove(f"{directory}/Hand_Written_Digit_" + str(y+1) + ".jpg")      
    print(str(files) + ' old images removed from mnist image directory')
    
    return None

# Image padding function for use after cropping digits
def pad_image(image, expected_size):
    image.thumbnail((expected_size[0], expected_size[1]))
    
    width = expected_size[0] - image.size[0]
    height = expected_size[1] - image.size[1]
    
    pad_width = width // 2
    pad_height = height // 2
    
    padding = (pad_width, pad_height, width - pad_width, height - pad_height)
    
    return ImageOps.expand(image, padding)

def loopit(x):
    arr = np.zeros(len(x))
    
    for i in range(len(arr)):
        if(x[i] >= 0):
            arr[i] = x[i]
        else:
            arr[i] = 0.2 *(math.exp(x[i]) - 1)
            
    return arr

# Machine learning algorithm
def inferencing(number_of_digits):
    numArray = np.zeros(number_of_digits+1);
    percentArray = np.zeros((number_of_digits+1)*10);
    
    for k in range(number_of_digits + 1):
        img = Image.open("/home/pi/Desktop/Cropped_Digits/Hand_Written_Digit_" + str(k+1) + ".jpg")
        
        #img2 = img.read().split('\t')
        array_image = np.asarray(img)
        array_image = cv2.blur(array_image, (3,3))
        cv2.imwrite('Blurred_Image.jpg' ,array_image)
            
        arrayimg = array_image.astype(np.float)
        arrayimg = np.array(arrayimg)
        
        
        #change image to 1d array
        pixelArray = arrayimg.flatten()
        
        #image pixels to percents
        pixelArray = np.true_divide(pixelArray, 255.0);
        
        #reading matrix files for weight and bias
        with open("w2.dat") as file_name:
            w2 = np.loadtxt(file_name, delimiter=",")
            
        print('File done')
        
        with open("w3.dat") as file_name:
            w3 = np.loadtxt(file_name, delimiter=",")
        
        with open("w4.dat") as file_name:
            w4 = np.loadtxt(file_name, delimiter=",")
        
        with open("b2.dat") as file_name:
            b2 = np.loadtxt(file_name, delimiter=",")
        
        with open("b3.dat") as file_name:
            b3 = np.loadtxt(file_name, delimiter=",")
        
        with open("b4.dat") as file_name:
            b4 = np.loadtxt(file_name, delimiter=",")
        
        
        #multiplication and adding bias
        m2 = np.add(np.dot(w2,pixelArray), b2)
        out2 = loopit(m2)
        m3 = np.add(np.dot(w3,out2), b3)
        out3 = loopit(m3)
        m = np.add(np.dot(w4,out3), b4)
        out = loopit(m)
        
        #normalizing values
        normalPercentages = (out-min(out))/(max(out)-min(out))
        percent = np.zeros(len(normalPercentages))
        percent[0] = 0
        
        for i in range(len(normalPercentages)):
            sortedPercent = np.sort(normalPercentages)
            for j in range(1,len(sortedPercent)):
                if (sortedPercent[j] == normalPercentages[i]):
                    percent[i] = normalPercentages[i] - sortedPercent[j-1]
                    percentArray[10*(k) + i] = percent[i]
        
        big = 0
        num = 0
        
        #loop through
        for i in range(0, 10):
            if (out[i] > big):
                num = i - 1
                big = out[i]
        
        numArray[k] = int(num + 1);
            
        print((num + 1))
    open('Percent.txt', 'w').close()
    with open('Percent.txt', 'w') as f:
        for i in range(len(percentArray)):
            f.write(str(round(percentArray[i], 2)))
            f.write('\n')
            
    open('Inference.txt', 'w').close()
    with open('Inference.txt', 'w') as f:
        for i in range(0, len(numArray)):   
            f.write(str(int(numArray[i])))
            f.write('\n')
            
    open('Number_Of_Digits.txt', 'w').close()     
    with open('Number_Of_Digits.txt', 'w') as f:  
        f.write(str(number_of_digits+1))

def find_digits(image):
    # Image saving directories
    saving_path = '/home/pi/Desktop/Cropped_Digits'
    binary_image_path = '/home/pi/Desktop/Binary_Images'
    boxed_digits_path = '/home/pi/Desktop/Boxed_Digits'
    number_of_digits = 0
    
    # Clean up output directory
    purge_directory(saving_path)
    
    # Resizing image for better thresholding results
    image = cv2.resize(image,(500,500))
    
    # Create input image copy
    imageCopy = image.copy()

    # Grayscale the input image
    grayscaleImage = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Obtain binary image through adaptive thresholding, values may vary depending on lighting
    ret, binaryImage = cv2.threshold(grayscaleImage,48, 255, cv2.THRESH_BINARY_INV) #48 for real1.jpg
    
    # Save binary image 
    cv2.imwrite(os.path.join(binary_image_path , 'Binary_Image.jpg'), binaryImage)
    
    # Obtain binary image contours
    conts, hier = cv2.findContours(binaryImage.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    digits = [cv2.boundingRect(cont) for cont in conts]
    j = 0
    for j,digit in enumerate(digits):
        # Draw bounding boxes around each digit on the original image and save it
        cv2.rectangle(image, (digits[j][0] , digits[j][1]), (digits[j][0] + digits[j][2], digits[j][1] + digits[j][3]), (0, 255, 0), 3)
        cv2.imwrite(os.path.join(boxed_digits_path ,'Boxed_Digits.jpg'), image)
        for i in range(len(digits)):
            # Get the roi for each bounding rectangle:
            x, y, w, h = digits[i]
            croppedImg = binaryImage[y:y + h, x:x + w]
            # Convert from numpy array to PIL
            image_mnist_pil = Image.fromarray(croppedImg)
            # Pad image with 0s 
            image_mnist_pil = pad_image(image_mnist_pil,(100,300))
             # Resize to mnist format
            image_mnist_pil = image_mnist_pil.resize((28,28))
                        
            width, height = image_mnist_pil.size
            # Filter extra noise out of the cropped images
            for x in range(0,width):
                for y in range(0,height):
                    if image_mnist_pil.getpixel((x,y)) > 1:
                        image_mnist_pil.putpixel((x,y),255)
            # Save final cropped digits
            if (i+1 < 11):
                image_mnist_pil.save(f"{saving_path}/Hand_Written_Digit_" + str(i+1) + ".jpg")
                number_of_digits = i
            
    return number_of_digits
    
        
if __name__ == '__main__':
    # Arduino serial communication set up
    #ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    #ser.reset_input_buffer()
    
    
    #take_picture_switch()
    image = cv2.imread('/home/pi/Desktop/Pi_Pics/image.jpg')
    #image = take_picture()
    digits = find_digits(image)
    inferencing(digits)
    lcd_digits()
