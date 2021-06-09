#! /bin/bash
set -e

arduino-cli -v compile --libraries $(pwd)/../../../../plugins .

echo "Reset the device, and press enter..."
read a

dfu-util -d 0483:DF11 -a 0 -s 0x08000000:leave -D build/*/*.bin
