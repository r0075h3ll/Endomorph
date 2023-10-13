CFLAGS=-Wall -g

endomorph: main.o
		   cc -o endomorph main.o
		   rm main.o
		   cp endomorph ~/.local/bin
		   mv endomorph bin/

main.o: src/main.c
		cc -c src/main.c

clean:
		rm ~/.local/bin/endomorph 
