CFLAGS = -Wall -Wextra
OBJS = help.o wfile.o wmain.o 


all: ws

ws: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ws

 
