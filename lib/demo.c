#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    printf("WASM Ready - Testing with Emscripten with HTML. Nov 27, 2022\n");
    return 1;
}

int getNum(){
    return 22; 
}

int getDoubleNum(int x){
    return x*2; 
}

char * greeting[50];
char * greet(char * name){
    if (strlen(name) > 40){
        return "The name is too long,";
    }
    strcpy(greeting, "Hello, ");
    return strcat(greeting, name);
}

