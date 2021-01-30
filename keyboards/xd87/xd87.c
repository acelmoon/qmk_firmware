/* Copyright 2018 Alexander Fougner <fougner89 at gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd87.h"
#include "led.h"

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up
  led_init_ports();
  matrix_init_user();
  led_init_ports();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware
  
  return process_record_user(keycode, record);
}

<<<<<<< HEAD
void led_init_ports(void) {
    // * Set our LED pins as output
    DDRE |= (1<<2);
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        //register_code(KC_C); //to test if this actually gets executed (it doesnt)
        PORTE &= ~(1 << 2);
    } else {
        //register_code(KC_O); //to test if this actually gets executed (it doesnt)
        PORTE |= (1 << 2);
    }
  led_set_user(usb_led);
=======
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if (res) {
        writePin(E2, !led_state.caps_lock);
    }

    return res;
>>>>>>> 1b960381153f69b7b0ed28db51248f674ce0fadb
}

void led_init_ports(void) {
  setPinOutput(E2);
}
