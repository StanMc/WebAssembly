#include <emscripten.h>
#include <stdio.h>

// Declare a reusable JS function
EM_JS(void, jsFunction, (int n), {
    console.log("Call from EM_JS: " + n);
});

int main(){
    printf("WASM Ready \n");
    // Call JS function (eval)
    emscripten_run_script("console.log('Hello from C')");

    // Call JS function (eval) ASYNC
    emscripten_async_run_script("console.log('Hello from C - Async')", 2000);


    // Get return value from JS function - INT
    int jsIntVal = emscripten_run_script_int("getNum()");
    printf("Value from getNum() = %d \n", jsIntVal);

    // Get return value from JS function - STRING
    char * jsStringVal = emscripten_run_script_string("getString()");
    printf("Value from getString() = %s \n", jsStringVal);

    jsFunction(144);

    return 1;
}