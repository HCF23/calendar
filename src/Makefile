CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Werror -Wconversion
DEBUG 	:= -g -nostdlib

TARGET 	:= my_cal
SRC 	:= $(wildcard *.c)
OBJ 	:= $(SRC:.c = .o)
DEP 	:= $(OBJ:.o = .d)
IDIR	:= ../include
INC		:= -I$(IDIR)

all: $(TARGET) $(OBJ)


$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(INC)

debug: $(TARGET)
	$(CC) -o $(TARGET)_$@ $^ $(CFLAGS) $(DEBUG) $(INC)


.PHONY: clean
clean:
	rm -f $(wildcard *.o) $(wildcard *.exe*)
