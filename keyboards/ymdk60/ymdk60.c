#include "ymdk60.h"


extern inline void caps_led_on(void);
extern inline void bl_led_on(void);
extern inline void rgb_led_on(void);

extern inline void caps_led_off(void);
extern inline void bl_led_off(void);
extern inline void rgb_led_off(void);


void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
	    caps_led_on();
	} else {
	    caps_led_off();
  }

   if (usb_led & (1<<USB_LED_NUM_LOCK)) {
	 } else {
   }

   if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
	 } else {
   }

	led_set_user(usb_led);
}
