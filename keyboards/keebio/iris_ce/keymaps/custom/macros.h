#pragma once

enum custom_keycodes {
    COPY = SAFE_RANGE,
    CUT,
    PASTE,
    WORD_NEXT,
    WORD_PREV,
};

bool handle_macros(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
            return true;

        case CUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("x"));
            }
            return true;

        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
            return true;
    };

    return false;
}
