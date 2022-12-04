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

// Circle annimation struct
struct CircleAnimationData {
    int x;  // x coordinate
    int y;  // y coordinate
    int r;  // radias
    int yv; // y - axis velocity
    int xv; // x - axis velocity
    int xd; // x - axis direction (1 = forward)
    int yd; // y - axis direction (1 = forward)
};


struct Circle circles[NUM_CIRCLES];
struct CircleAnimationData animationData[NUM_CIRCLES];

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

        // Fill animation data struct - i
        animationData[i].x = x;
        animationData[i].y = y;
        animationData[i].r = radias;
        animationData[i].xv = getRand(10);
        animationData[i].yv = getRand(10);
        animationData[i].xd = 1;
        animationData[i].yd = 1;

        // Now set the values in the struct - i
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

struct Circle * getCircles(int canvasWidth, int canvasHeight){
    printf("getCircles: entry\n");
    // Update circle data
    for (int i=0; i < NUM_CIRCLES; i++){
        // Check for RIGHT collision - set x direction backwards
        if ( (animationData[i].x + animationData[i].r) >= canvasWidth ){
            animationData[i].xd = 0;
        }
        // Check for LEFT collision - set x direction forwards
        if ( (animationData[i].x - animationData[i].r) <= 0 ){
            animationData[i].xd = 1;
        }
        // Check for TOP collision - set y direction forward
        if ( (animationData[i].y - animationData[i].r) <= 0 ){
            animationData[i].yd = 1;
        }
        // Check for BOTTOM collision - set y direction backward
        if ( (animationData[i].y + animationData[i].r) >= canvasHeight ){
            animationData[i].yd = 0;
        }

        // Move circle in specified direction
        if (animationData[i].xd == 1){
            animationData[i].x += animationData[i].xv;
        } else {
            animationData[i].x -= animationData[i].xv;
        }
        if (animationData[i].yd == 1){
            animationData[i].y += animationData[i].yv;
        } else {
            animationData[i].y -= animationData[i].yv;
        }

        // Update matching circle data
        circles[i].x = animationData[i].x;
        circles[i].y = animationData[i].y;

    }

    printf("getCircles: exit\n");
    return circles;
}