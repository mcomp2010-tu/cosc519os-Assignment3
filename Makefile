CC = gcc
FILES = process1.c
OUT_EXE = process1

build: $(FILES)
	mkdir build
	$(CC) -o build/$(OUT_EXE) $(FILES)

clean:
	rm -f *.o
	rm -rf build

rebuild: clean build
