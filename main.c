/*
 * task_eins.c
 *
 * Created: 9/4/2020 9:28:06 PM
 * Author : monad
 */ 

#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD &=~ (1<<2); // PIN 2 IN PORTD IS INPUT
	DDRC |= (1<<2);  //PIN 2 IN PORTC IS OUTPUT
	DDRC |= (1<<7); //PIN 7 IN PORTC IS OUTPUT
	DDRD |= (1<<3); //PIN3 IN PORTD IS OUTPUT
	DDRA |=(1<<3);
    /* Replace with your application code */
	char flag=0;
    while (1) 
		{
		  if ((((PIND>>2) & 1)==1) && (flag==0))
		  {
			  while ((((PIND>>2) & 1)==1) && (flag==0));
			  PORTC |=(1<<2);
			  _delay_ms(50);
			  ++flag;
		  }
		  if ((((PIND>>2) & 1)==1) && (flag==1))
		  {
			  while ((((PIND>>2) & 1)==1) && (flag==1));
			  PORTC |=(1<<7);
			  _delay_ms(50);
			  ++flag;
		  }
		  if ((((PIND>>2) & 1)==1) && (flag==2))
		  {
			  while ((((PIND>>2) & 1)==1) && (flag==2));
			  PORTD |=(1<<3);
			  PORTA |=(1<<3);
			  _delay_ms(50);
			  ++flag;
		  }
		  if ((((PIND>>2) & 1)==1) && (flag==3))
		  {
		       while ((((PIND>>2) & 1)==1) && (flag==3));
			   PORTC &=~(1<<2);
			   PORTC &=~(1<<7);
			   PORTD &=~(1<<3);
			   PORTA &=~(1<<3);
			   flag=0;
			   _delay_ms(50);
		  }
		}   

		
}

