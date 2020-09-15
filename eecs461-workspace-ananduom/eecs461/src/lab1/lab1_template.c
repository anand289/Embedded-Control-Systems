/*
  EECS461
  Lab 1
  Read Chapter 11&12 in S32K144 User's Manual
  Updated: March 17th, 2014 by Scott Kenyon
           14 Jun 2014 by GPCz
           19 Jun 2014 by GPCz
           2017-03 RMC
           2018-03 Paul Domanico
           15 Nov 2018 jfr
*/

#include "eecs461.h"
#include <stdint.h>
#include <myheaderfile_eecs461.h>

/* Change section number to match the section (1-3) being tested */
#define SECTION 1

#if SECTION == 1



/******************************************************************************
 * Function:    section1
 * Description: read and write to the GPIO registers using your header file
 ******************************************************************************/
void section1(){
  /* code for section 1 */

  volatile uint32_t * const portD_PCR = (uint32_t *)(BASE_PORTD);
  volatile uint32_t * const portE_PCR = (uint32_t *)(BASE_PORTE);
  GPIO_mem * const gpioD = (GPIO_mem *)(BASE_GPIO + GPIOD_OFFSET);
  GPIO_mem * const gpioE = (GPIO_mem *)(BASE_GPIO + GPIOE_OFFSET);


  uint16_t sum, value1, value2;
  uint32_t regReadVal;
  int index;

  /* Configure the LED pins */
  for(index = 0; index < 16; index++){
   /* Configure pin mux to gpio */
   portD_PCR[index] = 0b001 << 8;
   /* Set the direction to output */
   gpioD->PDDR |= 0b1 << index;
  }

  /* Configure the DIP pins */
  for(index = 6; index < 14; index++){
   /* Configure pin mux to gpio */
   portE_PCR[index] = 0b001 << 8;
   /* Set the direction to input */
   gpioE->PDDR &= ~(1 << index);
  }

  /* The functionality code will go here, it has been commented out*/
   while(1)
   {
    value1 = 0;
    value2 = 0;
    sum = 0;
    /* Read the GPIOE input register, extract the two 4 bit numbers
    set on dipswitches 1-4 and 5-8 */

    regReadVal = ((gpioE->PDIR)&0b1111000000)>>6;
    value1 = regReadVal;

    regReadVal = ((gpioE->PDIR)&0b11110000000000)>>10;
    value2 = regReadVal;
    sum = value1 + value2;




    /* Calculate the sum and write to the GPIOD output register
    to display the results on LEDs1-5. */
    gpioD->PDOR = sum;
   }




}


#elif SECTION == 2
#include "S32K144.h"
#include "gpio.h"
/******************************************************************************
 * Function:    section2
 * Description: Use the provided S32K144.h header file
 ******************************************************************************/
void section2(){
  /* code for section 2 */

  uint16_t sum, value1, value2;
  uint8_t baseE, baseD;
  int i;

  baseE = 4;
  baseD = 3;
/*Configure MUX and Direction */
  for(i=6;i<14;i++){
    initGPDI(baseE,i);
  }

  for(i=0;i<16;i++){
    initGPDO(baseD,i);
  }

  while(1){
    value1 = 0;
    value2 = 0;
    sum = 0;

    value1 = (readGPIO(baseE,9)<<3) + (readGPIO(baseE,8)<<2) + (readGPIO(baseE,7)<<1) + (readGPIO(baseE,6)<<0);
    value2 = (readGPIO(baseE,13)<<3) + (readGPIO(baseE,12)<<2) + (readGPIO(baseE,11)<<1) + (readGPIO(baseE,10)<<0);

    sum = value1 + value2;

    writeGPIO(baseD,0,(sum)&0b1);
    writeGPIO(baseD,1,(sum>>1)&0b1);
    writeGPIO(baseD,2,(sum>>2)&0b1);
    writeGPIO(baseD,3,(sum>>3)&0b1);
    writeGPIO(baseD,4,(sum>>4)&0b1);

  }

}


#elif SECTION == 3
#include "LPUART.h"
#include "gpio.h"
/******************************************************************************
 * Function:    section3
 * Description: Communicate with the computer using the keyboard interface
 ******************************************************************************/
void section3(){
  /* code for section 3 */
  char byte_in, old_byte_in;
  int sum, i ;
  uint8_t baseE, baseD;

  baseE = 4;
  baseD = 3;

  for(i=6;i<14;i++){
    initGPDI(baseE,i);
  }

  for(i=0;i<16;i++){
    initGPDO(baseD,i);
  }

  /* LPUART functions for sending and receiving serial data */
  LPUART1_init();
  LPUART1_transmit_string("\n\rSerial Output Enable...........");
  while(1) {
    old_byte_in = byte_in;
    byte_in = LPUART1_receive_char(); // returns ASCII representation

    sum = (old_byte_in - 48) + (byte_in - 48);

    writeGPIO(baseD,0,(sum)&0b1);
    writeGPIO(baseD,1,(sum>>1)&0b1);
    writeGPIO(baseD,2,(sum>>2)&0b1);
    writeGPIO(baseD,3,(sum>>3)&0b1);
    writeGPIO(baseD,4,(sum>>4)&0b1);


  }
}
#endif

int main(){
  /* Always call initEECS461() before doing anything else */
  initEECS461();
  #if(SECTION == 1)
  section1();
  #elif(SECTION == 2)
  section2();
  #elif(SECTION == 3)
  section3();
  #endif

  /* Should never reach this point */
  return 0;
}
