CC = gcc
CFLAGS = -std=c11 -Wall
LDFLAGS = -lpng

c_files = $(wildcard *.c)
o_files = $(c_files:%.c=%.o)

all: $(o_files)
	$(CC) $< -o $@ $(LDFLAGS)


$(o_files) : $(c_files)
#$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf main all *.o