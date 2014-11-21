quicksort_test.bin: quicksort_test.c quicksort.o quicksort.h
	gcc -I ./ quicksort_test.c quicksort.o -o quicksort_test.bin

quicksort.o: quicksort.c quicksort.h
	gcc -I ./ -c quicksort.c


