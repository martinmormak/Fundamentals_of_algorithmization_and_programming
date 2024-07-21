#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("Not enought arguments!\n");
        return 1;
    }
    FILE *fp = fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("Error opening file %s!\n",argv[2]);
        //exit(EXIT_FAILURE);
        return -1;
    }
    char buffer[6];
    int count=0;
    for(int i=0;i<6;i++)
    {
        buffer[i]=fgetc(fp);
    }
    while(buffer[5]!=EOF)
    {
        if(buffer[0]=='a'||buffer[0]=='A')
        {
            if(buffer[1]=='n'||buffer[1]=='N')
            {
                if(buffer[2]=='a'||buffer[2]=='A')
                {
                    if(buffer[3]=='n'||buffer[3]=='N')
                    {
                        if(buffer[4]=='a'||buffer[4]=='A')
                        {
                            if(buffer[5]=='s'||buffer[5]=='S')
                            {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<5;i++)
        {
            buffer[i]=buffer[i+1];
        }
        buffer[5]=fgetc(fp);
    }
    char c;
    int num;
    fclose(fp);
    FILE *fpp = fopen(argv[1],"w");
    if(count>9)
    {
        num=count/10;
        c=48+num;
        fputc(c,fpp);
        num=count-num*10;
        c=48+num;
        fputc(c,fpp);

    }
    else
    {
        c=48+count;
        fputc(c,fpp);

    }
    //fputc(c,fpp);
    fclose(fpp);
    //printf("%d",count);
}
