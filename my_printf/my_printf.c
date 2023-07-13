#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h> 
#include <stddef.h>

void My_put_Char(char hr)
{
    write(1, &hr, 1);
}

int  My_put_Str(char *s)
{    
    int g = 0;
    while (s[g] != '\0') {
        My_put_Char(s[g]);        
        g++;
    }    
    return g;
}

char* Stringreversed(char* par_1){
    int length = strlen(par_1);    
    for(int p = 0; p < length/2; p++){
        char bot = par_1[p];        
        par_1[p] = par_1[length - p - 1];
        par_1[length - p - 1] = bot;  
    }
    return par_1;
}

int IntchangeChar(int num_1, char num_2){ 
    char *ress = malloc(sizeof(char) * 10);    
    int r = 0, flg = 0;
    if(num_1 == 0){
        My_put_Char('0');
        return 1;
    }
    if (num_1 < 0) {       
        num_1 *= -1;
        flg++;
    }    
    while(num_1 != 0)
    {        
        ress[r++] = num_1 % 10 + 48;
        num_1 /= 10;   
    }
    if(flg == 1 && num_2 != 'u'){
        ress[r] = '-';
    }
    char *rever = malloc(sizeof(char) * strlen(ress));   
     rever = Stringreversed(ress);
    int band = My_put_Str(rever);
    return band;
}

int DectohexConver(int decNum)
{    int j = 0, change_1;
    char* hexNum = malloc(sizeof(char)* 20);    
    while (decNum != 0)
    {       
        change_1 = decNum % 16;
        if (change_1 < 10){           
        hexNum[j++] = 48 + change_1;
        }
        else{           
        hexNum[j++] = 55 + change_1;
        decNum = decNum / 16;   
        } 
    }
    char *rever_1 = malloc(sizeof(char) * strlen(hexNum));    
    rever_1 = Stringreversed(hexNum);
    int fr = My_put_Str(rever_1);    
    return fr;
}

int DectoOct(int dectooct)
{    
    int ind = 0;
    char* s = malloc(sizeof(char)*14);    
    while(dectooct != 0){
        s[ind] = dectooct % 8 + '0';        
        dectooct = dectooct / 8;
        ind++;    
    }
    char *rev_1 = malloc(sizeof(char) * strlen(s));    
    rev_1 = Stringreversed(s);
    int x = My_put_Str(rev_1);    
    return x;
}

int Pconversion(long sam)
{
    int f = 0, l, box_3, p, w;
    char* hexanbr = malloc(sizeof(char)*10);
    for(; sam != 0; ){
        p = sam / 16;
        w = p * 16;
        box_3 = sam - w;
        if(box_3 < 10)
        box_3 = box_3 + 48;
        else
        box_3 = box_3 + 87;
        hexanbr[f++] = box_3;
        sam = sam / 16;
    }
    char* string = Stringreversed(hexanbr);
    l = My_put_Str(string);
    return l;
}

int my_printf(char * qwer, ...)
{        
    va_list up;
    va_start(up, qwer);
    int i = 0 , x = 0, num, xeca, oct, uns;    
    unsigned long name; 
    char chr, *str; 
    while(qwer[i]){
        if(qwer[i] == '%'){            
            i++;
            switch (qwer[i]){                
                case 'd':
                    num = va_arg(up, int);                    
                    x += IntchangeChar(num, 'd');
                break;                
                case 'c':
                    chr = (char)va_arg(up, int);                    
                    My_put_Char(chr);
                    x++;                
                break;
                case 's':                    
                    str = va_arg(up,char*);
                    if(str == NULL){
                        str = "(null)";
                    }
                    x += My_put_Str(str);                
                    break;
                case 'x':                    
                    xeca = va_arg(up, int);
                    x += DectohexConver(xeca);                
                break;
                case 'o':                    
                    oct = va_arg(up, int);
                    x += DectoOct(oct);                
                break;
                case 'u':                    
                    uns = va_arg(up, int);
                    x += IntchangeChar(uns, 'u');                
                break; 
                case 'p':
                    name = (unsigned long) va_arg(up, void*);
                    My_put_Str("0x");                    
                    x += 2;
                    x += Pconversion(name);               
                break;            
            }
        }
        else{
            My_put_Char(qwer[i]);           
            x++;
        }        
        i++;
    }    
    return x;
}

// int main(){    
//  char* s = malloc(10);
//  s = "asd";  

// //int x = my_printf("%d - %d - %d\n", 12, 34, -56);
//     //printf("%d\n", x);
    
//     int x = my_printf("!%p!\n", &x);
//     printf("%d\n", x);    
//     // x = printf("%p\n", &x);
//     // printf("%d\n", x);
    
//     return 0;
// }