#include QMK_KEYBOARD_H

#define _BASEL 0
#define _ALTERL 1

enum custom_keycodes { EMACS = SAFE_RANGE, CHROME, SPOTIFY, NAUTILUS, FIREFOX, VSCODE, DBEAVER, HIBERNATE, LOCK, ANNON_FUNC };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASEL] = LAYOUT_ortho_4x4(LOCK, KC_NO, KC_NO, MO(_ALTERL)
                                , KC_HOME, HIBERNATE, KC_VOLD, KC_VOLU
                                , KC_DEL, KC_UP, KC_BSPC, KC_END
                                , KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT
                                )
    ,[_ALTERL] = LAYOUT_ortho_4x4(HIBERNATE, LOCK, KC_VOLU, KC_VOLD
                              , FIREFOX, VSCODE, ANNON_FUNC, KC_SLSH
                              , CHROME, SPOTIFY, NAUTILUS, DBEAVER
                              , EMACS, KC_HOME, KC_END, KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMACS:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("s"));
            }
            return false;
            break;
        case DBEAVER:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("d"));
        }
        return false;
        break;
        case VSCODE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("v"));
            }
            return false;
            break;
        case CHROME:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("c"));
            }
            return false;
            break;
        case FIREFOX:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("f"));
            }
            return false;
            break;
        case SPOTIFY:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("m"));
            }
            return false;
            break;
        case NAUTILUS:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("n"));
            }
            return false;
            break;
        case HIBERNATE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("h"));
            }
            return false;
            break;
        case LOCK:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("l"));
            }
            return false;
            break;
        case ANNON_FUNC:
            if (record->event.pressed) {
                SEND_STRING("() => {}");
            }
            return false;
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
#    include "encoder.h"
void encoder_update_user(int8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
#endif
