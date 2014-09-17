all:
	gcc gauss_partial_pivot.c -o gauss -lm -O2 -mtune=native -march=native

clean:
	-rm -rfv main core gauss
