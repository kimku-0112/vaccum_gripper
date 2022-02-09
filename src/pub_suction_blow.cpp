#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include <signal.h>

enum suctionblow{
    off = 0,
    suction,
    blow
};

void clearInputBuffer(){
    while(getchar() != '\n');
    std::cin.clear();
}


void shutdownHandler(int sig){
  while(getchar() != '\n');
  std::cin.clear();
  ros::shutdown();
}

int main(int argc, char **argv){

  ros::init(argc, argv, "gpio_setoutput");
	
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Int32>("/vacuumGripper/suctionblow", 10);
  ros::Rate loop_rate(10); 
  std::string str;
  int i = 0,gripper = 0;
  char ch;
  
  signal(SIGINT, shutdownHandler);
  while(ros::master::check()){    
    
    std_msgs::Int32 msg;

    std::system("clear");

    printf("\033[1;32mchange vacuum gripper status!!!! \n\n\033[0m");

    if(i)printf("\033[1;31m[%d] is invaild vacuum gripper status. please re-enter the vacuum gripper status(0~2).\n( off : 0 / suction : 1 / blow : / 2)\n\033[0m",gripper);
    else printf("\033[1;32mEnter the vacuum gripper status(0~2)\n( off : 0 / suction : 1 / blow : / 2)\n\033[0m");

    i = 1;

    std::cin>>gripper;
    clearInputBuffer();

    if(gripper < 0 | gripper > 2) continue;

    msg.data = gripper;

    pub.publish(msg);
    switch(gripper){
      case off:     str = "off"; break;
      case suction: str = "suction"; break;
      case blow:    str = "blow"; break;
    }
        
    std::cout << "\033[1;32mchange vacuum gripper status : " << str << "\033[0m\n";
    printf("\033[1;33mre-change vacuum gripper status?(y/n)\033[0m\n");

    ch = getchar();
    clearInputBuffer();
    if (ch == 'y'){
    }
    else{
      printf("\033[1;33m=================exit=================\033[0m\n");
      return 0;
    } 
            
    i = 0;
  }
  
  return 0;
}
