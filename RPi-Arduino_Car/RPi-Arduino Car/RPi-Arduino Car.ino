#include <AFMotor.h>
#include <Servo.h>

//Dc motor on m1
AF_DCMotor motor1(1);
//Dc motor on m2
AF_DCMotor motor2(2);
//Dc motor on m3
AF_DCMotor motor3(3);
//Dc motor on m4
AF_DCMotor motor4(4);


int order_received=0;
int action;
boolean stop_loop= false;
int motor_speed=220;

void setup() 
{
  
 Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
 Serial.write(order_received);

  
  //Initialize Speed
  motor1.setSpeed(0); 
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
} 

//Move Fowrard
  void move_for()
  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
   
  motor1.setSpeed(motor_speed);
  motor2.setSpeed(motor_speed);
  motor3.setSpeed(motor_speed);
  motor4.setSpeed(motor_speed);
  }

//Turn Left  
  void turn_left()
  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
   
  motor1.setSpeed(motor_speed);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(motor_speed);
  }
//Turn Right  
  void turn_right()
  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
   
  motor1.setSpeed(0);
  motor2.setSpeed(motor_speed);
  motor3.setSpeed(motor_speed);
  motor4.setSpeed(0);
  }
//Stop The Car
  void stop_motors()
  {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
   
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  }
//Move Backwards
  void move_backward()
  {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
   
  motor1.setSpeed(motor_speed);
  motor2.setSpeed(motor_speed);
  motor3.setSpeed(motor_speed);
  motor4.setSpeed(motor_speed);
  }
  



  
void recieve(){
  if(Serial.available() > 0)
  
  order_received=Serial.read();
}

void loop() {
  
// Read the order sent by the computer  
recieve();

      //If serial read = 'W', goes forward.
      if(order_received =='W')
      {
        move_for();
      }
      //If serial read = 'A', turn left
      else if (order_received == 'A')
      {
        turn_left();
      }
      //If serial read = 'D', turn right.
      else if (order_received == 'D')
      {
        turn_right();
      }  
      //If serial read = 'D', goes backwards.
      else if (order_received == 'S')
      {
        move_backward();
      }
      //If serial read = 'S', stop the car.  
      else if (order_received == 'Q')
      {
        stop_motors();
      }     

//  
//  if(Serial.available() <= 0)
//  {
//  while(1){ 
//  stop_motors();
//    } 
  }
//}
