
CC		:= gcc
IDIR 	:= ../include
CCFLAGS	:= -Wall -g -I$(IDIR)

ODIR	:= obj
LDIR	:= ../lib

#LIBS	:=-lm

TARGET	:= cal
SRC 	:= main print

_DEPS	:= main.h calendar_print.h
DEPS	:= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ	:= $(addsuffic .o, $(SRC))
OBJ		:= $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CCFLAGS)


.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJ)


all: $(TARGET) $(OBJ)


$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS) $(LIBS)
