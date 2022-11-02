CFLAGS = -O3 -Iinclude
LDFLAGS = -Llib -lglfw3 -lopengl32 -lgdi32

all:
	mkdir -p release
	gcc $(CFLAGS) -o release/main.exe *.c core/*.c graphics/*.c $(LDFLAGS)

run:
	./release/main.exe