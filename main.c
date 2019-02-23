/* 
 * File:   main.c
 * Author: A-A-Ron
 *
 * Created on July 23, 2017, 5:52 PM
 */

#include "mcc_generated_files/mcc.h"
#define _XTAL_FREQ 64000000


void blue(unsigned char v);
void cyan(unsigned char v);
void green(unsigned char v);
void yellow(unsigned char v);
void red(unsigned char v);
void magenta(unsigned char v);
void white(unsigned char v);
void off(void);
void oneBitOn(void);
void oneBitOff(void);
void lastBitOn(void);
void lastBitOff(void);
void allBitsOff(void);
void brightness(unsigned char grn, unsigned char red, unsigned char blu, unsigned char value );
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    unsigned int ADC_value = 0;
    unsigned char value = 0;
    unsigned char lastValue = 0;
    
    color = 0;
    while (1)
    {
        ADC_value = ADCC_GetSingleConversion(ADPCH0);
        value = ( ADC_value >> 2 );

        for( unsigned char j = 0; j < 25; j++ ){
            if (color < 1){
                off();
            }
            else if (color < 2){
                blue(value);
            }
            else if (color < 3){
                red(value);
            }
            else if (color < 4){  
                magenta(value);    
            }
            else if (color < 5){
                green(value);    
            }
            else if (color < 6){ 
                cyan(value);
            }
            else if (color < 7){          
                yellow(value);
            }
            else{
                white(value);
            }
        }
        
        __delay_us(10); 
    }
}

void brightness( unsigned char red, unsigned char grn, unsigned char blu, unsigned char value ){
    unsigned char bit7 = 0;//(value >> 7) & 1;
    unsigned char bit6 = 1;//(value >> 6) & 1;
    unsigned char bit5 = 1;//(value >> 5) & 1;
    unsigned char bit4 = 1;//(value >> 4) & 1;
    unsigned char bit3 = 1;//(value >> 3) & 1;
    unsigned char bit2 = 1;//(value >> 2) & 1;
    unsigned char bit1 = 1;//(value >> 1) & 1;
    unsigned char bit0 = 1;//(value) & 1;
    
    if (red){
        
        if (bit7 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit6 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit5 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit4 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit3 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit2 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
 
        
        if (bit1 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit0 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
    }
    else{

        allBitsOff();
    }
    
    
    if (grn){
        
        if (bit7 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit6 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit5 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit4 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit3 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit2 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
 
        
        if (bit1 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit0 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
    }
    else{

        allBitsOff();
    }

    
    if (blu){
        
        if (bit7 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit6 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit5 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
        
        
        if (bit4 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit3 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit2 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }
 
        
        if (bit1 == 1){
            oneBitOn();
        }
        else{
            oneBitOff();
        }

        
        if (bit0 == 1){
            lastBitOn();
        }
        else{
            lastBitOff();
        }
        
    }
    else{

        allBitsOff();
    }
}
            
void white(unsigned char v){
    brightness(1, 1, 1, v);
}


void cyan(unsigned char v){
    brightness(0, 1, 1, v);
}


void yellow(unsigned char v){
    brightness(1, 1, 0, v);
}


void magenta(unsigned char v){          
    brightness(1, 0, 1, v);
}


void green(unsigned char v){      
    brightness(0, 1, 0, v);
}


void blue(unsigned char v){
    brightness(0, 0, 1, v);
}


void red(unsigned char v){
    brightness(1, 0, 0, v);
}


void off(void){
    brightness(0, 0, 0, 0);
}


void allBitsOff(void){

    /*for (int i = 0; i < 8; i++){
        PORTCbits.RC0 = 1;
        __delay_us(0.15);
        PORTCbits.RC0 = 0;
        __delay_us(0.6);
    }*/
    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }


    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }


    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }


    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }


    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }


    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }


    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }


    if (0 == 1){
        oneBitOn();
    }
    else{
        oneBitOff();
    }
}


void oneBitOn(void){
    
        PORTCbits.RC0 = 1;
        __delay_us(.7);
        PORTCbits.RC0 = 0;
        __delay_us(0.6); 
}


void oneBitOff(void){
    
        PORTCbits.RC0 = 1;
        __delay_us(0.35);
        PORTCbits.RC0 = 0;
        __delay_us(0.6); 
}


void lastBitOn(void){
    
        PORTCbits.RC0 = 1;
        __delay_us(0.7);
        PORTCbits.RC0 = 0;
        __delay_us(0.3);
}


void lastBitOff(void){
    
        PORTCbits.RC0 = 1;
        __delay_us(0.35);
        PORTCbits.RC0 = 0;
        __delay_us(0.3);
}
/**
 End of File
*/