vec.o: vec.c
	gcc -c ./vec.c

vec_test.o: vec_test.c
	gcc -c ./vec_test.c

vec_test: vec.o vec_test.o
	gcc -o ./vec_test ./vec.o ./vec_test.o
	
qsc.o: qsc.c
	gcc -c ./qsc.c

qsc: qsc.o vec.o
	gcc -o ./qsc ./qsc.o ./vec.o

mgs: mgs.c
	gcc -o ./mgs ./mgs.c

clean:
	rm *.o ./qsc ./vec_test
