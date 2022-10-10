main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o caesar.o vigenere.o decryption.o
	g++ -o tests tests.o funcs.o caesar.o vigenere.o decryption.o

test-ascii: test-ascii.cpp
	g++ -o test-ascii test-ascii.cpp

decryption.o: decryption.cpp decryption.h funcs.h
	g++ -c decryption.cpp

vigenere.o: vigenere.cpp vigenere.h funcs.h
	g++ -c vigenere.cpp

caesar.o: caesar.cpp caesar.h funcs.h
	g++ -c caesar.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

main.o: main.cpp funcs.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h funcs.h caesar.h vigenere.h decryption.h
	g++ -c tests.cpp

clean:
	rm -f main.o funcs.o tests.o caesar.o vigenere.o decryption.o
