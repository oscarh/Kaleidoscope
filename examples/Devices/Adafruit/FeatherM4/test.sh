#! /bin/bash
arduino-cli compile --libraries $(pwd)/../../../../plugins .

echo "Reset the device, and press enter..."
read a

~/.arduino15/packages/arduino/tools/bossac/1.8.0-48-gb176eee/bossac -i --port=ttyACM0 -U -i --offset=0x4000 -w -v build/*/*.bin -R
