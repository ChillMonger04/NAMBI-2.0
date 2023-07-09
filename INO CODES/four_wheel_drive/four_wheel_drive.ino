#include <ros.h>
#include <std_msgs/UInt16.h>
#include <geometry_msgs/Twist.h>

//header files of the pan tilt

#include <pcl_msgs/Vertices.h>
#include<Servo.h>
Servo panservo1;
Servo tiltservo1;
Servo panservo2;
Servo tiltservo2;


#define DIR1L 10
#define PWM1L 11
#define DIR2L 12
#define PWM2L 13

#define DIR1R 47
#define PWM1R 46
#define DIR2R 45
#define PWM2R 44
//variables of pan tilt

int c ;
int i=0;
int panServopin1 = 4, tiltServopin1 = 5;
int panServopin2 = 6, tiltServopin2 = 7;
float track=0.6;
float VL,VR;

ros::NodeHandle nh;
//ros::NodeHandle nh2;
void Motor1L(float motion);
void Motor1R(float motion);
void Motor2L(float motion);
void Motor2R(float motion);

float speed_angular=0, speed_linear=0;

void messageCb( const geometry_msgs::Twist& msg){
  speed_angular = msg.angular.z;
  speed_linear = msg.linear.x;
  //speed_angular = (speed_angular*track)/(2.0);
  VR=speed_linear + speed_angular;
  VL= speed_linear - speed_angular;
  //Serial.println(VR);
  //Serial.println(VL);

   Motor1L(VL);
   Motor1R(VR);
   Motor2L(VL);
   Motor2R(VR);
}

void pan_msg( const pcl_msgs::Vertices& cmd_msg)
{
  
   int pan_angle = cmd_msg.vertices[0];
   int tilt_angle = cmd_msg.vertices[1];
   //Serial.println(pan_angle);
   //Serial.println(tilt_angle);
   panservo1.write(pan_angle);
   tiltservo1.write(tilt_angle);
   
}
void pan_msg2( const pcl_msgs::Vertices& cmd_msg)
{
  
   int pan_angle = cmd_msg.vertices[0];
   int tilt_angle = cmd_msg.vertices[1];
   //Serial.println(pan_angle);
   //Serial.println(tilt_angle);
   panservo2.write(pan_angle);
   tiltservo2.write(tilt_angle);
   
}
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );
ros::Subscriber<pcl_msgs::Vertices> sub1("servo_pantilt", pan_msg);
ros::Subscriber<pcl_msgs::Vertices> sub2("servo_pantilt1", pan_msg2);

void setup(){
 pinMode(PWM1L, OUTPUT);
 pinMode(PWM1R, OUTPUT);
 pinMode(PWM2L, OUTPUT);
 pinMode(PWM2R, OUTPUT);
 pinMode(DIR1L, OUTPUT);
 pinMode(DIR1R, OUTPUT);
 pinMode(DIR2L, OUTPUT);
 pinMode(DIR2R, OUTPUT);
 digitalWrite(PWM1L, LOW);
 digitalWrite(PWM1R, LOW);
 digitalWrite(PWM2L, LOW);
 digitalWrite(PWM2R, LOW);

 //pinMode(3, OUTPUT);
 nh.initNode();
 //nh2.initNode();
 nh.subscribe(sub);
 nh.subscribe(sub1);
 nh.subscribe(sub2);  
 panservo1.attach(panServopin1);
 tiltservo1.attach(tiltServopin1);
 panservo2.attach(panServopin2);
 tiltservo2.attach(tiltServopin2);
 
}

void loop(){
 //nh2.spinOnce();
 nh.spinOnce();
 delay(1);
}

void Motor1L(float motion){
if(motion>=0){
  analogWrite(PWM1L, motion);
  digitalWrite(DIR1L, HIGH); //clockwise
}else{
  motion=-1*motion;
  analogWrite(PWM1L, motion);
  digitalWrite(DIR1L, LOW); //anti-clockwise
}
}

void Motor1R(float motion){
if(motion>=0){
  analogWrite(PWM1R, motion);
  digitalWrite(DIR1R, HIGH); //clockwise
}else{
  motion=-1*motion;
  analogWrite(PWM1R, motion);
  digitalWrite(DIR1R, LOW); //anti-clockwise
} 
}

void Motor2L(float motion){
if(motion>=0){
  analogWrite(PWM2L, motion);
  digitalWrite(DIR2L, HIGH); //clockwise
}else{
  motion=-1*motion;
  analogWrite(PWM2L, motion);
  digitalWrite(DIR2L, LOW); //anti-clockwise
}
}

void Motor2R(float motion){
if(motion>=0){
  analogWrite(PWM2R, motion);
  digitalWrite(DIR2R, HIGH); //clockwise
}else{
  motion=-1*motion;
  analogWrite(PWM2R, motion);
  digitalWrite(DIR2R, LOW); //anti-clockwise
} 
}
