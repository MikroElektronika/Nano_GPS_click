#line 1 "D:/Clicks_git/N/NANO_GPS_Click/SW/example/c/ARM/STM/Click_NanoGPS_STM.c"
#line 1 "d:/clicks_git/n/nano_gps_click/sw/example/c/arm/stm/click_nanogps_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"



 typedef char _Bool;
#line 1 "d:/clicks_git/n/nano_gps_click/sw/example/c/arm/stm/click_nanogps_config.h"
#line 1 "d:/clicks_git/n/nano_gps_click/sw/example/c/arm/stm/click_nanogps_types.h"
#line 3 "d:/clicks_git/n/nano_gps_click/sw/example/c/arm/stm/click_nanogps_config.h"
const uint32_t _NANOGPS_TIMER_LIMIT = 5;
const uint16_t _NANOGPS_BUF_WARNING = 192;
const uint8_t _NANOGPS_POLL_ENABLE = 1;
const uint8_t _NANOGPS_CALLBACK_ENABLE = 0;

const uint32_t _NANOGPS_UART_CFG[ 4 ] =
{
 4800,
 _UART_8_BIT_DATA,
 _UART_NOPARITY,
 _UART_ONE_STOPBIT
};
#line 1 "d:/clicks_git/n/nano_gps_click/sw/example/c/arm/stm/click_nanogps_timer.h"
#line 1 "d:/clicks_git/n/nano_gps_click/sw/example/c/arm/stm/click_nanogps_types.h"
#line 1 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"
#line 53 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
extern const uint8_t _NANOGPS_UNKNOWN ;
extern const uint8_t _NANOGPS_TEST ;
extern const uint8_t _NANOGPS_SET ;
extern const uint8_t _NANOGPS_GET ;
extern const uint8_t _NANOGPS_URC ;
extern const uint8_t _NANOGPS_EXEC ;



extern const uint8_t _NANOGPS_EVARG_START_T ;
extern const uint8_t _NANOGPS_EVARG_END_T ;
extern const uint8_t _NANOGPS_EVARG_EVENT_T ;

extern const uint8_t _NANOGPS_EVENT_RESPONSE ;
extern const uint8_t _NANOGPS_EVENT_TIMEOUT ;
extern const uint8_t _NANOGPS_EVENT_BUFFER_OUT ;
extern const uint8_t _NANOGPS_EVENT_CALLBACK ;
#line 75 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
typedef void ( *T_nanogps_handler )( char *buffer, uint8_t *evArgs );
#line 91 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_uartDriverInit( const uint8_t*  gpioObj,  const uint8_t*  uartObj);
#line 103 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_coreInit( T_nanogps_handler defaultHdl, uint32_t defaultWdog );
#line 115 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_hfcEnable(  _Bool  hfcState );
#line 124 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_modulePower(  _Bool  powerState );
#line 135 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_putc( char rxInput );
#line 143 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_tick();
#line 154 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
uint16_t nanogps_setHandler( char *pCmd, uint32_t timeout, T_nanogps_handler pHandler );
#line 164 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_cmdSingle( char *pCmd );
#line 176 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_cmdDouble( char *pCmd, char *pArg1 );
#line 189 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_cmdTriple( char *pCmd, char *pArg1, char *pArg2 );
#line 196 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
void nanogps_process();
#line 210 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
char *nanogps_parser(char *dataIn, char *command, uint8_t dataPos);
#line 12 "d:/clicks_git/n/nano_gps_click/sw/example/c/arm/stm/click_nanogps_timer.h"
uint32_t timerCounter = 0;

static void nanogps_configTimer()
{
 RCC_APB1ENR.TIM2EN = 1;
 TIM2_CR1.CEN = 0;
 TIM2_PSC = 1;
 TIM2_ARR = 35999;
 NVIC_IntEnable(IVT_INT_TIM2);
 TIM2_DIER.UIE = 1;
 TIM2_CR1.CEN = 1;
 EnableInterrupts();
}

void Timer_interrupt() iv IVT_INT_TIM2
{
 nanogps_tick();
 timerCounter++;
 TIM2_SR.UIF = 0;
}
#line 1 "d:/clicks_git/n/nano_gps_click/sw/library/__nanogps_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"
#line 48 "D:/Clicks_git/N/NANO_GPS_Click/SW/example/c/ARM/STM/Click_NanoGPS_STM.c"
uint8_t pFlag = 0;
uint8_t dispFlag = 0;
char demoBuffer[ 500 ] = {0};
char demoCommand[ 16 ] = "$GPGGA";

void nanogps_default_handler( uint8_t *rsp, uint8_t *evArgs )
{
 char *tmp;
 tmp = rsp;

 mikrobus_logWrite( tmp, _LOG_TEXT );
 if(*rsp == '$')
 {
 memset(&demoBuffer[0], 0, 500);
 strcpy(demoBuffer, tmp);
 }
}

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_uartInit( _MIKROBUS1, &_NANOGPS_UART_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 4800 );
 mikrobus_logWrite("--- System Init ---", _LOG_LINE);
}

void applicationInit()
{

 nanogps_configTimer();


 nanogps_uartDriverInit(( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_UART);
 nanogps_coreInit( nanogps_default_handler, 1500 );


 nanogps_hfcEnable( 1 );
 nanogps_modulePower( 1 );

 Delay_ms( 5000 );
 timerCounter = 0;
}

void applicationTask()
{
 char *pLat;
 char *pLong;
 char *pAlt;
 char rspCom[ 50 ] = {0};


 nanogps_process();

 if(timerCounter > 5000)
 {
 pFlag++;
 if(pFlag > 2)
 {
 pFlag = 0;
 }
 timerCounter = 0;
 dispFlag = 1;
 }

 if(pFlag == 0 && dispFlag == 1)
 {
 mikrobus_logWrite("  ", _LOG_LINE);
 mikrobus_logWrite( " ---------------------------------------- ", _LOG_LINE);
 pLat = nanogps_parser(&demoBuffer[0], &demoCommand[0], 2);

 if(pLat == 0)
 {
 mikrobus_logWrite( " Latitude : No data available!", _LOG_LINE);
 }
 else
 {
 strcpy(&rspCom[0], pLat);
 mikrobus_logWrite( " Latitude : ", _LOG_TEXT);
 mikrobus_logWrite(rspCom, _LOG_LINE);
 }
 dispFlag = 0;
 mikrobus_logWrite( " ---------------------------------------- ", _LOG_LINE);
 }

 if(pFlag == 2 && dispFlag == 1)
 {
 mikrobus_logWrite("  ", _LOG_LINE);
 mikrobus_logWrite( " ---------------------------------------- ", _LOG_LINE);
 pAlt = nanogps_parser(&demoBuffer[0], &demoCommand[0], 9);
 if(pAlt == 0)
 {
 mikrobus_logWrite( " Altitude : No data available!", _LOG_LINE);
 }
 else
 {
 strcpy(&rspCom[0], pAlt);
 mikrobus_logWrite( " Altitude : ", _LOG_TEXT);
 mikrobus_logWrite(rspCom, _LOG_LINE);
 }
 dispFlag = 0;
 mikrobus_logWrite( " ---------------------------------------- ", _LOG_LINE);
 }

 if(pFlag == 1 && dispFlag == 1)
 {
 mikrobus_logWrite("  ", _LOG_LINE);
 mikrobus_logWrite( " ---------------------------------------- ", _LOG_LINE);
 pLong = nanogps_parser(&demoBuffer[0], &demoCommand[0], 4);
 if(pLong == 0)
 {
 mikrobus_logWrite( " Longitude : No data available!", _LOG_LINE);
 }
 else
 {
 strcpy(&rspCom[0], pLong);
 mikrobus_logWrite( " Longitude : ", _LOG_TEXT);
 mikrobus_logWrite(rspCom, _LOG_LINE);
 }
 dispFlag = 0;
 mikrobus_logWrite( " ---------------------------------------- ", _LOG_LINE);
 }
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
