#include <emscripten.h>
#include <stdio.h>

char * str = "my string variable";
char * getStr(){
    return str;
}

int getNumber(){
     int num = 22;
     /* emscripten_debugger(); */
     if (num < 30){
         emscripten_log(EM_LOG_WARN, "'num' is less than 30...");
     }
     return num;
}

int main(){
    printf("WASM Ready - Testing with Emscripten with HTML. Nov 27, 2022 @ 6:50PM\n");
    return 1;
}