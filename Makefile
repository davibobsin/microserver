OBJS = main.o
OBJS += response.o
OBJS += request.o

FLAGS = -I.
FLAGS = -Wall

all: server

clean:
	@rm -rf *.o
	@rm -rf server

server: $(OBJS)
	gcc -o $@ $^

%.o: %.c
	gcc $(FLAGS) -c $< -o $@
