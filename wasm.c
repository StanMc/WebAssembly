#include <string.h>

void intLog(int n);
void strLog(char * offset, int length);
void consoleMemory(int n);

int main() {
    return 42;
}

void greet(){
    char * msg = "Hello from C !!!";
    strLog(msg, strlen(msg));
}


void cConsoleMemory(){
  consoleMemory("This came from cConsoleLog....");
}

int getDoubleNumber(int x) {
    return x*2;
}

void getTripleNumber(int x){
    intLog(x*3);
    intLog(999); 
}
