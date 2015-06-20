PROJECT_DIR       = .
ARDMK_DIR         = ../build
ARDUINO_DIR       = /usr/share/arduino
USER_LIB_PATH    :=  ./
BOARD_TAG         = uno
MONITOR_BAUDRATE  = 115200
AVR_TOOLS_DIR     = /usr
AVRDDUDE          = /usr/bin/avrdude
CFLAGS_STD        = -std=gnu11
CXXFLAGS_STD      = -std=gnu++11
CXXFLAGS         += -pedantic -Wall -Wextra
MONITOR_PORT      = /dev/ttyACM0
CURRENT_DIR       = $(shell basename $(CURDIR))
OBJDIR            = /tmp/build/$(BOARD_TAG)/$(CURRENT_DIR)

include $(ARDMK_DIR)/Arduino.mk
