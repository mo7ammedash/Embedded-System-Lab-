#define GPIO2DIR (*((volatile unsigned long *)0x50028000))
#define GPIO2DATA (*((volatile unsigned long *)0x50023FFC))


int main (void){ 

   GPIO2DIR |= 0b111100;
   GPIO2DATA = 0b000000;
   
   while (1){
      if(GPIO2DATA & 0b1){
	 GPIO2DATA = 0b111100;
      }
      if(GPIO2DATA & 0b10){
	 GPIO2DATA = 0b000000;  
      }
   }
   return 0;
}   



