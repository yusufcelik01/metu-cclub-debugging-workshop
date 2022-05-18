#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for(i=0; i<1000000000; i++){
        printf("i: %d\n", i);
        sleep(1);
    }


    return 0;
}
