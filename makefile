matrix: main.c matrix.c
	gcc -o matrix main.c matrix.c
	
clean:
	rm -f matrix
