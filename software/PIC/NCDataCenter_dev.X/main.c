/* 
 * File:   main.c
 * Author: Ryuya Hirayama
 *
 * Created on 2019/07/20, 10:22
 */

#include <xc.h>
#include "usb.h"
/*
 * 
 */
int main(int argc, char** argv) {
    unsigned int i = 1;
    TRISA = 0;
    
    while(1) {
        PORTA = i;
        i = i == 0;
        __delay_ms(1000);
    }
    
  
    
    return (EXIT_SUCCESS);
}

