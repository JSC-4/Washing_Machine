/*
 * File:   LED.c
 * Author: Jerome
 *
 * Created on 01 October 2018, 15:05
 */

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include "MyLCD.h"

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ  20000000

#define menuB   PORTEbits.RE2   //Cycle through menu
#define selectB PORTEbits.RE1   //Select menu option
#define actionB PORTEbits.RE0   //Start and stop button

void Setup();
void Option();

void main()
{
    unsigned int a;
    
    TRISD = 0x00;
    TRISE = 0b111;
    
    ADCON1 = 0b11110111;
    
    Lcd_Start();
    Setup();
    Option();
    while (1)
    {

    }
}

void Setup()
{
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Print_String("Select your");
        Lcd_Set_Cursor(2,1);
        Lcd_Print_String("option:");
}

void Option()
{
    uint8_t oC;
    
    if (menuB == 0)
        oC++;
    else if (oC == 4)
        oC == 0;
    
    switch (oC)
    {
        case 0:
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Print_String("Quick Wash");
            Lcd_Set_Cursor(2,1);
            Lcd_Print_String("OK?");
            break;
        case 1:
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Print_String("Fast Wash");
            Lcd_Set_Cursor(2,1);
            Lcd_Print_String("OK?");
            break;
        case 2:
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Print_String("Medium Wash");
            Lcd_Set_Cursor(2,1);
            Lcd_Print_String("OK?");
            break;
        case 3:
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Print_String("Slow Wash");
            Lcd_Set_Cursor(2,1);
            Lcd_Print_String("OK?");
            break;
    }
        
        
}

//Long, medium, short and quick