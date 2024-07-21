#include <stdio.h>

int main(int argc, char *argv[])
{
    /*if(argc<3)
    {
        printf("Not enought arguments!\n");
        return 1;
    }*/
    FILE *fpi = fopen(argv[1],"r");
    /*if(fpi==NULL)
    {
        printf("Error opening file %s!\n",argv[1]);
        //exit(EXIT_FAILURE);
        return -1;
    }*/
    FILE *fpo = fopen(argv[2],"w");
    /*if(fpo==NULL)
    {
        printf("Error opening file %s!\n",argv[2]);
        //exit(EXIT_FAILURE);
        return -1;
    }*/
    char buffer[50];
    while(buffer[0]!='S'||buffer[1]!='T'||buffer[2]!='A'||buffer[3]!='R'||buffer[4]!='T')
    {
        for(int i=0;i<50;i++)
        {
            buffer[i]=fgetc(fpi);
            if(buffer[i]==' ')
            {
                buffer[i]='\0';
                i=50;
            }
            else if(buffer[i]==EOF)
            {
                return 0;
            }
        }
    }
    for(int i=0;i<50;i++)
    {
        buffer[i]=fgetc(fpi);
        if(buffer[i]==' ')
        {
            buffer[i]=' ';
            i=50;
        }
        else if(buffer[i]==EOF)
        {
            break;
        }
    }
    int number=1;
    while(buffer[0]!='S'||buffer[1]!='T'||buffer[2]!='O'||buffer[3]!='P')
    {
        if (number%2==0)
        {
            if(number!=2)
            {
                fputc(' ',fpo);
            }
            for(int i=0;i<50;i++)
            {
                if(buffer[i]==' ')
                {
                    i=50;
                    break;
                }
                fputc(buffer[i],fpo);
            }
        }
        number++;
        for(int i=0;i<50;i++)
        {
            buffer[i]=fgetc(fpi);
            if(buffer[i]==' ')
            {
                buffer[i]=' ';
                i=50;
            }
            else if(buffer[i]==EOF)
            {
                break;
            }
        }
    }
    fclose(fpo);
    fclose(fpi);
    //printf("%d",count);
}
