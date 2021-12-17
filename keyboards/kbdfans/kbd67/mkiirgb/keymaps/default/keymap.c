#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5

enum custom_keycodes {
    MIK_RENAME = SAFE_RANGE,
    MIK_FIND,
	MIK_CS, // change signature
	MIK_BUILD,
	MIK_SI, // select in
	MIK_FS, // file structure
	MIK_EV, // extract variable
	MIK_EF, // extract field
    MIK_EM, // extract method
    MIK_EP, // extract parameter
    MIK_PST, // Pase plain in Teams
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi_blocker( /* Base */
			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_GRAVE,
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, MO(3),
			KC_F13,        KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    OSL(4),
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     OSL(5),
		    KC_LCTL,       KC_LALT,  KC_LGUI,                KC_SPC,                KC_RALT,           MO(1),    KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[_LAYER1] = LAYOUT_65_ansi_blocker(
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,
		    KC_TRNS,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK,  KC_PAUS, RESET,    KC_PGUP,
			KC_TRNS,       RGB_SPI,  RGB_SPD, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_PGDN,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_VOLU,  KC_MUTE,
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_MPRV,          KC_VOLD,  KC_MNXT),
		[_LAYER2] = LAYOUT_65_ansi_blocker(
			KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
			KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),
		[_LAYER3] = LAYOUT_65_ansi_blocker(
			KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
			KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),
		[_LAYER4] = LAYOUT_65_ansi_blocker(
			KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
			KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  TG(4),
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,MIK_PST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),
		[_LAYER5] = LAYOUT_65_ansi_blocker(
			KC_TRNS,       MIK_SI,   KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, MIK_RENAME, MIK_FIND, KC_TRNS, MIK_BUILD, KC_TRNS,  KC_TRNS, MIK_FS,  KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,   MIK_EP,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
			KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,MIK_EF,  KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,
		    KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,MIK_EV,  KC_TRNS, KC_TRNS,    MIK_EM,   KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,          KC_TRNS,  TG(5),
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MIK_RENAME: //exsel is the last one before the modifier keys
      if (record->event.pressed) {
		if (get_mods() & MOD_MASK_GUI) {
			tap_code(KC_F6);
		} else {
			register_code(KC_LSHIFT);
			tap_code(KC_F6);
			unregister_code(KC_LSHIFT);
		}
        return false;
      }
      break;
	case MIK_FIND: //exsel is the last one before the modifier keys
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_F7);
        unregister_code(KC_LALT);
        return false;
      }
      break;
	case MIK_BUILD:
	  if (record->event.pressed) {
		  register_code(KC_LGUI);
		  tap_code(KC_F9);
		  unregister_code(KC_LGUI);
		  return false;
	  }
	  break;
	case MIK_SI:
	  if (record->event.pressed) {
		  register_code(KC_LALT);
		  tap_code(KC_F1);
		  unregister_code(KC_LALT);
		  return false;
	  }
	  break;
	case MIK_FS:
	  if (record->event.pressed) {
		  register_code(KC_LGUI);
		  tap_code(KC_F12);
		  unregister_code(KC_LGUI);
		  return false;
	  }
	case MIK_EV:
	  if (record->event.pressed) {
		  register_code(KC_LGUI);
		  register_code(KC_LALT);
		  tap_code(KC_V);
		  unregister_code(KC_LGUI);
		  unregister_code(KC_LALT);
		  return false;
	  }
	  break;
	case MIK_EF:
	  if (record->event.pressed) {
		  register_code(KC_LGUI);
		  register_code(KC_LALT);
		  tap_code(KC_F);
		  unregister_code(KC_LGUI);
		  unregister_code(KC_LALT);
		  return false;
	  }
	  break;
  case MIK_EM:
	  if (record->event.pressed) {
		  register_code(KC_LGUI);
		  register_code(KC_LALT);
		  tap_code(KC_M);
		  unregister_code(KC_LGUI);
		  unregister_code(KC_LALT);
		  return false;
	  }
	  break;
  case MIK_EP:
	  if (record->event.pressed) {
		  register_code(KC_LGUI);
		  register_code(KC_LALT);
		  tap_code(KC_P);
		  unregister_code(KC_LGUI);
		  unregister_code(KC_LALT);
		  return false;
	  }
	  break;
  case MIK_PST:
    if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        register_code(KC_LSHIFT);
        tap_code(KC_V);
        unregister_code(KC_LGUI);
        unregister_code(KC_LALT);
        unregister_code(KC_LSHIFT);
    }
    break;
  }
  return true;
}
