#Jason Matuszak
#ECE 1896 - Senior Design Midterm Checkoff
#Team 2

import os
import cv2
import time
import random
import numpy as np
import PIL.Image as pil
from mnist import MNIST
from os.path import expanduser
from PIL import Image, ImageOps

def find_digits(image):
    # Image saving directory
    saving_path = 'C:/Users/Jason Matuszak/Desktop/Cropped_Digits'

    # Resizing image for better thresholding results
    image = cv2.resize(image,(500,500))
    
    # Create input image copy
    imageCopy = image.copy()

    # Grayscale the input image
    grayscaleImage = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Obtain binary image through adaptive thresholding
    binaryImage = cv2.adaptiveThreshold(grayscaleImage, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 31, -1)
    
    # DIGITS CANNOT BE TOO CLOSE TOGETHER
    # Get the indices/labels of the remaining components based on the area stat
    componentsNumber, labeledImage, componentStats, componentCentroids = \
    cv2.connectedComponentsWithStats(binaryImage, connectivity=4)
    remainingComponentLabels = [i for i in range(1, componentsNumber) if componentStats[i][4] >= 2200] #1000 / 2200 best

    # Filter the labeled pixels based on the remaining labels,
    # assign pixel intensity to 255 (uint8) for the remaining pixels
    filteredImage = np.where(np.isin(labeledImage, remainingComponentLabels) == True, 255, 0).astype('uint8')
    
    # Get the structuring element:
    maxKernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3,3)) # Originally 3x3 

    # Perform closing:
    closingImage = cv2.morphologyEx(filteredImage, cv2.MORPH_CLOSE, maxKernel, None, None, 1, cv2.BORDER_REFLECT101)
    
    contours, hierarchy = cv2.findContours(closingImage, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)
    contours_poly = [None] * len(contours)
    #cv2.imshow('Closing Image',closingImage)
    # Bounding boxes
    boundRect = []
    # Search for outer bounding boxes
    for i, c in enumerate(contours):

        if hierarchy[0][i][3] == -1:
            contours_poly[i] = cv2.approxPolyDP(c, 3, True)
            boundRect.append(cv2.boundingRect(contours_poly[i]))

    # Draw the bounding boxes on input image copy:
    for i in range(len(boundRect)):
        # Red bounding box
        color = (0, 0, 255)
        cv2.rectangle(imageCopy, (int(boundRect[i][0]), int(boundRect[i][1])), (int(boundRect[i][0] + boundRect[i][2]), int(boundRect[i][1] + boundRect[i][3])), color, 2)
    cv2.imshow('Bounding Boxed Digits',imageCopy)
    # Crop the digits:
    for i in range(len(boundRect)):
    # Get the roi for each bounding rectangle:
        x, y, w, h = boundRect[i]

    # Crop the current digit:
        croppedImg = closingImage[y:y + h, x:x + w]
        #cv2.imshow("Processed Digit: " + str(i), croppedImg)
        # Shrink image to mnist size
        image_mnist = cv2.resize(croppedImg,(28,28))
        cv2.imwrite(os.path.join(saving_path , 'Hand_Written_Digit_' + str(i+1) + '.jpg'), image_mnist)
        # Convert discovered cropped/resized digit to array
        oneD_array = image_mnist.ravel()
        print(oneD_array)
        #cv2.waitKey(0)
        
if __name__ == '__main__':
    #image = cv2.imread('C:/Users/Jason Matuszak/Desktop/test pics/esp32_cam_pic.jpg')
    #image = cv2.imread('C:/Users/Jason Matuszak/Desktop/test pics/test.jpg')
    #image = cv2.imread('C:/Users/Jason Matuszak/Desktop/test pics/test2.jpg')
    #image = cv2.imread('C:/Users/Jason Matuszak/Desktop/test pics/image3.jpg')
    image = cv2.imread('C:/Users/Jason Matuszak/Desktop/test pics/test3.jpg')
    #image = cv2.imread('C:/Users/Jason Matuszak/Desktop/test pics/test4.jpg')
    find_digits(image)
