#ifndef _KEYS_
#define _KEYS_

typedef struct Keys {
    int key_up;
    int key_right;
    int key_down;
    int key_left;
} Keys;

typedef enum {
    //clavier azerty = clavier qwerty
    R_TYPE_KEY_A = KEY_Q,
    R_TYPE_KEY_B = KEY_B,
    R_TYPE_KEY_C = KEY_C,
    R_TYPE_KEY_D = KEY_D,
    R_TYPE_KEY_E = KEY_E,
    R_TYPE_KEY_F = KEY_F,
    R_TYPE_KEY_G = KEY_G,
    R_TYPE_KEY_H = KEY_H,
    R_TYPE_KEY_I = KEY_I,
    R_TYPE_KEY_J = KEY_J,
    R_TYPE_KEY_K = KEY_K,
    R_TYPE_KEY_L = KEY_L,
    // R_TYPE_KEY_M = KEY_,
    R_TYPE_KEY_N = KEY_N,
    R_TYPE_KEY_O = KEY_O,
    R_TYPE_KEY_P = KEY_P,
    R_TYPE_KEY_Q = KEY_A,
    R_TYPE_KEY_R = KEY_R,
    R_TYPE_KEY_S = KEY_S,
    R_TYPE_KEY_T = KEY_T,
    R_TYPE_KEY_U = KEY_U,
    R_TYPE_KEY_V = KEY_V,
    R_TYPE_KEY_W = KEY_Z,
    R_TYPE_KEY_X = KEY_X,
    R_TYPE_KEY_Y = KEY_Y,
    R_TYPE_KEY_Z = KEY_W,
    R_TYPE_UP = KEY_UP,
    R_TYPE_DOWN = KEY_DOWN,
    R_TYPE_RIGHT = KEY_RIGHT,
    R_TYPE_LEFT = KEY_LEFT,
    R_TYPE_ENTER = KEY_ENTER,
    R_TYPE_MOUSE_LEFT = MOUSE_BUTTON_LEFT,

} rTypeKeyboardKey;

#endif