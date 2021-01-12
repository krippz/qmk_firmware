#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base 0
 ,-----------------------,
 |  7  |  8  |  9  |  E4 | Volume / Backspace
 |-----+-----+-----+-----|
 |  4  |  5  |  6  |  E3 | Tracks / PlayPause
 |-----+-----+-----+-----|
 |  1  |  2  |  3  |  E2 | Scroll / -
 |-----+-----+-----+-----|
 |  0  |  =  | Mod |  E1 | - / Enter
 `-----------------------'
*/
	[0] = LAYOUT_ortho_4x4(

	KC_7, KC_8, KC_9, KC_BSPC,
	KC_4, KC_5, KC_6, KC_MPLY,
	KC_1, KC_2, KC_3, KC_NO,
	KC_0, KC_EQL, MO(1), KC_KP_ENTER

	),

/* Mod 1
 ,-----------------------,
 |  &  |  *  |  (  |  E4 | Volume / Backspace
 |-----+-----+-----+-----|
 |  $  |  %  |  ^  |  E3 | Tracks / PlayPause
 |-----+-----+-----+-----|
 |  !  |  @  |  #  |  E2 | Scroll / -
 |-----+-----+-----+-----|
 |  )  |  +  | Mod |  E1 | - / Enter
 `-----------------------'
*/
	[1] = LAYOUT_ortho_4x4(

	KC_AMPR, KC_ASTR, KC_LCBR, KC_NO,
	KC_DLR, KC_PERC, KC_CIRC, KC_NO,
	KC_EXLM, KC_AT, KC_HASH, KC_NO,
	KC_RCBR, KC_PPLS, KC_TRNS, KC_NO

	)
};

void keyboard_post_init_user(void) {
    writePinHigh(LED_RED);
/*
	debug_enable=true;
	debug_matrix=true;
	debug_keyboard=true;
*/
}


void encoder_update_user(uint8_t index, bool clockwise) {
/*
Rev1.1
,-----------------------,
|     |     |     |  E4 |
|-----+-----+-----+-----|
|     |     |     |  E3 |
|-----+-----+-----+-----|
|     |     |     |  E2 |
|-----+-----+-----+-----|
|     |     |     |  E1 |
`-----------------------'
 */
  // First encoder (E1)
  if (index == 0) {
    if (clockwise) {
      tap_code16(C(KC_RGHT));
    } else {
      tap_code16(C(KC_LEFT));
    }
  // Second encoder (E2)
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  // Third encoder (E3)
  } else if (index == 2) {
    if (clockwise) {
      tap_code16(C(KC_Y));
    } else {
      tap_code16(C(KC_Z));
    }
  // Forth encoder (E4)
  } else if (index == 3) {
    if (clockwise) {
      tap_code(KC__VOLDOWN);
    } else {
      tap_code(KC__VOLUP);
    }
  }
}
