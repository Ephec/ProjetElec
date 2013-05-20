#include <main.h>
#include <string.h>
#include <stdlib.h>
int1 flag = 1;

#define START 0x3A
#define END 0x0D
#byte  portb = 0xf81

char trame[8];
int cpt;
char c;
char arg[2];
char fonction[2];
char choix[2];

char test;
char reception;
char truc;

#int_RDA
void  RDA_isr(void){

   truc=getc();
}


void lectureTrame(){

    

}

void johnson(){

   Output_D(0b10000000);
   delay_ms(500);
   Output_D(0b11000000);
   delay_ms(500);
   Output_D(0b01100000);
   delay_ms(500);
   Output_D(0b00100000);
   delay_ms(500);
   
   

}

void compteur(){

   Output_A(0b00000000);

   Output_A(0b00000010);
   delay_ms(500);
   Output_A(0b00000100);
   delay_ms(500);
   Output_A(0b00000110);
   delay_ms(500);
   Output_A(0b00001000);
   delay_ms(500);
   Output_A(0b00001010);
   delay_ms(500);
   Output_A(0b00001100);
   delay_ms(500);
   Output_A(0b00001110);
   delay_ms(500);
   Output_A(0b00100000);
   delay_ms(500);
   Output_A(0b00100010);
   delay_ms(500);


}

void clignotement(){

    Output_D(0b00000000) ; // O
    delay_ms(1000);
    Output_D(0b11100000) ; // 1
    delay_ms(1000);

}

void chenillard(){

   output_D(0b10000000);
   delay_ms(1000);
   output_D(0b01000000);
   delay_ms(1000);
   output_D(0b00100000);
   delay_ms(1000);

}
void afficheur(int valeur){
Set_tris_A(0b00011110);

if(valeur<10 && valeur >=0)
{
  output_high(PIN_A1);
  valeur = valeur << 1;
  while(flag){
  output_A(valeur);
  }
}
}

void conversion(int1 trame[8], int8 nb)
{
int i;
for (i = 0; i<=7 ;i++){
   trame[i] = nb % 2;
   nb = nb >> 1;
}

}

int convertcharInt( char arg[2]){

return (atoi(arg[0])*10)+atoi(arg[1]);

}
void obtenirTrame (int1 trame[8]){
}





int1 lrc8(int1 trame[8],int1 parite )// dans ce cas si je ne vais m'occupé que d'un parité paire return 1 si trame OK
{
int i;
int cpt1 = 0; // On va compter le nomvre de 1
for (i=0;i<=7;i++)
   if (trame[i]) cpt1++; // Si c'est un 1 on l'incrémente
if (cpt1%2 == parite) // si divisible par 2 alors ca donnera 0 et le bit de parite doit etre egale a 0 sinon si il n'est pas divisible ca va donner un 1 et da parite doit etre egame a 1
   return 1;
return 0;
}
int1 CreationLRC8(int1 trame[8]) // renvoyer la valeur du bit de parité
{
int i;
int cpt1 = 0; // On va compter le nomvre de 1
for (i=0;i<=7;i++)
   if (trame[i]) cpt1++; // Si c'est un 1 on l'incrémente
return cpt1%2;

}


void main()
{


   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   setup_low_volt_detect(FALSE);


    //Setup_Oscillator parameter not selected from Intr Oscillotar Config tab
    //intitSerie(31);

   set_tris_a(0b00101111);
   set_tris_c(0b11111101);
   Set_tris_D(0b11100000); // port D : Led
   
   lectureTrame();
   
   while(true){
   
         if(truc=='c'){
         clignotement();
         }
         if(truc=='j'){
         johnson();
         }
         if(truc=='t'){
         compteur();
         }
         if(truc=='h'){
         chenillard();
         }
      
   }
}

