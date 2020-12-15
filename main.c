#include <stdio.h>
#include "roboid.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *sound() {
	hamster_pitch("C");
	wait(100);
	hamster_pitch("off");

	hamster_pitch("E");
	wait(100);
	hamster_pitch("off");
	hamster_pitch("G");
	wait(100);
	hamster_pitch("off");
	/*
	hamster_pitch("C");
	wait(500);
	hamster_pitch("off");
	*/
}

void soundCreateThread() {
	pthread_t p_thread[1];
	int thr_id;

	char p1[] = "th1";
	thr_id = pthread_create(&p_thread[0], NULL, sound, (void *)p1);
    if (thr_id < 0)
    {
        perror("thread create error!");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
	printf("loading\n");
	hamster_create();
	
	int rot = 0;
	
	while(1) {
		
		if(hamster_left_floor() <= 20) {
			// left
						soundCreateThread();
			if(rot == 0) {
				hamster_turn_left(1, 15);
				rot = 1;
			} else if(rot == 1) {
				hamster_turn_left(1, 10);
				rot = 2;
			} else {
				hamster_turn_left(1, 5);
				rot = 0;
			}
			hamster_leds("green", "off");

		} else if(hamster_right_floor() <= 20) {
			// right 
						soundCreateThread();
			if(rot == 0) {
				hamster_turn_right(1, 15);
				rot = 1;
			} else if(rot == 1) {
				hamster_turn_right(1, 10);
				rot = 2;
			} else {
				hamster_turn_right(1, 5);
				rot = 0;
			}
			hamster_leds("off", "green");
		} else {
			// 돌고있지 않을 때
			rot = 0;
			hamster_wheels(60, 60);
		}
		
		printf("%d\n", rot);
		
		wait(5);
	}
	
	return 0;
}
