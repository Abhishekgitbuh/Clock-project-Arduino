# Clock-project-Arduino
This clock project is a beginner level project based on seven-segment Leds and 74HC595 IC. 
![tinkercad_cicuit diagram](https://user-images.githubusercontent.com/111372019/200158512-95cf5b98-1e00-4489-ac23-b1792b8b44d8.JPG)
                            
                            Circuit diagram on Autodesk Tinkercad
                            
 Pin Description:
 
 Four seven segment LEDs(Common Anode) with all pins connected to each other (Except Common Anode pin)
 
 Arduino Uno: 
              Pin 12 is connected to SER    pin(14) of 74HC595;
              
              Pin 11 is connected to RCLK   pin(12) of 74HC595;
              
              Pin 10 is connected to SRCLK  pin(11) of 74HC595;
              
              Pin 9  is connected to common anode pin of leftmost   seven segment;
              
              Pin 8  is connected to common anode pin of 2nd        seven segment;
              
              Pin 7  is connected to common anode pin of 3rd        seven segment;
              
              Pin 6  is connected to common anode pin of righttmost seven segment;
          
 74HC595:
              pin 15 is connected to LED A of seven segment ;
              
              pin 1  is connected to LED B of seven segment ; 
              
              pin 2  is connected to LED C of seven segment ;
              
              pin 3  is connected to LED D of seven segment ;
              
              pin 4  is connected to LED E of seven segment ;
              
              pin 5  is connected to LED F of seven segment ;
              
              pin 6  is connected to LED G of seven segment ;
              
              pin 7  is connected to LED H of seven segment ;
