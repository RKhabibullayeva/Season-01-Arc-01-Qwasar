#include <stdio.h>
#include <stdlib.h>

int my_square(int x, int y){
    int a, b;

    for(a = 0; a < x; a++){
        for(b = 0; b < y; b++){
            if(a == 0 || a == x - 1){
                if(b > 0 && b < y -1){
                    printf("-");
                    continue;
                }
                printf("o"); 
            }else if(b == 0 || b == y - 1){
                printf("|");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int main(int ac, char **av){
    if(ac != 3){
        return 0;
    }

    int x = atoi(av[1]);
    int y = atoi(av[2]);
    my_square(x, y);
}
