##########################################
## GLOBAL

MAKEFLAGS += --silent
TARGET 	:= dynamic
CC		:= /usr/bin/gcc
#CC 		:= /usr/bin/x86_64-w64-mingw32-gcc

# Flags
INCS	?= -I./src/ -I/usr/include/
INCS	+= -L/usr/lib/
#INCS 	?= -I./src -I/usr/x86_64-w64-mingw32/include/
#INCS	+= -L/usr/x86_64-w64-mingw32/lib/
LIBS	?= -lpthread -lm
MKF_DIR	:= $(abspath $(lastword $(MAKEFILE_LIST)))
CUR_DIR	:= $(MKF_DIR:makefile=)

# Build
BUILD := build
OBJS  :=
OBJS  += $(patsubst %.c,$(BUILD)/%.c.o, $(shell find ./src -name "*.c"))
OBJS  += $(patsubst %.cpp,$(BUILD)/%.cpp.o, $(shell find ./src -name "*.cpp"))
OBJS  += $(patsubst %.cu,$(BUILD)/%.cu.o, $(shell find ./src -name "*.cu"))
HEAD  := $(patsubst %.h,$(BUILD)/inc/%.h, $(shell find ./src -name "*.h" ! -name "*.internal.h"))

##########################################
## Processes

CPU_COUNT=$(shell grep -c "^processor" /proc/cpuinfo)

##########################################
## Rules
all-dbg: CFLAGS += -DDEBUG -g
all-dbg: $(BUILD)/$(TARGET)-dbg
all-rel: $(BUILD)/$(TARGET)-rel

win-dbg: CC   = /usr/bin/x86_64-w64-mingw32-gcc
win-dbg: INCS = -I./src -I/usr/x86_64-w64-mingw32/include/ -L/usr/x86_64-w64-mingw32/lib/
win-dbg:
	$(MAKE) clean; $(MAKE) -j$(CPU_COUNT) $(BUILD)/$(TARGET)-dbg

rel:
	$(MAKE) clean; $(MAKE) -j$(CPU_COUNT) all-rel > $(TARGET).log; mv $(TARGET).log ./build/; $(MAKE) run
dbg:
	$(MAKE) clean; $(MAKE) -j$(CPU_COUNT) all-dbg > $(TARGET).log; mv $(TARGET).log ./build/; $(MAKE) run

# library
lib: $(OBJS) $(HEAD)
	ar rcs $(BUILD)/lib$(TARGET).a $(filter-out build/./src/main.c.o, $(OBJS))

# debug excecutiable
$(BUILD)/$(TARGET)-dbg: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BUILD)/$(TARGET) $(INCS) $(LIBS) $(LDFLAGS)

# release excecutiable
$(BUILD)/$(TARGET)-rel: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BUILD)/$(TARGET) $(INCS) $(LIBS) $(LDFLAGS)
	strip $(BUILD)/$(TARGET)

# c++ source
$(BUILD)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) -c -fPIC $< -o $@ $(INCS) $(LIBS) $(CFLAGS)

# c++ source
$(BUILD)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(INCS) $(LIBS) $(CFLAGS)

# Header files for library
$(BUILD)/inc/%.h: %.h
	mkdir -p $(dir $@)
	cp $< $@

##########################################
## Commands

.PHONY: run
run:
	$(BUILD)/$(TARGET)

.PHONY: leak
leak:
	valgrind --leak-check=full --track-origins=yes $(BUILD)/$(TARGET)

.PHONY: log
log:
	bat ./build/$(TARGET).log

.PHONY: gdb
gdb:
	gdb $(BUILD)/$(TARGET)

.PHONY: clean
clean:
	rm -r $(BUILD)
