#include <stdio.h>
int main(int argc, char* argv[]) {
    int array[128] = {0};
    for(int i = 1; i < argc; i++) {
        for(int j = 0; argv[i][j] != '\0'; j++) {
            array[(int)argv[i][j]]++;
        }
    }
    for(int i = 0; i < 128; i++) {
        if(array[i] > 0) {
            printf("%c:%d\n", i, array[i]);
        }
    }
}