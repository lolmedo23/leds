#include "leds.h"

#define LEDS_OFFSET 1
#define FIRST_BIT_ON 1
#define LEDS_ALL_OFF 0
#define LEDS_ALL_ON 0xFFFF

static uint16_t * puerto;

static uint16_t LedToMask(uint8_t led) {
    return (FIRST_BIT_ON << (led - LEDS_OFFSET));
}

void LedsCreate(uint16_t * address) {
    puerto = address;
    LedsAllTurnOff();
}

void LedsSingleTurnOn(uint8_t led) {
    *puerto |= LedToMask(led);
}

void LedsSingleTurnOff(uint8_t led) {
    *puerto &= ~LedToMask(led);
}

void LedsAllTurnOn(){
    *puerto = LEDS_ALL_ON;
}

void LedsAllTurnOff(){
    *puerto = LEDS_ALL_OFF;
}

bool IsLedOn(uint8_t led){
    return *puerto & LedToMask(led);
}