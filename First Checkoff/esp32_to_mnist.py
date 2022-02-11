#Jason Matuszak
#ECE 1896 - Senior Design Checkoff #1
#Team 2

import cv2
import time
import random
import numpy as np
import PIL.Image as pil
from mnist import MNIST
from os.path import expanduser
from PIL import Image, ImageOps

def mnist_resize(image):
    #Sharpening kernel
    kernel = np.array([[0, -1, 0],[-1, 5,-1],[0, -1, 0]])
    
    #Grayscale image
    image_gray = ImageOps.grayscale(image)
    
    #Convert to numpy array
    image_gray_np = np.array(image_gray)
    
    #Resize image to 28x28
    image_shrink = cv2.resize(image_gray_np,(28,28))

    #Sharpen image with defined kernel
    image_sharp = cv2.filter2D(image_shrink, -1, kernel)
    
    #Invert B/W 
    image_invert = cv2.bitwise_not(image_sharp)
    
    #Convert back to PIL for better display
    image_mnist = pil.fromarray(np.uint8(image_invert * 255) , 'L')
    
    return image_mnist    

if __name__ == '__main__':
    #Gathering Mnist image data
    home = expanduser("~")+'/Desktop/image_samples/'
    mnist = MNIST(home)
    
    #Converting random mnist array data to a 28x28 image and displaying
    images, labels = mnist.load_testing()
    #Choosing a random index
    index = random.randrange(0, len(images))
    #Reshaping 28x28 array to a 28x28 image
    testImage = (np.array(images[index], dtype='float')).reshape(28,28)
    #Convert numpy to PIL
    mnist = pil.fromarray(np.uint8(testImage * 255) , 'L')
    
    print("Here is some random 28x28 mnist array data converted into a 28x28 image")
    time.sleep(5)
    mnist.show()
    
    print("\nOriginal esp32-cam picture")
    time.sleep(10)
    
    #Importing original image with PIL and displaying
    image_dir = 'C:/Users/Jason Matuszak/Desktop/test pics/esp32_cam_pic.jpg'
    esp32_cam_image = Image.open(image_dir)
    esp32_cam_image.show()
    time.sleep(5)
    
    #Resizing and displaying image
    esp32_28x28 = mnist_resize(esp32_cam_image)
    print("\nSame image taken from the esp32-cam converted into a similar format")
    time.sleep(10)
    esp32_28x28.show()
    
    
    
    
