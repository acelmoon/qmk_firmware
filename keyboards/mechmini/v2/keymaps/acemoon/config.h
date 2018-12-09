/* key matrix pins */
#undef UNUSED_PINS
#define UNUSED_PINS {B2, B4, B5, C0, C1, C2, C3, C4, C5, C6, D4, D6, D7, E0, E1, E3, E4, E5, E6, E7, F2, F3}

/* number of backlight levels */
#ifdef BACKLIGHT_PIN
#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 4
#endif
