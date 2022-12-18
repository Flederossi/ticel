ticel:
	gcc src/main.c -o bin/ticel -I src/include -L src/lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2
clean:
	del bin\ticel.exe
run:
	make
	./bin/ticel.exe B2/S1