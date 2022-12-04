#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten.h>

#define NUM_CIRCLES 20

struct Circle {
    int x;  // x coordinate
    int y;  // y coordinate
    int r;  // radias
    int cr; // color for red
    int cg; // color for green
    int cb; // color for blue
};

struct Circle circles[NUM_CIRCLES];

int getRand(int max){
    return (rand() % max);
}

int main(){
    printf("main: entry\n");
    printf("WASM Ready from circles.\n");
    
    // Seed random number generator
    srand(time(NULL));

    // Create random circles
    for(int i=0; i < NUM_CIRCLES; i++){
        // Radias
        int radias = getRand(50);
        // Coordinates
        int x = getRand(1000)+radias;
        int y = getRand(1000)+radias; 
        // Now set the values in the struct
        circles[i].x = x;
        circles[i].y = y;
        circles[i].r = radias;
        circles[i].cr = getRand(255);
        circles[i].cg = getRand(255);
        circles[i].cb = getRand(255);
    }

    EM_ASM({render($0, $1); }, NUM_CIRCLES*6, 6);
    printf("main: exit\n");
    return 1;
}

struct Circle * getCircles(){
    printf("getCircles: entry\n");
    printf("getCircles: exit\n");
    return circles;
}