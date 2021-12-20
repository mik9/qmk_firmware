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
const single_rgb_config layer1[] = { {63, {0, 255, 0} }, NULL_LED };
const single_rgb_config layer2[] = { {29, {0, 255, 0} }, NULL_LED };
const single_rgb_config layer3[] = { {43, {0, 255, 0} }, {48, {0, 255, 0} }, NULL_LED };
const single_rgb_config layer4[] = {
    {57, {0, 255, 0} }, {6, {0, 255, 0} }, {7, {0, 0, 255} },
    {60, {0, 255, 0} }, {9, {255, 0, 0} }, {1, {0, 0, 255} },
    {12, {0, 0, 255}}, {48, {255, 0, 0}}, {34, {255, 0, 0}},
    {51, {255, 0, 0}}, {25, {255, 0, 0}}, {18, {0, 0, 255}},
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
