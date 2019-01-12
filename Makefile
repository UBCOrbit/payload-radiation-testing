# CFLAGS=-I ./src/
debug ?= yes

ifeq ($(debug),yes)
    suffix := .debug
else
    ifeq ($(debug),no)
        CFLAGS += -O3
        suffix := .opt
    else
        $(error debug should be either yes or no)
    endif
endif

sources := $(sort $(wildcard *.c))
objects := $(addprefix ., $(sources:.c=$(suffix).o))
deps := $(addprefix ., $(sources:.c=$(suffix).d))

all : rad_tests

rad_tests : rad_tests$(suffix)
	ln -sf $< $@

rad_tests$(suffix) : $(objects)
	$(CC) $(CFLAGS) $(objects) -o $@

-include $(deps)

.%$(suffix).o : %.c
	$(CC) $(CFLAGS) -MD -MP -MF $(addprefix ., $(<:.c=$(suffix).d)) -c -o $@ $<
