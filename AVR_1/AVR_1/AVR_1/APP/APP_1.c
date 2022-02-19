/*
 * APP_1.c
 *
 * Created: 2/18/2022 11:52:41 AM
 *  Author: Mahm Oud Sa Ad
 */ 

#include <USART_File.h>
#include <LED.h>
#include <Keypad.h>
#include <APP_1.h>
#include <util/delay.h>
#include <LCD.h>
Keypad_Data keypad_app = {Port_A, PIN0, PIN1, PIN2, PIN3, PIN4, PIN5,PIN6, PIN7};
uint_8 keypad_Read_Value;


void APP1_Init()
{
	USART0.Micro_State=USART_Transmitter;
	USART0.Communcation_Mode=USART_Asyn_Normal;
	USART0.Communication_Processor=USART_SingleProcessor;
	USART0.Baud_Rate=9600;
	USART0.Interrupt_Source=USART_Interrupt_Disable;
	USART0.Character_Size=Size_8bit;
	USART0.Frame_Control=USART_Parity_Disable_1StopBit;
	USART_Init();
	keypad_Init(keypad_app);
	_delay_ms(300);
	USART_Send_String("Welcome");
	
}
void APP1_System()
{
	_delay_ms(300);
	do
	{
		keypad_Read_Value=keypad_Read(keypad_app);
		_delay_ms(100);
	} while (keypad_Read_Value ==Keypad_Not_Pressed);
	/*
	---> in this case the value of null character will be printed
	uint_8 *TData = & keypad_Read_Value;
	USART_Send_String(TData);
	*/
	USART_Send_ByteOfData_Blocking(keypad_Read_Value);
	switch (keypad_Read_Value)
	{
		case '+':
		_delay_ms(200);
		USART_Send_ByteOfData_Blocking(keypad_Read_Value);
		_delay_ms(300);
		keypad_Read_Value=keypad_Read(keypad_app);
		_delay_ms(300);
		USART_Send_ByteOfData_Blocking(keypad_Read_Value);
		break;
		
		
	}
	
}