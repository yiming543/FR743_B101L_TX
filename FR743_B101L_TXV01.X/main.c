/*
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1936
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/

//20250711 CS:B77A V01
//初版只有遠燈
// D5 bit5 行車			
// D2 bit0 晝行			
// D1 bit3 近燈			
// D1 bit6 遠燈			
// D1 bit4 左方向						
// D1 bit5 右方向


#include "mcc_generated_files/mcc.h"
#define SET_BIT(x, bit)      ((x) |= (1 << (bit)))
#define CLEAR_BIT(x, bit)    ((x) &= (~(1 << (bit))))

// void SET_BIT(uint8_t *byte, uint8_t bit)
// {
//     *byte |= (1 << bit);
// }

// void CLEAR_BIT(uint8_t *byte, uint8_t bit)
// {
//     *byte &= ~(1 << bit);
// }

/*
                         Main application
 */

// extern uint8_t SW_STATE_Data[];

int main(void)
{
  // initialize the device
  SYSTEM_Initialize();

  // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
  // Use the following macros to:

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();

  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  // Disable the Global Interrupts
  // INTERRUPT_GlobalInterruptDisable();

  // Disable the Peripheral Interrupts
  // INTERRUPT_PeripheralInterruptDisable();
  
  SW_STATE_Data[0] = 0x24;
  SW_STATE_Data[1] = 0x08;
  SW_STATE_Data[2] = 0x94;
  SW_STATE_Data[3] = 0x00;
  SW_STATE_Data[4] = 0x2F;
  SW_STATE_Data[5] = 0x00;
  SW_STATE_Data[6] = 0xA3;
  SW_STATE_Data[7] = 0xBE;

  while (1)
  {
    // Add your application code
    LIN_handler();

    //行車
    if (SW1_GetValue() == LOW)
    {
      LED1_SetHigh();
      SET_BIT(SW_STATE_Data[5], 5);
    }
    else
    {
      LED1_SetLow();
      CLEAR_BIT(SW_STATE_Data[5], 5);
    }

    //晝行
    if (SW2_GetValue() == LOW)
    {
      LED2_SetHigh();
      SET_BIT(SW_STATE_Data[2], 0);
    }
    else
    {
      LED2_SetLow();
      CLEAR_BIT(SW_STATE_Data[2], 0);
    }

    //近燈
    if (SW3_GetValue() == LOW)
    {
      LED3_SetHigh();
      SET_BIT(SW_STATE_Data[1], 3);
    }
    else
    {
      LED3_SetLow();
      CLEAR_BIT(SW_STATE_Data[1], 3);
    }

    //遠燈
    if (SW4_GetValue() == LOW)
    {
      LED4_SetHigh();
      SET_BIT(SW_STATE_Data[1], 6);
      // SET_BIT(SW_STATE_Data[1], 7);
    }
    else
    {
      LED4_SetLow();
      CLEAR_BIT(SW_STATE_Data[1], 6);
      // CLEAR_BIT(SW_STATE_Data[1], 7);
    }

    //左方向
    if (SW5_GetValue() == LOW)
   {
      LED5_SetHigh();
      SET_BIT(SW_STATE_Data[1], 4);
      // SET_BIT(SW_STATE_Data[1], 5);
    }
    else
    {
      LED5_SetLow();
      CLEAR_BIT(SW_STATE_Data[1], 4);
      // CLEAR_BIT(SW_STATE_Data[1], 5);
    }

    //右方向
    if (SW6_GetValue() == LOW)
   {
      LED6_SetHigh();
      // SET_BIT(SW_STATE_Data[1], 4);
      SET_BIT(SW_STATE_Data[1], 5);
    }
    else
    {
      LED6_SetLow();
      // CLEAR_BIT(SW_STATE_Data[1], 4);
      CLEAR_BIT(SW_STATE_Data[1], 5);
    }
  }
}
/**
 End of File
*/