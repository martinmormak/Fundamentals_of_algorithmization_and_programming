#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include <string.h>
#include <ctype.h>


int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[])
{
    if(strlen(letters_guessed)<1)
    {
        return 0;
    }
    for(int i=0;i<strlen(secret);i++)
    {
        for(int x=0;x<strlen(letters_guessed);x++)
        {
            if(secret[i]!=letters_guessed[x]&&x==strlen(letters_guessed)-1)
            {
                return 0;
            }
            else if (secret[i]==letters_guessed[x])
            {
                x=strlen(letters_guessed);
            }
        }
    }
    return 1;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[])
{
    for(int i=0;i<strlen(secret);i++)
    {
        guessed_word[i]='_';
        guessed_word[i+1]='\0';
    }
    for(int i=0;i<strlen(secret);i++)
    {
        for(int x=0;x<strlen(letters_guessed);x++)
        {
            if(letters_guessed[x]==secret[i])
            {
                guessed_word[i]=secret[i];
            }
        }
    }
}

void get_available_letters(const char letters_guessed[], char available_letters[])
{
    available_letters[0]='\0';
    char input[2];
    for(int i=97;i<123;i++)
    {
        int z=1;
        for(int x=0;x<strlen(letters_guessed);x++)
        {
            int y=(int)letters_guessed[x];
            if(i==y)
            {
                z=0;
                x=strlen(letters_guessed);
            }
        }
        if(z==1)
        {
            input[0]=i;
            strcat(available_letters, input);
        }
    }
}

void hangman(const char secret[])
{
    printf("Welcome to the game, Hangman!\nI am thinking of a word that is %ld letters long.\n",strlen(secret));
    //printf("%s\n",secret);
    //char available_letters[26];
    char letters_guessed[100/*strlen(secret)*/]={0};
    char guessed_word[/*100*/strlen(secret)*2];
    char guessed_word_2[strlen(secret)*2];
    char input[100];
    int round=8;
    //printf("%ld\n",strlen(secret));
    //strncpy(guessed_word, secret, strlen(secret));
    //printf("%s\n",guessed_word);
    printf("-------------\n");
    for(int q=0;q<strlen(secret);q++)
    {
        guessed_word[q]='_';
        guessed_word[q+1]='\0';
    }
    strncpy(guessed_word_2, guessed_word, strlen(guessed_word));
    guessed_word_2[strlen(guessed_word)]='\0';
    //printf("%s\t%s",guessed_word,guessed_word_2);
    while(round>0)
    {
        char available_letters[26]={0};
        get_available_letters(letters_guessed,available_letters);
        printf("You have %d guesses left.\nAvailable letters: %s\nPlease guess a letter: ",round,available_letters);
        //fgets(input,strlen(secret),stdin);
        scanf("%s",input);
        while(getchar()!='\n');
        int w=0;
        //int q=0;
        if(strlen(input)==1)
        {
            if(input[0]>='a'&&input[0]<='z')
            {
                strcat(letters_guessed, input);
                get_guessed_word(secret,letters_guessed,guessed_word);
                /*for(int r=0;r<strlen(secret);r++)
                {
                    if(secret[r]==input[0])
                    {
                        round++;
                        break;
                    }
                }*/
                if(strlen(letters_guessed)>1)
                {
                    for(int i=0;i<strlen(letters_guessed)-1;i++)
                    {
                        if(letters_guessed[i]==letters_guessed[strlen(letters_guessed)-1])
                        {
                            round++;
                            w=strlen(guessed_word);
                            printf("Oops! You've already guessed that letter:");
                            for(int i=0;i<strlen(guessed_word);i++)
                            {
                                printf(" %c",guessed_word[i]);
                            }
                            printf("\n");
                            break;
                        }
                    }
                }
                while(w<strlen(guessed_word))
                {
                    if(guessed_word[w]==guessed_word_2[w]&&w==strlen(guessed_word)-1)
                    {
                        printf("Oops! That letter is not in my word:");
                        for(int i=0;i<strlen(guessed_word);i++)
                        {
                            printf(" %c",guessed_word[i]);
                        }
                        printf("\n");
                        break;
                    }
                    else if(guessed_word[w]!=guessed_word_2[w])
                    {
                        round++;
                        printf("Good guess:");
                        for(int i=0;i<strlen(guessed_word);i++)
                        {
                            printf(" %c",guessed_word[i]);
                        }
                        printf("\n");
                        break;
                    }
                    w++;
                }
                strncpy(guessed_word_2, guessed_word, strlen(guessed_word));
                guessed_word_2[strlen(guessed_word)]='\0';
            }
            else if(input[0]>='A'&&input[0]<='Z')
            {
                input[0]=tolower(input[0]);
                strcat(letters_guessed, input);
                get_guessed_word(secret,letters_guessed,guessed_word);
                /*for(int r=0;r<strlen(secret);r++)
                {
                    if(secret[r]==input[0])
                    {
                        round++;
                        break;
                    }
                }*/
                if(strlen(letters_guessed)>1)
                {
                    for(int i=0;i<strlen(letters_guessed)-1;i++)
                    {
                        if(letters_guessed[i]==letters_guessed[strlen(letters_guessed)-1])
                        {
                            round++;
                            w=strlen(guessed_word);
                            printf("Oops! You've already guessed that letter:");
                            for(int i=0;i<strlen(guessed_word);i++)
                            {
                                printf(" %c",guessed_word[i]);
                            }
                            printf("\n");
                            break;
                        }
                    }
                }
                while(w<strlen(guessed_word))
                {
                    if(guessed_word[w]==guessed_word_2[w]&&w==strlen(guessed_word)-1)
                    {
                        printf("Oops! That letter is not in my word:");
                        for(int i=0;i<strlen(guessed_word);i++)
                        {
                            printf(" %c",guessed_word[i]);
                        }
                        printf("\n");
                        break;
                    }
                    else if(guessed_word[w]!=guessed_word_2[w])
                    {
                        round++;
                        printf("Good guess:");
                        for(int i=0;i<strlen(guessed_word);i++)
                        {
                            printf(" %c",guessed_word[i]);
                        }
                        printf("\n");
                        break;
                    }
                    w++;
                }
                strncpy(guessed_word_2, guessed_word, strlen(guessed_word));
                guessed_word_2[strlen(guessed_word)]='\0';            }
            else
            {
                round++;
                printf("Oops! '%c' is not a valid letter:",input[0]);
                for(int i=0;i<strlen(guessed_word);i++)
                {
                    printf(" %c",guessed_word[i]);
                }
                printf("\n");
            }
        }
        else
        {
            strncpy(guessed_word, input, strlen(input));//https://stackoverflow.com/questions/16645583/how-to-copy-a-char-array-in-c
            break;
        }
        /*printf("%d\n",*/is_word_guessed(secret,letters_guessed)/*)*/;
        round--;
        for(int i=0;i<strlen(guessed_word);i++)
        {
            if(guessed_word[i]=='_')
            {
                i=strlen(guessed_word);
            }
            else if(guessed_word[i]!='_'&&i==strlen(guessed_word+1))
            {
                round=0;
            }
        }
        printf("-------------\n");
    }
    if(strlen(guessed_word)==strlen(secret))
    {
        for(int i=0;i<strlen(secret);i++)
        {
            if(guessed_word[i]!=secret[i])
            {
                if(round<1)
                {
                    printf("Sorry, you ran out of guesses. The word was %s.\n",secret);
                }
                else
                {
                    printf("Sorry, bad guess. The word was %s.\n",secret);
                }
                return;
            }
            else if(i==strlen(secret)-1)
            {
                printf("Congratulations, you won!\n");
            }
        }
    }
    else
    {
        if(round<1)
        {
            printf("Sorry, you ran out of guesses. The word was %s.\n",secret);
        }
        else
        {
            printf("Sorry, bad guess. The word was %s.\n",secret);
        }
    }
    //printf("%d\n",is_word_guessed(secret,letters_guessed));
}
