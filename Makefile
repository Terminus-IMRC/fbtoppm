PROG=fbtoppm
SRCS=fbtoppm.c
OBJS=$(SRCS:%.c=%.c.o)
ALLDEP=$(MAKEFILE_LIST)

all: $(PROG)

$(PROG): $(OBJS) $(ALLDEP)
	$(LINK.o) $(OUTPUT_OPTION) $(OBJS)

%.c.o: %.c $(ALLDEP)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJS)
