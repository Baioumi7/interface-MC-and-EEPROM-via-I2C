/*
 * interface__MC_and_EEPROM_via_I2C.c
 *
 *  Author: BAYOUMII
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "I2C.h"
#include "LCD.h"
int main(void)
{
	LCD_vInit();
	unsigned char x;
	/*write to the location 0b00000000000*/
	unsigned char counter=0;
	I2C_Master_init(50000);
	_delay_ms(500);
	I2C_start(); // transmit start condition
	I2C_write_address(0b10100000); // transmit device address and Write
	I2C_write_data(0b00000000); // transmit word address
	I2C_write_data(0x32); // transmit data
	I2C_stop(); // transmit stop condition
	
	/*read from the location 0b00000000000*/
	_delay_ms(200);
	I2C_start(); // transmit start condition
	I2C_write_address(0b10100000); // transmit device address and Write
	I2C_write_data(0b00000000); // transmit word address
	I2C_repeated_start(); // transmit repeated start condition
	I2C_write_address_and_read(0b10100001); // transmit device address and read
	x=I2C_read_with_NACK();
	I2C_stop();
	LCD_vSend_char(x);
	while(1)
	{
		
	}
}

