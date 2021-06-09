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

#ifdef USBD_USE_HID_COMPOSITE

#include <Arduino.h>
#include "kaleidoscope/key_defs.h"

#include "kaleidoscope/driver/hid/Base.h"

#include "usbhid/Keyboard.h"
#include "usbhid/MouseWrapper.h"

namespace kaleidoscope {
namespace driver {
namespace hid {

struct USBHIDProps: public BaseProps {
  typedef usbhid::KeyboardProps KeyboardProps;
  typedef usbhid::Keyboard<KeyboardProps> Keyboard;
  typedef usbhid::MouseProps MouseProps;
  typedef usbhid::Mouse<MouseProps> Mouse;
};

template <typename _Props>
class USBHID: public Base<_Props> {};

}
}
}

#endif
