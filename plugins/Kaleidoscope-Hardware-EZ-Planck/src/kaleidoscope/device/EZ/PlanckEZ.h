/* -*- mode: c++ -*-
 * Kaleidoscope - Firmware for computer input devices
 * Copyright (C) 2021  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#pragma once

#ifdef ARDUINO_GENERIC_F303CCTX

#include "kaleidoscope/driver/keyscanner/None.h"
#include "kaleidoscope/driver/hid/USBHID.h"
#include "kaleidoscope/driver/hid/Base.h"
#include "kaleidoscope/device/Base.h"

namespace kaleidoscope {
namespace device {
namespace ez {

struct PlanckEZProps : kaleidoscope::device::BaseProps {
  typedef kaleidoscope::driver::keyscanner::None KeyScanner;
#if 0
  typedef kaleidoscope::driver::hid::USBHIDProps HIDProps;
  typedef kaleidoscope::driver::hid::USBHID<HIDProps> HID;
#else
  typedef kaleidoscope::driver::hid::BaseProps HIDProps;
  typedef kaleidoscope::driver::hid::Base<HIDProps> HID;
#endif
  static constexpr const char *short_name = "planck-ez";
};

class PlanckEZ: public kaleidoscope::device::Base<PlanckEZProps> {
 public:
  auto serialPort() -> decltype(Serial) & {
    return Serial;
  }
};

}
}

typedef kaleidoscope::device::ez::PlanckEZ Device;

}

#endif
