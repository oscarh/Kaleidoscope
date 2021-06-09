// -*- mode: c++ -*-
/* Kaleidoscope - Firmware for computer input devices
 * Copyright (C) 2021  Keyboard.io, Inc.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <Arduino.h>
#include <Keyboard.h>

#include "kaleidoscope/driver/hid/base/Keyboard.h"

namespace kaleidoscope {
namespace driver {
namespace hid {
namespace usbhid {

/*
 * We are wrapping a few keyboard-related objects here, instead of directly
 * using the classes in `KeyboardProps` below. We do this, because this lets the
 * linker optimize this whole thing out if it is unused. It can do that because
 * instantiating `Keyboard_` & co is in a separate compilation unit.
 *
 * While it would have been cleaner and shorter to instantiate them here, and
 * drop the global objects, that prevents optimizing them out, and that's a cost
 * we do not want to pay.
 */

class BootKeyboardWrapper {
 public:
  BootKeyboardWrapper() {}
  void begin() {
    Keyboard.begin();
  }

  uint8_t getProtocol() {
    return 0;
  }
  void setProtocol(uint8_t protocol) {}
  void setDefaultProtocol(uint8_t protocol) {}

  void sendReport() {
  }

  void press(uint8_t code) {
    Keyboard.press(code);
  }
  void release(uint8_t code) {
    Keyboard.release(code);
  }
  void releaseAll() {
    Keyboard.releaseAll();
  }

  bool isKeyPressed(uint8_t code) {
    return false;
  }
  bool isModifierActive(uint8_t code) {
    return false;
  }
  bool wasModifierActive(uint8_t code) {
    return false;
  }
  bool isAnyModifierActive() {
    return false;
  }
  bool wasAnyModifierActive() {
    return false;
  }

  uint8_t getLeds() {
    return 0;
  }
};

struct KeyboardProps: public base::KeyboardProps {
  typedef BootKeyboardWrapper BootKeyboard;
};

template <typename _Props>
class Keyboard: public base::Keyboard<_Props> {};

}
}
}
}
