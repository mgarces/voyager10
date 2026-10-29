// Voyager10 — ten-key ZSA Voyager companion macropad
// Controller: Seeed XIAO RP2040; direct GPIO wiring with shared GND.
// Host keyboard layout: macOS U.S. (symbol mappings depend on host layout).
//
// Physical positions, viewed from above:
//      [4]  [3]  [2]  [1]
//      [5]            [7]
//           [6]    [8][9][10]

#include QMK_KEYBOARD_H

#define KEY_COLON LSFT(KC_SCLN) // macOS US: :
#define KEY_EURO  LSA(KC_2)    // macOS US: € (Option+Shift+2)
#define KEY_SHOT  HYPR(KC_2)   // configured screenshot shortcut on host

// Backspace and symbols — longest overlapping combo takes precedence.
const uint16_t PROGMEM combo_12[]  = { KC_BSPC, KEY_COLON, COMBO_END };
const uint16_t PROGMEM combo_123[] = { KC_BSPC, KEY_COLON, KEY_SHOT, COMBO_END };
const uint16_t PROGMEM combo_23[]  = { KEY_COLON, KEY_SHOT, COMBO_END };

// Navigation and macOS shortcuts.
const uint16_t PROGMEM combo_left_down[]  = { KC_LEFT, KC_DOWN, COMBO_END };
const uint16_t PROGMEM combo_right_down[] = { KC_RGHT, KC_DOWN, COMBO_END };
const uint16_t PROGMEM combo_up_down[]    = { KC_UP, KC_DOWN, COMBO_END };
const uint16_t PROGMEM combo_left_right[] = { KC_LEFT, KC_RGHT, COMBO_END };

combo_t key_combos[] = {
    COMBO(combo_123, LGUI(KC_BSPC)),       // 1+2+3: Cmd+Backspace
    COMBO(combo_12, LALT(KC_BSPC)),        // 1+2: Option+Backspace
    COMBO(combo_23, KEY_EURO),             // 2+3: € on macOS US
    COMBO(combo_left_down, HYPR(KC_LEFT)), // 8+9: Hyper+Left
    COMBO(combo_right_down, HYPR(KC_RGHT)),// 9+10: Hyper+Right
    COMBO(combo_up_down, LCTL(KC_UP)),     // 7+9: Mission Control
    COMBO(combo_left_right, LCTL(LGUI(KC_Q))) // 8+10: Lock Mac
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_BSPC, KEY_COLON, KEY_SHOT, KC_ESC, // 1, 2, 3, 4
        HYPR(KC_K), HYPR(KC_N),              // 5, 6
        KC_UP, KC_LEFT, KC_DOWN, KC_RGHT     // 7, 8, 9, 10
    )
};

// Hold physical switches 1 and 4 as you connect USB-C to enter bootloader.
// These share matrix row 0 at columns 0 and 3.
bool bootmagic_should_reset(void) {
    const matrix_row_t required = (1u << 0) | (1u << 3);
    return (matrix_get_row(0) & required) == required;
}
