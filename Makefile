.PHONY: encrypt decrypt run clean

encrypt:
	g++ --std=c++11 -I include -Wall -Wextra -pedantic -O3 -o run src/main.cpp src/user.cpp src/file.cpp src/decrypt.cpp src/encrypt.cpp -DDECRYPT_MODE=0

decrypt:
	g++ --std=c++11 -I include -Wall -Wextra -pedantic -O3 -o run src/main.cpp src/user.cpp src/file.cpp src/decrypt.cpp src/encrypt.cpp -DDECRYPT_MODE=1

run: $(MODE)
	./run

clean:
	rm -f run saved.txt
