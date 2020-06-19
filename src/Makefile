CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Werror -Wconversion
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CCEXTRAFLAGS 		:= -Wformat=2 -Wformat-truncation=2 -Wshadow -Wdouble-promotion -pedantic-errors -Wundef
CCNO_TENTATIVE_VARIABLES_IE_VARIABLES_FORCED_SHARE_MEM := -fno-common 
CCtldr			    := $(CCNO_TENTATIVE_VARIABLES_IE_VARIABLES_FORCED_SHARE_MEM) 
CC_FIX_ENUM_WIDTH	:= -fno-short-enums

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CCFLAGSX  := $(CFLAGS) $(CCEXTRAFLAGS)
CCXTRA   := $(CFLAGS) $(CCEXTRAFLAGS) $(CCtldr) $(CC_FIX_ENUM_WIDTH)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DEBUG 	:= -g -nostdlib

TARGET 	:= my_cal
SRC 	:= $(wildcard *.c)
OBJ 	:= $(SRC:.c = .o)
DEP 	:= $(OBJ:.o = .d)
IDIR	:= ../include
INC		:= -I$(IDIR)

all: $(TARGET) $(OBJ)


$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CCXTRA) $(INC)

debug: $(TARGET)
	$(CC) -o $(TARGET)_$@ $^ $(CFLAGS) $(DEBUG) $(INC)


.PHONY: clean
clean:
	rm -f $(wildcard *.o) $(wildcard *.exe*)
