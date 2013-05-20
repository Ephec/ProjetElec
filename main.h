#include <18F458.h>
#device adc=16

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES WDT128                	//Watch Dog Timer uses 1:128 Postscale
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(clock=20000000)

#use rs232(baud=2400,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

