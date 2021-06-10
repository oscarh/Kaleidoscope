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

#ifdef ADAFRUIT_FEATHER_M4_EXPRESS

#include "kaleidoscope/driver/keyscanner/None.h"
#include "kaleidoscope/device/Base.h"

namespace kaleidoscope {
namespace device {
namespace adafruit {

struct M4FeatherProps : kaleidoscope::device::BaseProps {
  typedef kaleidoscope::driver::keyscanner::None KeyScanner;
  static constexpr const char *short_name = "m4-feather";
};

class M4Feather: public kaleidoscope::device::Base<M4FeatherProps> {
 public:
  auto serialPort() -> decltype(Serial) & {
    return Serial;
  }
};

}
}

typedef kaleidoscope::device::adafruit::M4Feather Device;

}

#endif
