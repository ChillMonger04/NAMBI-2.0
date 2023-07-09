#ifndef _ROS_arm_Joint_ang_h
#define _ROS_arm_Joint_ang_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm
{

  class Joint_ang : public ros::Msg
  {
    public:
      typedef float _b_l0_type;
      _b_l0_type b_l0;
      typedef float _l0_l1_type;
      _l0_l1_type l0_l1;
      typedef float _base_type;
      _base_type base;

    Joint_ang():
      b_l0(0),
      l0_l1(0),
      base(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_b_l0;
      u_b_l0.real = this->b_l0;
      *(outbuffer + offset + 0) = (u_b_l0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b_l0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_b_l0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_b_l0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b_l0);
      union {
        float real;
        uint32_t base;
      } u_l0_l1;
      u_l0_l1.real = this->l0_l1;
      *(outbuffer + offset + 0) = (u_l0_l1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l0_l1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l0_l1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l0_l1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->l0_l1);
      union {
        float real;
        uint32_t base;
      } u_base;
      u_base.real = this->base;
      *(outbuffer + offset + 0) = (u_base.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_base.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_base.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_base.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->base);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_b_l0;
      u_b_l0.base = 0;
      u_b_l0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b_l0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b_l0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b_l0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b_l0 = u_b_l0.real;
      offset += sizeof(this->b_l0);
      union {
        float real;
        uint32_t base;
      } u_l0_l1;
      u_l0_l1.base = 0;
      u_l0_l1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l0_l1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l0_l1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l0_l1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->l0_l1 = u_l0_l1.real;
      offset += sizeof(this->l0_l1);
      union {
        float real;
        uint32_t base;
      } u_base;
      u_base.base = 0;
      u_base.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_base.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_base.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_base.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->base = u_base.real;
      offset += sizeof(this->base);
     return offset;
    }

    const char * getType(){ return "arm/Joint_ang"; };
    const char * getMD5(){ return "a13a82a9c5424f4ec461c9023e8f4421"; };

  };

}
#endif
