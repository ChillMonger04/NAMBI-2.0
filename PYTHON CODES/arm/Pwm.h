#ifndef _ROS_arm_Pwm_h
#define _ROS_arm_Pwm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm
{

  class Pwm : public ros::Msg
  {
    public:
      typedef int16_t _base_type;
      _base_type base;
      typedef int16_t _shoulder_angle_type;
      _shoulder_angle_type shoulder_angle;
      typedef int16_t _elbow_angle_type;
      _elbow_angle_type elbow_angle;
      typedef int16_t _roll_type;
      _roll_type roll;
      typedef int16_t _pitch_type;
      _pitch_type pitch;
      typedef int16_t _yaw_type;
      _yaw_type yaw;
      typedef int16_t _gripper_type;
      _gripper_type gripper;

    Pwm():
      base(0),
      shoulder_angle(0),
      elbow_angle(0),
      roll(0),
      pitch(0),
      yaw(0),
      gripper(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_base;
      u_base.real = this->base;
      *(outbuffer + offset + 0) = (u_base.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_base.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->base);
      union {
        int16_t real;
        uint16_t base;
      } u_shoulder_angle;
      u_shoulder_angle.real = this->shoulder_angle;
      *(outbuffer + offset + 0) = (u_shoulder_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_shoulder_angle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->shoulder_angle);
      union {
        int16_t real;
        uint16_t base;
      } u_elbow_angle;
      u_elbow_angle.real = this->elbow_angle;
      *(outbuffer + offset + 0) = (u_elbow_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_elbow_angle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->elbow_angle);
      union {
        int16_t real;
        uint16_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_gripper;
      u_gripper.real = this->gripper;
      *(outbuffer + offset + 0) = (u_gripper.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gripper);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_base;
      u_base.base = 0;
      u_base.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_base.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->base = u_base.real;
      offset += sizeof(this->base);
      union {
        int16_t real;
        uint16_t base;
      } u_shoulder_angle;
      u_shoulder_angle.base = 0;
      u_shoulder_angle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_shoulder_angle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->shoulder_angle = u_shoulder_angle.real;
      offset += sizeof(this->shoulder_angle);
      union {
        int16_t real;
        uint16_t base;
      } u_elbow_angle;
      u_elbow_angle.base = 0;
      u_elbow_angle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_elbow_angle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->elbow_angle = u_elbow_angle.real;
      offset += sizeof(this->elbow_angle);
      union {
        int16_t real;
        uint16_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_gripper;
      u_gripper.base = 0;
      u_gripper.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gripper = u_gripper.real;
      offset += sizeof(this->gripper);
     return offset;
    }

    const char * getType(){ return "arm/Pwm"; };
    const char * getMD5(){ return "a5e9098981f1b9f9b76fd4d969af7669"; };

  };

}
#endif
