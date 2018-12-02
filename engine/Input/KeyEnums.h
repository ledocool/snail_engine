/*
 * Copyright 2018 LedoCool.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* 
 * File:   keysEnums.h
 * Author: LedoCool
 *
 * Created on August 14, 2018, 10:54 PM
 */

#ifndef KEYSENUMS_H
#define KEYSENUMS_H

#include "SDL.h"

namespace Key 
{

    enum en 
    {
        KEY_UNKNOWN = SDLK_UNKNOWN,
        //KEY_FIRST		= SDLK_FIRST,
        KEY_BACKSPACE = SDLK_BACKSPACE,
        KEY_TAB = SDLK_TAB,
        KEY_CLEAR = SDLK_CLEAR,
        KEY_RETURN = SDLK_RETURN,
        KEY_PAUSE = SDLK_PAUSE,
        KEY_ESCAPE = SDLK_ESCAPE,
        KEY_SPACE = SDLK_SPACE,
        KEY_EXCLAIM = SDLK_EXCLAIM,
        KEY_QUOTEDBL = SDLK_QUOTEDBL,
        KEY_HASH = SDLK_HASH,
        KEY_DOLLAR = SDLK_DOLLAR,
        KEY_AMPERSAND = SDLK_AMPERSAND,
        KEY_QUOTE = SDLK_QUOTE,
        KEY_LEFTPAREN = SDLK_LEFTPAREN,
        KEY_RIGHTPAREN = SDLK_RIGHTPAREN,
        KEY_ASTERISK = SDLK_ASTERISK,
        KEY_PLUS = SDLK_PLUS,
        KEY_COMMA = SDLK_COMMA,
        KEY_MINUS = SDLK_MINUS,
        KEY_PERIOD = SDLK_PERIOD,
        KEY_SLASH = SDLK_SLASH,
        KEY_0 = SDLK_0,
        KEY_1 = SDLK_1,
        KEY_2 = SDLK_2,
        KEY_3 = SDLK_3,
        KEY_4 = SDLK_4,
        KEY_5 = SDLK_5,
        KEY_6 = SDLK_6,
        KEY_7 = SDLK_7,
        KEY_8 = SDLK_8,
        KEY_9 = SDLK_9,
        KEY_COLON = SDLK_COLON,
        KEY_SEMICOLON = SDLK_SEMICOLON,
        KEY_LESS = SDLK_LESS,
        KEY_EQUALS = SDLK_EQUALS,
        KEY_GREATER = SDLK_GREATER,
        KEY_QUESTION = SDLK_QUESTION,
        KEY_AT = SDLK_AT,


        /*
        Skip uppercase letters
         */
        KEY_LEFTBRACKET = SDLK_LEFTBRACKET,
        KEY_BACKSLASH = SDLK_BACKSLASH,
        KEY_RIGHTBRACKET = SDLK_RIGHTBRACKET,
        KEY_CARET = SDLK_CARET,
        KEY_UNDERSCORE = SDLK_UNDERSCORE,
        KEY_BACKQUOTE = SDLK_BACKQUOTE,
        KEY_a = SDLK_a,
        KEY_b = SDLK_b,
        KEY_c = SDLK_c,
        KEY_d = SDLK_d,
        KEY_e = SDLK_e,
        KEY_f = SDLK_f,
        KEY_g = SDLK_g,
        KEY_h = SDLK_h,
        KEY_i = SDLK_i,
        KEY_j = SDLK_j,
        KEY_k = SDLK_k,
        KEY_l = SDLK_l,
        KEY_m = SDLK_m,
        KEY_n = SDLK_n,
        KEY_o = SDLK_o,
        KEY_p = SDLK_p,
        KEY_q = SDLK_q,
        KEY_r = SDLK_r,
        KEY_s = SDLK_s,
        KEY_t = SDLK_t,
        KEY_u = SDLK_u,
        KEY_v = SDLK_v,
        KEY_w = SDLK_w,
        KEY_x = SDLK_x,
        KEY_y = SDLK_y,
        KEY_z = SDLK_z,
        KEY_DELETE = SDLK_DELETE,
        /* End of ASCII mapped keysyms */

        /* Numeric keypad */
        KEY_KP0 = SDLK_KP_0,
        KEY_KP1 = SDLK_KP_1,
        KEY_KP2 = SDLK_KP_2,
        KEY_KP3 = SDLK_KP_3,
        KEY_KP4 = SDLK_KP_4,
        KEY_KP5 = SDLK_KP_5,
        KEY_KP6 = SDLK_KP_6,
        KEY_KP7 = SDLK_KP_7,
        KEY_KP8 = SDLK_KP_8,
        KEY_KP9 = SDLK_KP_9,
        KEY_KP_PEROID = SDLK_KP_PERIOD,
        KEY_KP_DIVIDE = SDLK_KP_DIVIDE,
        KEY_KP_MULTIPLY = SDLK_KP_MULTIPLY,
        KEY_KP_MINUS = SDLK_KP_MINUS,
        KEY_KP_PLUS = SDLK_KP_PLUS,
        KEY_KP_ENTER = SDLK_KP_ENTER,
        KEY_KP_EQUALS = SDLK_KP_EQUALS,

        /* Arrows + Home/End pad */
        KEY_UP = SDLK_UP,
        KEY_DOWN = SDLK_DOWN,
        KEY_RIGHT = SDLK_RIGHT,
        KEY_LEFT = SDLK_LEFT,
        KEY_INSERT = SDLK_INSERT,
        KEY_HOME = SDLK_HOME,
        KEY_END = SDLK_END,
        KEY_PAGEUP = SDLK_PAGEUP,
        KEY_PAGEDOWN = SDLK_PAGEDOWN,

        /* Function keys */
        KEY_F1 = SDLK_F1,
        KEY_F2 = SDLK_F2,
        KEY_F3 = SDLK_F3,
        KEY_F4 = SDLK_F4,
        KEY_F5 = SDLK_F5,
        KEY_F6 = SDLK_F6,
        KEY_F7 = SDLK_F7,
        KEY_F8 = SDLK_F8,
        KEY_F9 = SDLK_F9,
        KEY_F10 = SDLK_F10,
        KEY_F11 = SDLK_F11,
        KEY_F12 = SDLK_F12,
        KEY_F13 = SDLK_F13,
        KEY_F14 = SDLK_F14,
        KEY_F15 = SDLK_F15,

        /* Key state modifier keys */
        KEY_NUMLOCK = SDLK_NUMLOCKCLEAR,
        KEY_CAPSLOCK = SDLK_CAPSLOCK,
        KEY_SCROLLOCK = SDLK_SCROLLLOCK,
        KEY_RSHIFT = SDLK_RSHIFT,
        KEY_LSHFIT = SDLK_LSHIFT,
        KEY_RCTRL = SDLK_RCTRL,
        KEY_LCTRL = SDLK_LCTRL,
        KEY_RALT = SDLK_RALT,
        KEY_LALT = SDLK_LALT,
        KEY_RMETA = SDLK_RGUI,
        KEY_LMETA = SDLK_LGUI,
        //    KEY_LSUPER		= SDLK_LSUPER,		/* Left "Windows" key */
        //    KEY_RSUPER		= SDLK_RSUPER,		/* Right "Windows" key */

        /* Miscellaneous function keys */
        KEY_HELP = SDLK_HELP,
        //    KEY_PRINT		= SDLK_PRINT,
        KEY_SYSREQ = SDLK_SYSREQ,
        //    KEY_BREAK		= SDLK_BREAK,
        KEY_MENU = SDLK_MENU,

    };

}

namespace MouseAction
{
    
    enum en 
    {
        MOUSE_LEFT = SDL_BUTTON_LEFT,
        MOUSE_RIGHT = SDL_BUTTON_RIGHT,
        MOUSE_MIDDLE = SDL_BUTTON_MIDDLE
    };
}

namespace KeyState
{
    enum en
    {
        UP = 0,
        DOWN = 1,
        HELD = 2,
        TOGGLED = 3,
        UNDEFINED
    };
}

#endif /* KEYSENUMS_H */

