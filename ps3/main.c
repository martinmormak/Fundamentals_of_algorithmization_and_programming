#include<stdio.h>
#include"hangman.h"
#include<time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    char secret[9]={'a','a','a','a'};
    /*char result[30]={"_________________"};
    get_guessed_word("vitalizing", "",result);
    printf("%s\n%ld\n",result,strlen(result));*/
    /*printf("%d\n",*/get_word(secret)/*)*/;
    //printf("%s\n",secret);
    hangman(secret);
    return 0;
}
