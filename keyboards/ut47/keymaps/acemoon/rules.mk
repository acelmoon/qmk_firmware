# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no        # Console for debug(+400)
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
UNICODE_ENABLE = yes         # Unicode
TAP_DANCE_ENABLE = yes  	# Enable Tap Dance (+~1000)

MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches

RGBLIGHT_ENABLE = no        # Enable keyboard underglow functionality (+4870)
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
LED_ENABLE = yes


#COMMAND_ENABLE = yes        # Commands for debug and configuration
#UNICODE_ENABLE = no         # Unicode