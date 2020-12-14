
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

	//int passed = 0;
	//int passing = 0;
	

	
	int uhh = 0;
	int ticks = 0;
	
    hamster_create();
    
    printf("move");
    while(1) {
    	int l = hamster_left_floor();
    	int r = hamster_right_floor();
    	
    	double defaultL = 10;
    	double defaultR = 40;
    	
    	if(l < 20) {
    		if(ticks != 0) {
    			uhh = 1;
			}
			
			
			
			if(uhh == 1) {
				// �ް� 
				hamster_wheels(defaultL-3, defaultR * 1.5);
				hamster_leds("red", "off");
			} else {
				// ��ް�
				hamster_wheels(defaultL, defaultR);
				hamster_leds("green", "off");
			}
			soundCreateThread();
		} else if(r < 20) {
			if(ticks != 0) {
    			uhh = 1;
			}
			

			
			if(uhh == 1) {
				// �ް� 
				hamster_wheels(defaultR * 1.5, defaultL-3);
				hamster_leds("off", "red");
			} else {
				// ��ް�
				hamster_wheels(defaultR, defaultL);
				hamster_leds("off", "green");
			}
			soundCreateThread();
		} else {
			hamster_wheels(defaultL, defaultL);
			hamster_leds("white", "white");
		}
		
		if(ticks == 50) {
			ticks = 0; 
			uhh = 0;
		}
		
		ticks++;
		
		
		wait(5);
	}
    
    
	// ������ �ڵ��ϴ��� 
	/*
    while(passed <= 2) { // �������� ���� ������
    
    	int l = hamster_left_floor();
    	int r = hamster_right_floor();
    	
        //printf("%d-----%d\n", l, r);
        hamster_wheels(30, 30); // ������ �̵��Ѵ�.
        
        /*
        if (l < 20 || r < 20)
        {
        	while(hamster_left_floor() < 20 || hamster_right_floor() < 20)	{
			}
        	passed++;
		}-

        
        
        /*
        if(l < 20 || r < 20) {
        	passing = 1;
		} else {
			if(passing == 1) {
				passed++;
				passing = 0;
			}
		}
		printf("passed: %d\n", passed);
		
        wait(20); // �ʹ� ���� �ݺ����� �ʵ��� �Ѵ�.
    }
    printf("passed: %d\n", passed);
    printf("%d-----%d\n", hamster_left_floor(), hamster_right_floor());
    */
    
    
    hamster_stop(); // �����Ѵ�.

    dispose_all(); // ��� ������ �����ϰ� �޸𸮸� �����Ѵ�.

    return 0;
}
