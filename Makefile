all: quicksort_test.bin

quicksort_test.bin: quicksort_test.c quicksort.o binary_search.o quicksort.h binary_search.h sortable.h sort_util.o
	gcc -I ./ quicksort_test.c quicksort.o binary_search.o sort_util.o -o quicksort_test.bin

quicksort.o: quicksort.c quicksort.h sortable.h sort_util.h
	gcc -I ./ -c quicksort.c

binary_search.o: binary_search.c binary_search.h sortable.h sort_util.h
	gcc -I ./ -c binary_search.c

sort_util.o: sort_util.c sort_util.h
	gcc -I ./ -c sort_util.c
