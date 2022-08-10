#include <stdint.h>
#include <stdbool.h>

void LedsCreate(uint16_t * address);
void LedsSingleTurnOn(uint8_t led);
void LedsSingleTurnOff(uint8_t led);
void LedsAllTurnOn(void);
void LedsAllTurnOff(void);
bool IsLedOn(uint8_t led);