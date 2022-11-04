CFLAGS = -O3 -Iinclude
LDFLAGS = -Llib -lglfw3 -lopengl32 -lgdi32
FILES = *.c core/*.c scenes/*.c

all:
	mkdir -p release
	gcc $(CFLAGS) -o release/main.exe $(FILES) $(LDFLAGS)

run:
	./release/main.exe