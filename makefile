##########################################
## GLOBAL

TARGET 	:= dynamic
CC		:= gcc

# Flags
CFLAGS 	:= -g3 -rdynamic
INCS	?= -I./src/
LIBS	?= -lpthread -lm -lcurl
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

# Use all avaliable processors to build the project
.PHONY: all multi
multi:
	$(MAKE) -j$(CPU_COUNT) all

.PHONY: dev
dev: clean multi run

all: $(BUILD)/$(TARGET)

##########################################
## Rules

lib: $(OBJS) $(HEAD)
	ar rcs $(BUILD)/lib$(TARGET).a $(filter-out build/./src/main.c.o, $(OBJS))

# excecutiable
$(BUILD)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(INCS) $(LIBS) $(LDFLAGS) $(CFLAGS) -fsanitize=address

# c++ source
$(BUILD)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) -c -fPIC $< -o $@ $(INCS) $(LIBS) $(CFLAGS)

# c++ source
$(BUILD)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c -fPIC $< -o $@ $(INCS) $(LIBS) $(CFLAGS)

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
	valgrind --undef-value-errors=no --leak-check=full $(BUILD)/$(TARGET)

.PHONY: gdb
gdb:
	gdb $(BUILD)/$(TARGET)

.PHONY: clean
clean:
	rm -r $(BUILD)
