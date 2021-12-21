/* Copyright 2021 Kyrylo Mikos <kiril.mik.os@gmail.com>
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
#include QMK_KEYBOARD_H
#include "./rgb.h"

#define RGB_DIM_AFTER_LAYER 1

typedef struct {
    uint8_t led_index;
    RGB color;
} single_rgb_config;

const single_rgb_config NULL_LED = { 255 };

void apply_layer(const single_rgb_config leds[]) {
    for (uint8_t i = 0; leds[i].led_index != NULL_LED.led_index; i++) {
        rgb_matrix_set_color(leds[i].led_index, leds[i].color.r, leds[i].color.g, leds[i].color.b);
    }
}

const single_rgb_config layer0[] = { NULL_LED };
const single_rgb_config layer1[] = { {LED_FN, {0, 255, 0} }, NULL_LED };
const single_rgb_config layer2[] = { {LED_HOME, {0, 255, 0} }, {LED_1, {0, 255, 0} }, {LED_2, {0, 255, 0} }, NULL_LED };
const single_rgb_config layer3[] = { {LED_PGUP, {0, 255, 0} }, {LED_V, {0, 255, 0} }, NULL_LED };
const single_rgb_config layer4[] = {
    {LED_PGDN, {0, 255, 0} }, {LED_6, {0, 255, 0} }, {LED_7, {0, 0, 255} },
    {LED_LCMD, {0, 255, 0} }, {9, {255, 0, 0} }, {LED_1, {0, 0, 255} },
    {LED_EQL, {0, 0, 255}}, {LED_V, {255, 0, 0}}, {LED_F, {255, 0, 0}},
    {LED_M, {255, 0, 0}}, {LED_P, {255, 0, 0}}, {LED_E, {0, 0, 255}},
    NULL_LED
};

const single_rgb_config *led_layers[] = (const single_rgb_config*[]){
    layer0,
    layer1,
    layer2,
    layer3,
    layer4,
    NULL // Null terminate the array
};
void rgb_matrix_indicators_user() {
#ifdef RGB_MATRIX_DIM
    bool otherLayerApplied = false;
#endif

    for (int i = 0; led_layers[i] != NULL; i++) {
        if (layer_state_is(i)) {
            apply_layer(led_layers[i]);
#ifdef RGB_MATRIX_DIM
            if (i > RGB_DIM_AFTER_LAYER) {
                otherLayerApplied = true;
            }
#endif
        }
    }

#ifdef RGB_MATRIX_DIM
    if (otherLayerApplied) {
        rgb_matrix_dim_temporary();
    } else {
        rgb_matrix_reset_dim();
    }
#endif
}
