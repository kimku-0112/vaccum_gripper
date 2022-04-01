#include "suction_blow.h"

using namespace std;

int main(int argc, char **argv){ 
  int fd;
  unsigned int *add1;

  if (0 != iopl(3)){ printf("gpio must run in root mode.\n"); return 0;}
  
  fd = open("/dev/mem",O_RDWR|O_SYNC);
  
  if(fd<0){ printf("cannot open /dev/mem \n"); return 0;}
  
  add1 = (unsigned int *)mmap(NULL,0x1000 & ~(sysconf(_SC_PAGE_SIZE) - 1), PROT_READ|PROT_WRITE,MAP_SHARED, fd, C_GPIO_PHY_BASE);
  
  if(MAP_FAILED==add1){ perror("mmap faild:"); return 0;}
  
  C_GPIO_MEM_ADDR = add1+0x1B0;		//6c0/4
  
  Init_Gpio();
  
  system("clear");
  
  cout << "vacuum grriper mode :: off\n";

  setSuctionBlow(0);
 
  return 1;
}



//set all Pins as GPIO function
//set OUT GPIO as GPO fucntion
//set IN GPIO as GPI function
//set OUT GPO output low level
//bit[10]  0-- GPIO Mode
//bit[9:8] 10--output mode   01--input mode
//bit[1]   read gpio input level when gpio in input mode
//bit[0]   output level when gpio in output mode

void Init_Gpio(void)
{
//set all GP pin as gpio output, and output low as defult
  unsigned int val;
  val=0x44000201;
  *(GP_PIN2_ADDR) = val;    
  *(GP_PIN3_ADDR) = val;
  val=0x44000100;
  *(GP_PIN4_ADDR) = val; 
  *(GP_PIN5_ADDR) = val; 
  *(GP_PIN6_ADDR) = val; 
  *(GP_PIN7_ADDR) = val; 
  *(GP_PIN8_ADDR) = val; 
  *(GP_PIN9_ADDR) = val;
}

int setSuctionBlow(int suctionblow){
  switch(suctionblow){
    case off: 
      set_lvl(suction,OFF);
      set_lvl(blow,OFF);
    break;
    case suction: 
      set_lvl(suction,ON);
      set_lvl(blow,OFF);
    break;
    case blow:
      set_lvl(suction,OFF);
      set_lvl(blow,ON);
    break;
    default: return -1;
  }
  return suctionblow;
}

void set_lvl(int suctionblow,int level)
{
	unsigned int val;
	 unsigned int * addr;
  	  
	switch(suctionblow){
    case suction: addr = GP_PIN2_ADDR; break;  
    case blow:    addr = GP_PIN3_ADDR; break;
    default: return; 
  }     
  val = *(addr);
  val &= ~(0x1);
  if(!level)val |= 0x1;
  *(addr) = val;
}
