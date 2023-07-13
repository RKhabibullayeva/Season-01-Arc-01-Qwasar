#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int my_length(char* p1){
    int l = 0;
    while(p1[l]!='\0'){
     l++;
    }
     return l;
}
int my_head(char *isN, char c){
    for(int i = 0; isN[i] != '\0'; i++){
        if(isN[i] == c){
            return i;
        }
    }
    return 0;
}

char *my_rand(){
    srand(time(0));
    char *isN = (char*)malloc(4 * sizeof(char));
    int i = 0;
    while(i < 4){
        char c = rand() % 8 + '0';
        if(my_head(isN, c) == 0){
            isN[i] = c;
            i++;
        }
    }
    
    return isN;
}


int intg(char* array1, char b){
    for(int j = 0; j < 4; j++){
        if(array1[j] == b)
        {
            return j;
        }
    }
    
    return -1;
}

char* my_read(){
    char *str = (char*)malloc(500 * sizeof(char));
    int j = 0;
    char b;
    while(read(0, &b, 1) > 0){
        if(b != '\n'){
            str[j] = b;
            j++;
        }else{
            return str;
        }
    }
    return NULL;
}
int my_replace(char *str1,char *str2){
    int f1 = 0,f2 = 0;
    
    for(int j = 0; str1[j] != '\0';j++){
    f1+=str1[j];
    }
    for(int j = 0; str2[j] != '\0';j++){
    f2+=str2[j];
    }
    if(f1 - f2 == 0){
        return 0;
    }else if(f1 > f2){
        return 1;
    }else{
        return -1;
    }
    return 0;
}
void my_putterchar(char b)
{
    write(1, &b, 1);
}
void my_printf(char *string)
{
    int w = 0;
    while(string[w]!= '\0')
    {
        my_putterchar(string[w]);
        w++;
    }
}

int falce_input(char *str)
{
    if(my_length(str) > 4 || my_length(str) < 4){
        return 0;
    }
    
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] > '9' || str[i] < '0'){
            return 0;
        }
    }
    
    for(int i = 0; i < my_length(str) - 1; i++){
        for(int j = i + 1; j < my_length(str); j++){
            if(str[i] == str[j]){
                return 0;
            }
        }
    }
    
    return 1;
}


int main(int ac, char** av) {
    
    char *kod;
    char* my_kod;
    int rounds = 10;
    my_kod = my_rand();
    int i = 0;
    while( i < ac)
    {
        if(my_replace("-t",av[i]) == 0){
            rounds = atoi(av[i+1]);
        }
        i++;
    }
    for(int i = 0; i < ac; i++){
        if(my_replace("-c",av[i]) == 0){
            kod = av[i+1];
        for(int i = 0; kod[i] != '\0'; i++){
        my_kod[i] = kod[i];
        }
      }
    }

    my_printf("Will you find the secret code?\nPlease enter a valid guess\n");
    char* isfalce;
    int finish = 0;
    for(int i = 0; i < rounds; i++)
    {
       
        printf("---\nRound %d\n",i);
         finish = 0;
        for(;finish != 1;){
            write(1, ">", 1);
           isfalce = my_read();
           if(isfalce == NULL){
               return 0;
           }
            if(falce_input(isfalce) == 1){
                    
              int s = 0, b = 0;
            
                int j = 0; 
                while(j< 4)
            {
                if(isfalce[j] == my_kod[j]){
                    s++;
                }
                j++;
            }
            if(s == 4){
                my_printf("Congratz! You did it!\n");
               return 0;
            }
            if(s != 4)
                    for(int i = 0; i < 4; i++){
                    int x = intg(isfalce, my_kod[i]);
                    if(x != -1 && x != i){
                        b++;
                    }
                 }
                 finish = 1;
                printf("\nWell placed pieces: %d\n",s);
                printf("Misplaced pieces: %d\n", b);
            }else{
                my_printf("Wrong Input!\n");
            }
            
        }
    }
    return 0;
}