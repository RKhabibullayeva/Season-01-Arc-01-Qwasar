CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SOURCES = my_printf.c
TARGET = my_printf

$(TARGET):$(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^
.PHONY: fclean
fclean:    
	@rm -r $(TARGET)