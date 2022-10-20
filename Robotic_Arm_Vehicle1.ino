#include <Servo.h>

Servo motor_1;
Servo motor_2;
Servo motor_3;
Servo motor_4;
Servo motor_5;

#define enA 5  
#define in1 A3 
#define in2 A2 
#define in3 A1  
#define in4 A0 
#define enB 5  

int servo1 = 90;
int servo2 = 110;
int servo3 = 40;
int servo4 = 50;
int servo5 = 90;

int bt_data;
int Speed = 130;

void setup(){
  
Serial.begin(9600); 
 
motor_1.attach(8);
motor_2.attach(9);
motor_3.attach(10);
motor_4.attach(11);
motor_5.attach(12); 
 
motor_1.write(servo1); 
motor_2.write(servo2); 
motor_3.write(servo3); 
motor_4.write(servo4); 
motor_5.write(servo5); 

pinMode(enA, OUTPUT);  
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);

delay(1000);
}

void loop(){


if(Serial.available() > 0){     
bt_data = Serial.read(); 
Serial.println(bt_data);
if(bt_data > 20){Speed = bt_data;}      
}

analogWrite(enA, Speed); 
analogWrite(enB, Speed); 


     if(bt_data == 1){forword(); }  
else if(bt_data == 2){backword();}  
else if(bt_data == 3){turnLeft();}  
else if(bt_data == 4){turnRight();} 
else if(bt_data == 5){Stop(); }     

else if(bt_data == 6){turnLeft();  delay(400);  bt_data = 5;}
else if(bt_data == 7){turnRight(); delay(400);  bt_data = 5;}   

else if (bt_data == 8){
if(servo1<180){servo1 = servo1+1;}
motor_1.write(servo1);  
}
else if (bt_data == 9){
if(servo1>0){servo1 = servo1-1;} 
motor_1.write(servo1);  
}

else if (bt_data == 10){
if(servo2>0){servo2 = servo2-1;}
motor_2.write(servo2);
}
else if (bt_data == 11){
if(servo2<180){servo2 = servo2+1;}
motor_2.write(servo2);  
}

else if(bt_data == 12){
if(servo3>0){servo3 = servo3-1;}
motor_3.write(servo3);
}
else if (bt_data == 13){
if(servo3<180){servo3 = servo3+1;}
motor_3.write(servo3);
}

else if (bt_data == 14){
if(servo4<180){servo4 = servo4+1;}
motor_4.write(servo4);
}
else if(bt_data == 15){
if(servo4>0){servo4 = servo4-1;}
motor_4.write(servo4);
}

else if (bt_data == 16){
if(servo5>90){servo5 = servo5-1;}
motor_5.write(servo5);
}
else if (bt_data == 17){
if(servo5<150){servo5 = servo5+1;}
motor_5.write(servo5);
}

delay(30);
}


void forword(){ 
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW);   
digitalWrite(in4, HIGH); 
}

void backword(){ //backword
digitalWrite(in1, LOW);  
digitalWrite(in2, HIGH); 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW); 
}

void turnRight(){ //turnRight
digitalWrite(in1, LOW);  
digitalWrite(in2, HIGH); 
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH); 
}

void turnLeft(){ //turnLeft
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW); 
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);
}

void Stop(){ //stop
digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);  
digitalWrite(in3, LOW); 
digitalWrite(in4, LOW); 
}
