CC = gcc
CFLAGS = -g -Wall

LD = gcc
LDFLAGS =
TEST_LDFLAGS =

AR = ar
ARFLAGS = rcs

PKG_CONFIG = $(shell which pkg-config)
ifneq ($(PKG_CONFIG), "")
CFLAGS += $(shell $(PKG_CONFIG) --cflags check)
TEST_LDFLAGS += $(shell $(PKG_CONFIG) --libs check)
endif

VALGRIND = $(shell which valgrind)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@ -MMD

%_test.exe : %_test.o %.o
	$(LD) $(LDFLAGS) $^ $(TEST_LDFLAGS) -o $@

.PRECIOUS: %.o
