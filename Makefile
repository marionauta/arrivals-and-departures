aad: src/main.c
	cc -std=c11 -Wall -Wextra -o $@ $^ `pkg-config --cflags --libs raylib` -lm
