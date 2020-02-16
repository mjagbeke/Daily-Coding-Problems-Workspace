
SRCDIR   := src/
LIBDIR	 := ../../../C/Library
OBJDIR   := obj/
BINDIR   := bin/
NAME     := DCP_1
C_NAMES  := DCP_1.c 
L_Names := customStringUtil.c customStringUtil.h
EXE      := $(BINDIR)$(NAME)
all: exe

# Everything below this point is generic and could be put into a common 
# make include file to be included in other makefiles.

SFILES   := c
OFILES   := o
AFILES   := a
HFILES   := h
CC       := gcc
CFLAGS   := -c -ansi -pedantic -Wall

SOURCES := $(foreach sname, $(C_NAMES), $(SRCDIR)$(sname))
LIBSOURCES := $(foreach sname, $(L_NAMES), $(LIBDIR)$(sname))
OBJECTS := $(patsubst $(SRCDIR)%.$(SFILES), $(OBJDIR)%.$(OFILES), $(SOURCES))
LIBRARIES:= $(patsubst $(LIBDIR)%.$(AFILES), $(lIBDIR)%.$(SFILES), $(lIBDIR)%.$(HFILES))
ALLFILES := $(SOURCES)

.PHONY: all clean exe

exe:    $(EXE)

$(EXE): $(OBJECTS)
	        @echo 'Building exe: $<'
	        $(CC) $^ -o $@
			#gcc 	
$(OBJDIR)%$(OFILES):    $(SRCDIR)%$(SFILES)
	        @echo 'Building object file: $<'
	        $(CC) $(CFLAGS) $< -o $@

$(lIBDIR)%$(AFILES):    $(SRCDIR)%$(SFILES)
			@echo 'Building Library file: $<'
	        $(CC) $(CFLAGS) $< a $@

clean:
	        rm -f $(OBJECTS) $(EXE)

	        