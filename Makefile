CFLAGS = -Iinclude -Ic_shaders
LDFLAGS = -Llib -lglfw3 -lopengl32 -lgdi32
FILES = *.c core/*.c scenes/*.c

all:
	rm -rf c_shaders
	mkdir -p c_shaders
	node utils/shader-compiler.js -o c_shaders shaders

	rm -rf release
	mkdir -p release
	gcc $(CFLAGS) -o release/main.exe $(FILES) $(LDFLAGS)

run:
	./release/main.exe