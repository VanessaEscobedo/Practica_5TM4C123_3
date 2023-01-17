#include "lib/include.h"
/*volatile float valor,valor1;
volatile uint16_t Result[2];
volatile uint16_t duty;
volatile uint16_t duty2;
volatile uint16_t duty3;*/

volatile uint16_t a; //volatil para poderla monitorear 
volatile uint16_t color;


uint16_t count;
int main(void)
{
    
//Experimento 3
/* Usando el modulo 0 de PWM con una frecuencia de reloj del sistema de 20,000,000 Hz
 * junto con el generador 0,1,2  habilitar alguno de los pwm's asociados y obtener un PWM
 * cuya frecuencia sea de 50Hz, utilizando el uart de la practica 3
 * se enviara dato desde interfaz de simulink para controlar la intensidad luminosa 
 * usando un led RGB externa  
 */
    Configurar_PLL(_20MHZ);  //configuracion de velocidad de reloj
    Configurar_UART0();
    Configura_Reg_PWM1(8);
    
    /*Experimento 0
    count = 0;
    duty=15999;
    duty2=15999;
    duty3=15999;*/

    /*a=1;
    b=16000;
    c=5000;*/

    while (1)
    {
        color = readChar();
        
        switch (color)
        {
            case 'r':
                a = (int)readChar(); //recibe el % del uart para calcular el dc%
                PWM0->_0_CMPB = 20000-((int)(a*10000)/50); //PB7 (R)
            break;

            case 'g':
                a = (int)readChar();
                PWM0->_1_CMPA = 20000-((int)(a*10000)/50); //PB4 (G)
            break;

            case 'b':
                a = (int)readChar();
                PWM0->_2_CMPA = 20000-((int)(a*10000)/50); //PE4 (B)
            break;

            default:
                a=1;
            break;
        }   
    }
}

