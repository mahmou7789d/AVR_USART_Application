/*
 * AVR_1.c
 *
 * Created: 2/17/2022 3:45:06 PM
 *  Author: Mahm Oud Sa Ad
 */ 

#include <APP_1.h>
int main(void)
{
	APP1_Init();
	while (1)
	{
		APP1_System();
	}


}