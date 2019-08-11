# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes	# Mouse keys(+4700)
EXTRAKEY_ENABLE = yes	# Audio control and System control(+450)
CONSOLE_ENABLE = no 	# Console for debug(+400)
COMMAND_ENABLE = no     # Commands for debug and configuration
TAP_DANCE_ENABLE = yes  # Enable Tap Dance (+~1000)
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE  = yes   # Unicode

#BACKLIGHT_ENABLE = yes  # Enable keyboard backlight functionality (+1150)
#RGBLIGHT_ENABLE = yes   # Enable keyboard underglow functionality (+4870)
AUDIO_ENABLE = no       # Audio output on port ??
MIDI_ENABLE      = no   # MIDI controls
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
BLUETOOTH_ENABLE = no   # Enable Bluetooth with the Adafruit EZ-Key HID

SRC += acemoon.c

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif