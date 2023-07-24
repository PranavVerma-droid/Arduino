
 #include <Servo.h> // servo library  
 Servo s1;  
 void setup()  
 {   
  s1.attach(0);  // servo attach D3 pin of arduino  
 }  
 void loop()   
 {  
  
   s1.write(180);  
   delay(1000);
   s1.write(0);  
   delay(1000);  
   
 }  
