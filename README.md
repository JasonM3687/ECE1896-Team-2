ECE 1896 (Senior Design)

ML Inference Device for Handwritten Digits 

Project Description:  A device that  records an image of a handwritten number,  inferences  the number using  ML trained by MNIST database, and visualizes the result on a 7-segment LED display.  

Project Specifications: 

 The hardware includes an image sensor, a microprocessor, a micro-SD card, and  a 7-segment LED display.  
 The device reshapes a taken image to a format matched with a MNIST image. As  the initial step, the image includes only one black handwritten number with white  background.  As  an  optional  specification,  the  device  extracts  multiple  output  images from a single input image with multiple numbers with background noise.   
 A  neural  network  is  trained  with  a  training  set  of  60,000  examples  of  MNIST  database in a software (e.g., python). The trained neural network is evaluated by  a test set of 10,000 examples of MNIST database. The inference accuracy should  be higher than 95% for the test set. Note that the neural network should be fit to  the designed hardware.   
 The  hardware  is  programed  to  compute  the  neural  network.  The  inference  accuracy should be higher than 90% for the test set. As an optional specification,  the neural network is trained in the developed hardware.   
 The hardware takes a picture of a handwritten digit and  classify it among 0  – 9.  For  10  reasonable  handwritten  digits,  it  inferences  at  least  8  correct  results.  If  necessary, a neural network should be revised.   
 In  a  real-time  demo  system,  a  user  writes  a  number  and  clicks  a  button  on  a  computer monitor, and then the monitor shows a programmed neural network and  images of all the layers including reshaped input images, probability of all the digit  candidates,  and  an  inference  result.  Also,  display  the  inference  result  on  the  7- segment LED display on the designed hardware. All the results should come from  the developed hardware instead of running the neural network in a computer.


PCB Board Parameters
2.25 inches x 3.635 inches
