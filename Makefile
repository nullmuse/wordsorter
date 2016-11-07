CFLAGS = -Wall -Wextra -pedantic
OBJS = help.o wlib.o sortlib.o wfile.o wmain.o 


all: ws

ws: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ws

 
