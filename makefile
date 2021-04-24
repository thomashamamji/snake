all : COMPILATION EXECUTION

COMPILATION : main.c draw.c input.c init.c text.c
	gcc -o exec main.c draw.c input.c init.c text.c -lSDL2 -lSDL2_image

EXECUTION : exec
	./exec