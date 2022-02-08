/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-ShapeShifter.h"
#include "./se-dvorak.h"


static const kaleidoscope::plugin::ShapeShifter::dictionary_t shape_shift_dictionary[] PROGMEM = {
 {Key_se_Quote, Key_2},
 {Key_NoKey, Key_NoKey},
};


#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_VERSION_INFO
};

enum {
  DVORAK,
  SYMBOLS,
  NUMPAD_LANG
};

/* *INDENT-OFF* */
KEYMAPS(
  [DVORAK] = KEYMAP_STACKED
  (
       Key_se_Tab    ,Key_Comma       ,Key_Period    ,Key_P                     ,Key_Y
      ,Key_A         ,Key_O          ,Key_E         ,Key_U                     ,Key_I
      ,Key_se_Quote  ,Key_Q          ,Key_J         ,Key_K                     ,Key_X         ,Key_se_UpArrow
      ,Key_Esc       ,Key_se_LeftGui ,Key_LeftShift ,ShiftToLayer(NUMPAD_LANG) ,Key_Backspace ,Key_LeftAlt

                         ,Key_F     ,Key_G                 ,Key_C          ,Key_R        ,Key_L
                         ,Key_D     ,Key_H                 ,Key_T          ,Key_N        ,Key_S
       ,Key_se_DownArrow ,Key_B     ,Key_M                 ,Key_W          ,Key_V        ,Key_Z
       ,Key_LeftControl  ,Key_Space ,ShiftToLayer(SYMBOLS) ,Key_RightShift ,Key_se_Minus ,Key_Enter
  ),

  [SYMBOLS] = KEYMAP_STACKED
  (
       Key_se_Caret            ,Key_se_Dollar            ,Key_se_LeftBracket ,Key_se_RightBracket ,Key_se_Pipe
      ,Key_se_LeftCurlyBracket ,Key_se_RightCurlyBracket ,Key_se_LeftParen   ,Key_se_RightParen   ,Key_se_Slash
      ,Key_se_Backtick         ,Key_se_Percent           ,Key_se_LessThan    ,Key_se_GreaterThan  ,Key_se_Star ,Key_se_LeftArrow
      ,___                     ,___                      ,___                ,___                 ,___         ,___

                          ,Key_se_Plus  ,Key_se_Exclamation ,Key_se_And ,Key_se_Equals ,Key_se_Question
                          ,Key_se_Tilde ,Key_se_Hash        ,Key_se_At  ,___           ,___
      ,Key_se_RightArrow  ,___          ,Key_se_Backslash   ,___ ,___ ,___
      ,___                ,___          ,___                ,___ ,___ ,___
  ),

  [NUMPAD_LANG] = KEYMAP_STACKED
  (
       ___          ,___         ,___          ,___ ,___
      ,Key_se_Aring ,Key_se_Auml ,Key_se_Ouml  ,___ ,___
      ,___          ,___         ,___          ,___ ,___ , Key_se_PageUp
      ,___          ,___         ,___          ,___ ,___ ,___

                       ,___ ,Key_se_7      ,Key_se_8 ,Key_se_9 ,___
                       ,___ ,Key_se_4      ,Key_se_5 ,Key_se_6 ,___
      ,Key_se_PageDown ,___ ,Key_se_1      ,Key_se_2 ,Key_se_3 ,___
      ,___             ,___ ,Key_LeftShift ,Key_se_0 ,___      ,___
   )

)


/*
  [UPPER] = KEYMAP_STACKED
  (
       Key_Insert            ,Key_Home                 ,Key_UpArrow   ,Key_End        ,Key_PageUp
      ,Key_Delete            ,Key_LeftArrow            ,Key_DownArrow ,Key_RightArrow ,Key_PageDown
      ,M(MACRO_VERSION_INFO) ,Consumer_VolumeIncrement ,XXX           ,XXX            ,___ ,___
      ,MoveToLayer(QWERTY)   ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,___      ,___           ,MoveToLayer(QWERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   )
)
*/

/*
  [XYZ] = KEYMAP_STACKED
  (
       ___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___ ,___

           ,___ ,___ ,___ ,___ ,___
           ,___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___ ,___
   )
*/
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  Macros,
  ShapeShifter
);

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (keyToggledOn(event.state)) {
    switch (macro_id) {
    case MACRO_VERSION_INFO:
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
      break;
    default:
      break;
    }
  }
  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  ShapeShifter.dictionary = shape_shift_dictionary;
}

void loop() {
  Kaleidoscope.loop();
}
