ifndef GBDK_BIN
	GBDK_BIN = ../gbdk/bin
endif

TARGET = speech
CC = $(GBDK_BIN)/lcc
SRC_DIR = src
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/speech.c $(SRC_DIR)/utils.c
ROM = $(BUILD_DIR)/$(TARGET).gb
MAP = $(BUILD_DIR)/$(TARGET).map
SYM = $(BUILD_DIR)/$(TARGET).sym

CFLAGS = -Wa-l -Wl-m -Wl-j

.PHONY: all clean

all: $(ROM)
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
$(ROM): $(SRCS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -rf $(BUILD_DIR)

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/speech.h $(SRC_DIR)/utils.h
$(SRC_DIR)/speech.o: $(SRC_DIR)/speech.c $(SRC_DIR)/speech.h $(SRC_DIR)/utils.h
$(SRC_DIR)/utils.o: $(SRC_DIR)/utils.c $(SRC_DIR)/utils.h
