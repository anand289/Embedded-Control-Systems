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

/* Change section number to match the section (1-3) being tested */
#define SECTION 1

#if SECTION == 1



/******************************************************************************
 * Function:    section1
 * Description: read and write to the GPIO registers using your header file
 ******************************************************************************/
void section1(){
  /* code for section 1 */

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

  /* LPUART functions for sending and receiving serial data */
  LPUART1_init();
  LPUART1_transmit_string("\n\rSerial Output Enable...........");
  while(1) {
    old_byte_in = byte_in;
    byte_in = LPUART1_receive_char(); // returns ASCII representation


  }
}
#endif

int main(){
  /* Always call initEECS461() before doing anything else */

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
