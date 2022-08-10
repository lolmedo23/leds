#include "unity.h"
#include "leds.h"
/**
 Revisar limites de los parametros.
 Revisar parámetros fuera de los limites..
 */

uint16_t leds_virtuales;

void setUp(void){
    LedsCreate(&leds_virtuales);
}

void tearDown(void){

}

//Con la inicialización de todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void){
    leds_virtuales = 0xFFFF;
    LedsCreate(&leds_virtuales);
    TEST_ASSERT_EQUAL(0X0000, leds_virtuales);
}

// Prender un LED individual
void test_prender_un_led_individual(void){
    LedsSingleTurnOn(3);
    TEST_ASSERT_EQUAL(1 << 2, leds_virtuales);
}

// Apagar un led individual
void test_apagar_un_led_individual(void){
    LedsSingleTurnOn(3);
    LedsSingleTurnOff(3);
    TEST_ASSERT_EQUAL(0, leds_virtuales);
}

// Prender y apagar múltiples leds
void test_prender_y_apagar_multiples_leds(void){
    LedsSingleTurnOn(3);
    LedsSingleTurnOn(7);
    LedsSingleTurnOff(7);
    TEST_ASSERT_EQUAL(1 << 2, leds_virtuales);
}

//Prender todos los leds de una vez
void test_prender_todos_los_leds(void){
    LedsAllTurnOn();
    TEST_ASSERT_EQUAL(0xFFFF, leds_virtuales);
}

// Apagar todos los leds de una vez
void test_apagar_todos_los_leds(void){
    LedsAllTurnOn();
    LedsAllTurnOff();
    TEST_ASSERT_EQUAL(0, leds_virtuales);
}

// Consultar el estado de un led que está en estado apagado
void test_estado_led_individual_apagado(void){
    TEST_ASSERT_EQUAL(false, IsLedOn(3));
}

// Consultar el estado de un led que está en estado encendido
void test_estado_led_individual_encendido(void){
    LedsSingleTurnOn(3);
    TEST_ASSERT_EQUAL(true, IsLedOn(3));
}