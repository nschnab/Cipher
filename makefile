compile: queue cipher cipheradvanced
	g++ -Wall Project3.cpp Queue.o Cipher.o CipherAdvanced.o -o a.out
queue:
	g++ -Wall -c Queue.cpp
cipher:
	g++ -Wall -c Cipher.cpp
cipheradvanced:
	g++ -Wall -c CipherAdvanced.cpp
run:
	./a.out
clean:
	rm *.out