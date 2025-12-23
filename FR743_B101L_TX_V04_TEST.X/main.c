/*
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules
  selected in the GUI. Generation Information : Product Revision  :  PIC10 /
  PIC12 / PIC16 / PIC18 MCUs - 1.81.8 Device            :  PIC16F1936 Driver
  Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software
   and any derivatives exclusively with Microchip products. It is your
   responsibility to comply with third party license terms applicable to your
   use of third party software (including open source software) that may
   accompany Microchip software.

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

// 20250711 CS:3166 V01
// 初版只有遠燈
//  D2 bit3 行車
//  D2 bit6 晝行
//  D1 bit7 超車
//  D1 bit6 遠燈
//  D1 bit5 右方向
//  D1 bit4 左方向
// D0    D1    D2    D3    D4    D5    D6    D7
// 0x24  0x00  0x00  0x00  0x00  0x00  0x00  0x00

// D0
// 0x01 UNLOCK
// 0x11 LOCK
// 0x24 引擎啟動

// D1
// 0x80 超車 bit7
// 0x40 遠燈 bit6
// 0x20 右方向 bit5
// 0x10 左方向 bit4

// D2
// 0x51 OFF mode 晝行
// 0x14 POS mode 位置燈(行車)
// 0x4C AUTO mode 白天 晝行
// 0x94 AUTO mode 夜間 近燈+行車
// 0x13 近燈 mode 近燈
// bit6 晝行
// bit3 行車

// SW123456
// 000000 24 00 51 00 00 00 00 00 OFF mode 晝行
// 000100 24 80 51 00 00 00 00 00 OFF mode 晝行 + 超車
// 000010 24 10 51 00 00 00 00 00 OFF mode 晝行 + 左方向
// 000001 24 20 51 00 00 00 00 00 OFF mode 晝行 + 右方向
// 000011 24 30 51 00 00 00 00 00 OFF mode 晝行 + 警示
// 000110 24 90 51 00 00 00 00 00 OFF mode 晝行 + 左方向 + 超車
// 000101 24 A0 51 00 00 00 00 00 OFF mode 晝行 + 右方向 + 超車
// 000111 24 B0 51 00 00 00 00 00 OFF mode 晝行 + 警示 + 超車

// 010000 24 00 14 00 00 00 00 00 POS mode 行車
// 010100 24 80 14 00 00 00 00 00 POS mode 行車 + 超車
// 010010 24 10 14 00 00 00 00 00 POS mode 行車 + 左方向
// 010001 24 20 14 00 00 00 00 00 POS mode 行車 + 右方向
// 010011 24 30 14 00 00 00 00 00 POS mode 行車 + 警示
// 010110 24 90 14 00 00 00 00 00 POS mode 行車 + 左方向 + 超車
// 010101 24 A0 14 00 00 00 00 00 POS mode 行車 + 右方向 + 超車
// 010111 24 B0 14 00 00 00 00 00 POS mode 行車 + 警示 + 超車

// 001000 24 00 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車
// 001100 24 80 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車 + 超車
// 001010 24 10 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車 + 左方向
// 001001 24 20 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車 + 右方向
// 001011 24 30 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車 + 警示
// 001110 24 90 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車 + 左方向 + 超車
// 001101 24 A0 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車 + 右方向 + 超車
// 001111 24 B0 94 00 00 00 00 00 AUTO mode 晚上 近燈 + 行車 + 警示 + 超車

// 101000 24 00 4C 00 00 00 00 00 AUTO mode 白天 晝行
// 101100 24 80 4C 00 00 00 00 00 AUTO mode 白天 晝行 + 超車
// 101010 24 10 4C 00 00 00 00 00 AUTO mode 白天 晝行 + 左方向
// 101001 24 20 4C 00 00 00 00 00 AUTO mode 白天 晝行 + 右方向
// 101011 24 30 4C 00 00 00 00 00 AUTO mode 白天 晝行 + 警示
// 101110 24 90 4C 00 00 00 00 00 AUTO mode 白天 晝行 + 左方向 + 超車
// 101101 24 A0 4C 00 00 00 00 00 AUTO mode 白天 晝行 + 右方向 + 超車
// 101111 24 B0 4C 00 00 00 00 00 AUTO mode 白天 晝行 + 警示 + 超車

// 011000 24 00 13 00 00 00 00 00 近燈 mode 近燈
// 011100 24 80 13 00 00 00 00 00 近燈 mode 近燈 + 超車
// 011010 24 10 13 00 00 00 00 00 近燈 mode 近燈 + 左方向
// 011001 24 20 13 00 00 00 00 00 近燈 mode 近燈 + 右方向
// 011011 24 30 13 00 00 00 00 00 近燈 mode 近燈 + 警示
// 011110 24 90 13 00 00 00 00 00 近燈 mode 近燈 + 左方向 + 超車
// 011101 24 A0 13 00 00 00 00 00 近燈 mode 近燈 + 右方向 + 超車
// 011111 24 B0 13 00 00 00 00 00 近燈 mode 近燈 + 警示 + 超車

// Const 啟動碼 As Integer = &H24  'D0
// Const UNLOCK碼 As Integer = &H1  'D0
// Const LOCK碼 As Integer = &H11  'D0

// Const 超車碼 As Integer = &H80  'D1
// Const 遠燈碼 As Integer = &H40  'D1
// Const 右方向碼 As Integer = &H20    'D1
// Const 左方向碼 As Integer = &H10    'D1

// Const OFF模式碼_24 As Integer = &H51   'D2 2024
// Const 行車模式碼_24 As Integer = &H14   'D2 2024
// Const 行車模式碼_24_2 As Integer = &H12   'D2 2024
// Const AUTO晚上模式碼_24 As Integer = &H94  'D2 2024
// Const AUTO晚上模式碼_24_2 As Integer = &HAC  'D2 2024
// Const 近燈模式碼_24 As Integer = &H13   'D2 2024

// Const OFF模式碼 As Integer = &H49   'D2 2023
// Const 行車模式碼 As Integer = &HA   'D2 2023
// Const AUTO白天模式碼 As Integer = &H4C  'D2 2023
// Const AUTO晚上模式碼 As Integer = &H8C  'D2 2023
// Const 近燈模式碼 As Integer = &HB   'D2 2023
// Const 晝行碼 As Integer = &H40   'D2

// Const 近燈碼 As Integer = &H8   'D4
// Const 行車碼 As Integer = &H3   'D4

// 20251008 V02 CS:CFDF
//  修正信號不穩定 晝行

// 20251125 V03 CS:50C7
// 每個按鍵獨立功能，測試用

#include "mcc_generated_files/mcc.h"
#define SET_BIT(x, bit) ((x) |= (1 << (bit)))
#define CLEAR_BIT(x, bit) ((x) &= (~(1 << (bit))))

#define ON 0
#define OFF 1

#define SW1_ON() (SW1_GetValue() == ON)
#define SW2_ON() (SW2_GetValue() == ON)
#define SW2_OFF() (SW2_GetValue() == OFF)
#define SW3_ON() (SW3_GetValue() == ON)
#define SW3_OFF() (SW3_GetValue() == OFF)
#define SW4_ON() (SW4_GetValue() == ON)
#define SW5_ON() (SW5_GetValue() == ON)
#define SW6_ON() (SW6_GetValue() == ON)

#define LED1_ON() LED1_SetHigh()
#define LED1_OFF() LED1_SetLow()
#define LED2_ON() LED2_SetHigh()
#define LED2_OFF() LED2_SetLow()
#define LED3_ON() LED3_SetHigh()
#define LED3_OFF() LED3_SetLow()
#define LED4_ON() LED4_SetHigh()
#define LED4_OFF() LED4_SetLow()
#define LED5_ON() LED5_SetHigh()
#define LED5_OFF() LED5_SetLow()
#define LED6_ON() LED6_SetHigh()
#define LED6_OFF() LED6_SetLow()

/*
                         Main application
 */

// extern uint8_t SW_STATE_Data[];

int main(void) {
  // initialize the device
  SYSTEM_Initialize();

  // When using interrupts, you need to set the Global and Peripheral Interrupt
  // Enable bits Use the following macros to:

  // Enable the Global Interrupts
  INTERRUPT_GlobalInterruptEnable();
  // Enable the Peripheral Interrupts
  INTERRUPT_PeripheralInterruptEnable();

  SW_STATE_Data[0] = 0x00;
  SW_STATE_Data[1] = 0x00;
  SW_STATE_Data[2] = 0x00;
  SW_STATE_Data[3] = 0x00;
  SW_STATE_Data[4] = 0x00;
  SW_STATE_Data[5] = 0x00;
  SW_STATE_Data[6] = 0x00;
  SW_STATE_Data[7] = 0x00;

  while (1) {
    // Add your application code
    LIN_handler();

    // if (SW1_ON()) {//POS
    //   LED1_ON();
    //   LED2_OFF();
    //   LED3_OFF();
    //   LED4_OFF();
    //   SW_STATE_Data[0] = 0x24;
    //   SW_STATE_Data[1] = 0x08;
    //   SW_STATE_Data[2] = 0x12; //POS
    //   SW_STATE_Data[3] = 0x00;
    //   SW_STATE_Data[4] = 0x27;
    //   SW_STATE_Data[5] = 0x20;
    //   SW_STATE_Data[6] = 0xB5;
    //   SW_STATE_Data[7] = 0xBE;
    // } else if (SW2_ON()) {//DRL
    //   LED2_ON();
    //   LED1_OFF();
    //   LED3_OFF();
    //   LED4_OFF();
    //   SW_STATE_Data[0] = 0x24;
    //   SW_STATE_Data[1] = 0x08;
    //   SW_STATE_Data[2] = 0x51; //DRL
    //   SW_STATE_Data[3] = 0x00;
    //   SW_STATE_Data[4] = 0x24;
    //   SW_STATE_Data[5] = 0x20;
    //   SW_STATE_Data[6] = 0xB4;
    //   SW_STATE_Data[7] = 0xBE;
    // } else if (SW3_ON()) {//POS+LoBeam
    //   LED3_ON();
    //   LED1_OFF();
    //   LED2_OFF();
    //   LED4_OFF();
    //   SW_STATE_Data[0] = 0x24;
    //   SW_STATE_Data[1] = 0x08;
    //   SW_STATE_Data[2] = 0x13; //Lobeam
    //   SW_STATE_Data[3] = 0x00;
    //   SW_STATE_Data[4] = 0x2F;
    //   SW_STATE_Data[5] = 0x20;
    //   SW_STATE_Data[6] = 0xB4;
    //   SW_STATE_Data[7] = 0xBE;
    // } else if (SW4_ON()) {//
    //   LED4_ON();
    //   LED1_OFF();
    //   LED2_OFF();
    //   LED3_OFF();
    //   SW_STATE_Data[0] = 0x24;
    //   SW_STATE_Data[1] = 0x08;//超車
    //   SW_STATE_Data[2] = 0x94;//0x8C;  //Lobeam
    //   SW_STATE_Data[3] = 0x00;
    //   SW_STATE_Data[4] = 0x2F;
    //   SW_STATE_Data[5] = 0x20;
    //   SW_STATE_Data[6] = 0x7C;
    //   SW_STATE_Data[7] = 0xBE;
    // } else {
    //   LED1_OFF();
    //   LED2_OFF();
    //   LED3_OFF();
    //   LED3_OFF();
    //   SW_STATE_Data[0] = 0x01;
    //   SW_STATE_Data[1] = 0x08;
    //   SW_STATE_Data[2] = 0x14;
    //   SW_STATE_Data[3] = 0x00;
    //   SW_STATE_Data[4] = 0x27;
    //   SW_STATE_Data[5] = 0x00;
    //   SW_STATE_Data[6] = 0x00;
    //   SW_STATE_Data[7] = 0x00;
    // }

#ifdef CAR_MODE
    // SW1 白天/夜間
    if (SW1_ON()) {
      LED1_ON();
    } else {
      LED1_OFF();
    }
    // SW2 & SW3 OFF/POS/AUTO/近燈
    if (SW2_OFF() && SW3_OFF()) { // OFF mode
      LED2_OFF();
      LED3_OFF();
      SW_STATE_Data[2] = 0x51; // 晝行
      // SET_BIT(SW_STATE_Data[2], 6);
      CLEAR_BIT(SW_STATE_Data[4], 3);
      CLEAR_BIT(SW_STATE_Data[4], 0);
      CLEAR_BIT(SW_STATE_Data[4], 1);
    } else if (SW2_ON() && SW3_OFF()) { // POS mode
      LED2_ON();
      LED3_OFF();
      SW_STATE_Data[2] = 0x14; // 位置燈(行車)
      // CLEAR_BIT(SW_STATE_Data[2], 6);
      CLEAR_BIT(SW_STATE_Data[4], 3);
      SET_BIT(SW_STATE_Data[4], 0);
      SET_BIT(SW_STATE_Data[4], 1);
    } else if (SW2_OFF() && SW3_ON()) { // AUTO mode
      LED2_OFF();
      LED3_ON();
      if (SW1_ON()) {            // 白天
        SW_STATE_Data[2] = 0x4C; // 晝行
        // SET_BIT(SW_STATE_Data[2], 6);
        CLEAR_BIT(SW_STATE_Data[4], 3);
        CLEAR_BIT(SW_STATE_Data[4], 0);
        CLEAR_BIT(SW_STATE_Data[4], 1);
      } else {                   // 夜間
        SW_STATE_Data[2] = 0x94; // 近燈+行車
        // CLEAR_BIT(SW_STATE_Data[2], 6);
        SET_BIT(SW_STATE_Data[4], 3);
        SET_BIT(SW_STATE_Data[4], 0);
        SET_BIT(SW_STATE_Data[4], 1);
      }
    } else if (SW2_ON() && SW3_ON()) { // 近燈 mode
      LED2_ON();
      LED3_ON();
      SW_STATE_Data[2] = 0x13; // 近燈
      // CLEAR_BIT(SW_STATE_Data[2], 6);
      SET_BIT(SW_STATE_Data[4], 3);
      SET_BIT(SW_STATE_Data[4], 0);
      SET_BIT(SW_STATE_Data[4], 1);
    }
#endif

    // // 遠燈 & 超車
    // if (SW4_ON()) {
    //   LED4_ON();
    //   SET_BIT(SW_STATE_Data[1], 6);
    //   SET_BIT(SW_STATE_Data[1], 7);
    // } else {
    //   LED4_OFF();
    //   CLEAR_BIT(SW_STATE_Data[1], 6);
    //   CLEAR_BIT(SW_STATE_Data[1], 7);
    // }

    // // 左方向
    // if (SW5_ON()) {
    //   LED5_ON();
    //   SET_BIT(SW_STATE_Data[1], 4);
    // } else {
    //   LED5_OFF();
    //   CLEAR_BIT(SW_STATE_Data[1], 4);
    // }

    // // 右方向
    // if (SW6_ON()) {
    //   LED6_ON();
    //   SET_BIT(SW_STATE_Data[1], 5);
    // } else {
    //   LED6_OFF();
    //   CLEAR_BIT(SW_STATE_Data[1], 5);
    // }
  }
}
/**
 End of File
*/