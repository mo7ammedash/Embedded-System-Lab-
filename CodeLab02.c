#include <LPC11xx.h>
//PORT0
#define GPIO0DIR (*((volatile unsigned long *)0x50008000))
#define GPIO0DATA (*((volatile unsigned long *)0x50003ffc))

//PORT1
#define GPIO1DIR (*((volatile unsigned long *)0x50018000))
#define GPIO1DATA (*((volatile unsigned long *)0x50013ffc))

//PORT2
#define GPIO2DIR (*((volatile unsigned long *)0x50028000))
#define GPIO2DATA (*((volatile unsigned long *)0x50023ffc))

int main (void){ 

   GPIO0DIR |= 0b11110;
   GPIO1DIR |= 0b1000000;
   GPIO2DIR |= 0b1111111;
   
   GPIO1DATA = 0b0000000;
   int seven_seg_encoder [] = {
				 0b1000000,
				 0b1111001,
				 0b0100100,
				 0b0110000,
				 0b0011001,
				 0b0010010,
				 0b0000010,
				 0b1111000,
				 0b0000000,
				 0b0010000
			      };
   int count = 555;
   int i = 0;
   
   while (1){
	 //segm4
         GPIO0DATA = 0b10000;
	 GPIO2DATA = seven_seg_encoder [count%10];
	 for(i = 0; i < 500; i++);
	 
	 //segm3
	 GPIO0DATA = 0b01000;
	 GPIO2DATA = seven_seg_encoder [(count/10)%10];
	 for(i = 0; i < 500; i++);
	 
	 //segm2
	 GPIO0DATA = 0b00100;
	 GPIO2DATA = seven_seg_encoder [(count/100)%10];
	 for(i = 0; i < 500; i++);
	 
	 count--; 
	 if(count == 0){
	    break;
	 }
	
   }
   
   GPIO0DATA = 0b11100;
   GPIO1DATA = 0b1000000;
   GPIO2DATA = seven_seg_encoder [count];

   return 0;
}   
