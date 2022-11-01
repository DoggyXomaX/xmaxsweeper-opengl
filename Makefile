all:
	mkdir -p release
	gcc *.c core/*.c graphics/*.c -o release/main.exe

run:
	./release/main.exe