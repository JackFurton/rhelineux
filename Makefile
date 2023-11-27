#---------------Makefile-----------------
CC=g++
CFLAGS=--std=c++11
COMMON_SRC=main.cpp user.cpp file.cpp decrypt.cpp encrypt.cpp

decrypt:
	$(CC) $(CFLAGS) -DDECRYPT_MODE -o run $(COMMON_SRC)

encrypt:
	$(CC) $(CFLAGS) -o run $(COMMON_SRC)

clean:
	rm -f run
