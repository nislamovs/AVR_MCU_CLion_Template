#include <avr/io.h>
#include <util/delay.h>
#include "easyavr.h"

#define LED_PORT PORTD
#define LED_PIN1 0
#define LED_PIN2 1
#define LED_DDR DDRD

#define F_CPU 8000000UL

#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

//Declaration of our functions
void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);

char String[]="Hello world!!\r\n";


void USART_init(void){

    UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
    UBRR0L = (uint8_t)(BAUD_PRESCALLER);
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (3<<UCSZ00);
}

unsigned char USART_receive(void){

    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;

}

void USART_send( unsigned char data){

    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;

}

void USART_putstring(char* StringPtr){

    while(*StringPtr != 0x00){
        USART_send(*StringPtr++);
    }
}


int main(void){
    USART_init();        //Call the USART initialization code

    while(1){        //Infinite loop
        USART_putstring(String);    //Pass the string to the USART_putstring function and sends it over the serial
        _delay_ms(1000);        //Delay for 5 seconds so it will re-send the string every 5 seconds
    }

    return 0;
}

//int main(void)
//{
//    PIN_AS_OUTPUT(LED_DDR, LED_PIN1);
//    PIN_AS_OUTPUT(LED_DDR, LED_PIN2);
//
//    while (1) {
//        PIN_ON(LED_PORT, LED_PIN1);
//        _delay_ms(100);
//        PIN_OFF(LED_PORT, LED_PIN1);
//        _delay_ms(100);
//    }
//}
