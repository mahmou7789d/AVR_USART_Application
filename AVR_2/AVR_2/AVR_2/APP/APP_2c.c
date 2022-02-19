/*
 * APP_2c.c
 *
 * Created: 2/18/2022 12:03:36 PM
 *  Author: Mahm Oud Sa Ad
 */ 
#include <USART_File.h>
#include <LED.h>
#include <LCD.h>
#include <APP_2.h>

#include <util/delay.h>


void APP2_Init()
{
	USART0.Micro_State=USART_Receiver;
	USART0.Communcation_Mode=USART_Asyn_Normal;
	USART0.Communication_Processor=USART_SingleProcessor;
	USART0.Baud_Rate=9600;
	USART0.Interrupt_Source=USART_Interrupt_Disable;
	USART0.Character_Size=Size_8bit;
	USART0.Frame_Control=USART_Parity_Disable_1StopBit;
	USART_Init();
	LCD_Init();
}
void APP2_System()
{
	uint_8 R_data;
	while(1)
	{
		R_data =USART_Receive_ByteOfData_Blocking();
		Send_char_LCD(R_data);
	}
	
	
}