CC := gcc -Wall
BIN := liblinked.so
SRC := linked_list.c
INCL := linked_list.h linked_defs.h

LIB_DIR := /usr/local/lib
INCL_DIR := /usr/local/include

.PHONY: all
all: clean
	$(CC) $(SRC) -shared -fPIC -o $(BIN)

.PHONY: clean
clean:
	rm -f $(BIN)

.PHONY: install
install:
	install -D -m 755 $(INCL) $(INCL_DIR)
	install -D -m 755 $(BIN) $(LIB_DIR)

.PHONY: uninstall
uninstall:
	rm -f $(LIB_DIR)/$(BIN)
	for file in $(INCL); do \
		rm -f $(INCL_DIR)/$$file; \
	done