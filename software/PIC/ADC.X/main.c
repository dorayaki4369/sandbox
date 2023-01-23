/* 
 * File:   main.c
 * Author: doray
 *
 * Created on 2019/03/03, 14:32
 */


// DSPIC33FJ64GP802 Configuration Bit Settings
// 'C' source line config statements

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)
#pragma config RBS = NO_RAM             // Boot Segment RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WRPROTECT_OFF     // Secure Segment Program Write Protect (Secure segment may be written)
#pragma config SSS = NO_FLASH           // Secure Segment Program Flash Code Protection (No Secure Segment)
#pragma config RSS = NO_RAM             // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = LPRCDIVN         // Oscillator Mode (Internal Fast RC (FRC) with divide by N)
#pragma config IESO = ON                // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Source (Primary Oscillator Disabled)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (Watchdog timer always enabled)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)

// FICD
#pragma config ICS = PGD3               // Comm Channel Select (Communicate on PGC3/EMUC3 and PGD3/EMUD3)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

void initializationADC(void) {
    AD1CON1bits.ADON      = 0x0;
    AD1CON1bits.ADSIDL    = 0x1;
    AD1CON1bits.AD12B     = 0x0;
    AD1CON1bits.FORM      = 0x3;
    AD1CON1bits.SSRC      = 0x7;
    AD1CON1bits.SIMSAM    = 0x1;
    AD1CON1bits.ASAM      = 0x1;
    AD1CON2bits.VCFG      = 0x0;
    AD1CON2bits.CSCNA     = 0x0;
    AD1CON2bits.CHPS      = 0x1;
    AD1CON2bits.SMPI      = 0x0;
    AD1CON2bits.BUFM      = 0x0;
    AD1CON2bits.ALTS      = 0x1;
    AD1CON3bits.ADRC      = 0x1;
    AD1CON3bits.SAMC      = 0x1F;
    AD1CON3bits.ADCS      = 0xFF;
    AD1CHS123bits.CH123NB = 0x00;
    AD1CHS123bits.CH123SB = 0x1;
    AD1CHS123bits.CH123NA = 0x00;
    AD1CHS123bits.CH123SA = 0x0;
    AD1CHS0bits.CH0NB     = 0x0;
    AD1CHS0bits.CH0SB     = 0x07;
    AD1CHS0bits.CH0NA     = 0x0;
    AD1CHS0bits.CH0SA     = 0x06;
    AD1PCFGLbits.PCFG     = 0x1FFF;
}
