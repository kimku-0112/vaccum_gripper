#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "ros/ros.h"
#include "std_msgs/Int32.h"

#ifndef SBC_GPIO_H
#define SBC_GPIO_H

#define C_GPIO_PHY_BASE 0xFD6A0000	

static unsigned int *C_GPIO_MEM_ADDR = NULL;

#define GP_PIN2_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+8*4)   //FD6A0740
#define GP_PIN3_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+9*4)   //FD6A0750
#define GP_PIN4_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+10*4)  //FD6A0760
#define GP_PIN5_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+11*4)  //FD6A0770

#define GP_PIN6_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+0*4)   //FD6A06C0
#define GP_PIN7_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+1*4)   //FD6A06D0
#define GP_PIN8_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+2*4)   //FD6A06E0
#define GP_PIN9_ADDR   (unsigned int *)((C_GPIO_MEM_ADDR)==NULL ?(C_GPIO_MEM_ADDR) : (C_GPIO_MEM_ADDR)+3*4)   //FD6A06F0

#define OFF false
#define ON  true

enum suctionblow{
    off = 0,
    suction,
    blow
};

//ros
ros::Subscriber suction_blow;
ros::Publisher suction_blow_data;
ros::Publisher suction_blow_ok;
void suctionblowCallback(const std_msgs::Int32::ConstPtr& msg);

int curSuctionBlow = 0;

void Init_Gpio(void);
void set_lvl(int suctionblow,int level);
int setSuctionBlow(int suctionblow);
#endif