#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;

//Connect with pin 18 and 19
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include<ros.h>
#include<geometry_msgs/Vector3.h>
#include<sensor_msgs/Imu.h>
#include <SoftwareSerial.h>
float lati=0.0, longi=0.0;
float g_degree=0.0;
ros::NodeHandle nh;
geometry_msgs::Vector3 data;
sensor_msgs::Imu bata; 

ros::Publisher pos("gps",&data);
ros::Publisher imu("imu",&bata);
//data.x=0;
// Assign a Uniquej ID to the HMC5883 Compass Sensor
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

#include <TinyGPS.h>
float lat,lon;
TinyGPS gps; // create gps object

void setup(){
  
  nh.initNode();
  nh.advertise(pos);
  nh.advertise(imu);
  sensor_t sensor;
  mag.getSensor(&sensor);
  //Serial.begin(57600); // connect serial
  Serial.println("The GPS Received Signal:");
  Serial2.begin(9600); // connect gps sensor
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }

}
 
void loop(){
    while(Serial2.available()){ // check for gps data
      if(true || gps.encode(Serial2.read()))// encode gps data
      { 
        gps.f_get_position(&lat,&lon); // get latitude and longitude
    
        Serial.print("Position: ");
        
        //Latitude
        Serial.print("Latitude: ");
        Serial.print(lat,6);
        lati=lat;        
        Serial.print(",");
        //Longitude
        Serial.print("Longitude: ");
        Serial.println(lon,6);
        longi=lon; 
        IMU.readSensor();
        // display the data
        float ax=0.0, ay=0.0, az=0.0, gx=0.0, gy=0.0, gz=0.0;
        ax=IMU.getAccelX_mss();
        ay=IMU.getAccelY_mss();
        az=IMU.getAccelZ_mss();
        gx=IMU.getGyroX_rads();
        gy=IMU.getGyroY_rads();
        gz=IMU.getGyroZ_rads();
        Serial.print(ax,6);
        Serial.print("\t");
        Serial.print(ay,6);
        Serial.print("\t");
        Serial.print(az,6);
        Serial.print("\t");
        Serial.print(gx,6);
        Serial.print("\t");
        Serial.print(gy,6);
        Serial.print("\t");
        Serial.print(gz,6);
        Serial.print("\t");
        Serial.print(IMU.getMagX_uT(),6);
        Serial.print("\t");
        Serial.print(IMU.getMagY_uT(),6);
        Serial.print("\t");
        Serial.print(IMU.getMagZ_uT(),6);
        Serial.print("\t");
        Serial.println(IMU.getTemperature_C(),6);
        //delay(100);
        if(mag.begin())
        {
          float l_degree=0.0;
          l_degree=displayCompassInfo();
          data.z=l_degree;
          data.x=lati;
          data.y=longi;
          bata.linear_acceleration.x=ax;
          bata.linear_acceleration.y=ay;
          bata.linear_acceleration.z=az;
          bata.angular_velocity.x=gx;
          bata.angular_velocity.y=gy;
          bata.angular_velocity.z=gz;
          g_degree=l_degree;
          pos.publish(&data);
          imu.publish(&bata);
          nh.spinOnce();
          
        }
      
     }
   }
} 
float displayCompassInfo()
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
 
  /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
  Serial.print("X: "); Serial.print(event.magnetic.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.magnetic.z); Serial.print("  ");Serial.println("uT");

  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.05;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
  return headingDegrees;
  
  delay(500);
}
