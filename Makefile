CFLAG = -g -Wall -ansi -pedantic -std=c++17 -ggdb
CLIB = -lsfml-graphics -lsfml-window -lsfml-system

CC = g++
TARGET_EXEC := hexacity

BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

MKDIR_P := mkdir -p

$(TARGET_EXEC): $(OBJS)
	@$(CC) $(OBJS) $(CFLAG) -o $@ $(LDFLAGS) $(CLIB)
	@echo $(TARGET_EXEC) compilation termined

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	@$(MKDIR_P) $(dir $@)
	@echo Compiling $(shell basename $<)
	@$(CC) $(CPPFLAGS) $(CFLAG) $(CPPFLAGS) -c $< -o $@ $(CLIB)


.PHONY: clean

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo Build directory removed