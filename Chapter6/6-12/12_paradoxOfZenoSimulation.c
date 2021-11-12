/*
## 6.12 제논의 역설 시뮬레이션 예제
*/

    /*
    	Simulation of a Moving Object

    	- Speed = 1.0 m/s
    	- dt = 1.0 s
    	- Distance traveled during dt = Speed * dt

    	- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m
    	- Step 2 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m + 1.0 m = 2.0 m
    	- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 2.0 m + 1.0 m = 3.0 m
    	- ... ...
    */ // 이러한 코드 만들기

// ※ 내가 한 코드

#include <stdio.h>

int main() {

    double speed = 1.0, dt = 0, distance = 0;

    for (dt = 1; dt <= 10; dt++) {
    	distance = speed * dt;

    	printf("Elapsed time = %lfs, ", dt);
    	printf("Distance = %lfm\n", distance);
    }

    return 0;
}

//
// ※ 교수님 코드

#include <stdio.h>

int main() {
    const double speed = 1.0;
    const unsigned repeat_max = 10;

    double dt = 1.0;
    double time = 0.0;		// Elaped time
    double dist = 0.0;		// Distance

    for (unsigned i = 0; i < repeat_max; ++i) {

    	dist += speed * dt; // dist = dist + speed * dt;
    	time += dt;

    	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);
    }

    return 0;
}


/*********************************************************
*********************************************************/


// 위에 코드 수정해서 제논의 역설 식 만들기

    /*
    	Zeno's Paradox

    	- Step 1 : 1.0 * 1.0 = 1.0, 1.0
    	- Step 2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
    	- Step 3 : 1.0 * 0.25 = 0.25, 1.5 + 0.25 = 1.75
    	... ...(1step 마다 dt를 절반으로 줄여서 계산)
    */

// ※ 내가 한 코드

#include <stdio.h>

int main() {

    const double speed = 1.0;
    const unsigned repeat_max = 10;

    double dt = 1.0;
    double time = 0.0;		// Elaped time
    double dist = 0.0;		// Distance

    for (unsigned i = 0; i < repeat_max; ++i) {

    	dist += speed * dt; // dist = dist + speed * dt;
    	time += dt;

    	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

    	//TODO: half time step
    	dt = dt / 2;
    }

    //Note: infinite geometric series

    return 0;
}


/*********************************************************
*********************************************************/

/*
dt가 double일 때 dt = dt / 2; 해도 되긴 한다.
하지만 C/C++의 엄격함을 따라 가려면 dt = dt / 2.0;으로 쓰는 것이 좋다.

그리고 *(곱하기)가 /(나누기)보다 빠르다.
그래서 *를 쓰는 것이 좋다.
dt = dt / 2.0;을 dt = dt _ 0.5;로 쓰는 것이 일반적. 더 나아가서 dt _= 0.5;
*/

int main() {

    const double speed = 1.0;
    const unsigned repeat_max = 10;

    double dt = 1.0;
    double time = 0.0;		// Elaped time
    double dist = 0.0;		// Distance

    for (unsigned i = 0; i < repeat_max; ++i) {

    	dist += speed * dt; // dist = dist + speed * dt;
    	time += dt;

    	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

    	//TODO: half time step
    	dt *= 0.5;
    }

    //Note: infinite geometric series

    return 0;
}

/*
repeat_max를 100으로 해도 time이 2를 넘어가지 못한다.
제논의 역설에서 말하는 무한 등비 급수 infinite geometric series
*/

// 제논의 역설 구현

int main() {

    const double speed = 1.0;
    const unsigned repeat_max = 50;

    double time = 0.0;			// Elaped time
    double dist_arch = 0.0;		// Achilleus distance from start point
    double dist_turtle = 1.0;	// turtle distance from start point
    double speed_arch = 10.0;
    double speed_turtle = 0.001;
    double dt = 0.01;
    unsigned i;

    printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n",
    	time, dt, dist_arch, dist_turtle);

    for (i = 0; i < repeat_max; ++i) {

    	dist_arch += speed_arch * dt;
    	dist_turtle += speed_turtle * dt;
    	time += dt;

    	printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n",
    		time, dt, dist_arch, dist_turtle);

    	dt *= 0.5;
    }

    //Note: infinite geometric series

    return 0;
}
