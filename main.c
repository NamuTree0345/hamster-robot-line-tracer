#include <stdio.h>
#include <stdlib.h>
#include "roboid.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("loading\n");
	hamster_create();
	
	int rot = 0;
	
	while(1) {
		
		if(hamster_left_floor() <= 20) {
			// left
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

		} else if(hamster_right_floor() <= 20) {
			// right 
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
