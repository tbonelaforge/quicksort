all: quicksort_test.bin disc_intersections.bin

quicksort_test.bin: quicksort_test.c quicksort.o binary_search.o quicksort.h binary_search.h sortable.h sort_util.o
	gcc -I ./ quicksort_test.c quicksort.o binary_search.o sort_util.o -o quicksort_test.bin

disc_intersections.bin: disc_intersections.c quicksort.o binary_search.o quicksort.h binary_search.h sortable.h sort_util.o disc
	gcc -I ./ -I ./disc disc_intersections.c ./disc/disc.o quicksort.o binary_search.o sort_util.o -o disc_intersections.bin

quicksort.o: quicksort.c quicksort.h sortable.h sort_util.h
	gcc -I ./ -c quicksort.c

binary_search.o: binary_search.c binary_search.h sortable.h sort_util.h
	gcc -I ./ -c binary_search.c

sort_util.o: sort_util.c sort_util.h
	gcc -I ./ -c sort_util.c

.PHONY: disc

disc:
	cd ./disc; make
