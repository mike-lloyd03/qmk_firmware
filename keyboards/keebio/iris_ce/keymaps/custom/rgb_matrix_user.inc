RGB_MATRIX_EFFECT(SOLID_REACTIVE_WHITE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static hsv_t SOLID_REACTIVE_WHITE_math(hsv_t hsv, uint16_t offset) {
    //if (offset > 255) offset = 255;
    //hsv.h += scale8(255 - offset, 64);
    uint8_t shift = (uint8_t)offset;
    hsv.s += scale8(shift < 128 ? shift * 2 : (255 - shift) * 2, 64);

    return hsv;
}

bool SOLID_REACTIVE_WHITE(effect_params_t* params) {
    return effect_runner_reactive(params, &SOLID_REACTIVE_WHITE_math);
}
#endif
