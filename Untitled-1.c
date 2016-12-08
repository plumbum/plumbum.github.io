#include <stdio.h>

void pr(int line) {
    printf("Line %d\n", line+1)
}

int main(int argc, char** argv) {
    for(i =0 ; i < 10; i++) {
        pr(i);
    }
    return 0;
}