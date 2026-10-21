
example1 :
	gcc example/example1.c WaveFunctionCollapse.c
	./a.out

example2 :
	gcc example/example2.c WaveFunctionCollapse.c
	./a.out

example3 :
	gcc example/example3.c WaveFunctionCollapse.c
	./a.out

example4 :
	gcc example/example4.c WaveFunctionCollapse.c
	./a.out

test :
	gcc tests/test_entropy.c WaveFunctionCollapse.c -o test_entropy
	./test_entropy

clean :
	rm -f a.out
	rm -f test_entropy
