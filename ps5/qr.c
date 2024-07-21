#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);


int main()
{
    char character = 'A';
    bool bits[8];
    char* text = "Hello, how are you?";
    bool bytes[strlen(text)+1][8];
    int rows=strlen(text);
    char string[rows];
    int cols=3;
    int offset=2;
    bool blocks[offset*8][cols];
    encode_char(character, bits);
    for(int i=0;i<8;i++)
    {
        printf("%d",bits[i]);
    }
    printf("\n");
    printf("%c\n",decode_byte(bits));
    encode_string(text, bytes);
    for(int i=0;i<strlen(text)+1;i++)
    {
        printf("%c: ", text[i]);
        for(int x=0;x<8;x++)
        {
            printf("%d", bytes[i][x]);
        }
        printf("\n");
    }
    /*bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};*/
    decode_bytes(rows, bytes, string);
    printf("%s\n",string);
    /*bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
    };
    char string[7];
    decode_bytes(7, bytes2, string);
    printf("%s\n", string);*/
    /*bool bytes1[4+1][8]= {{0,1,0,0,0,0,0,1},
    {0,1,1,0,1,0,0,0},
    {0,1,1,0,1,1,1,1},
    {0,1,1,0,1,0,1,0},
    {0,0,0,0,0,0,0,0}};*/
    bytes_to_blocks(cols, offset, blocks, rows, bytes);
    for(int i=0;i<offset*8;i++)
    {
        for(int x=0;x<cols;x++)
        {
            printf("%d ", (blocks[i][x] == true) ? 1 : 0);
        }
        printf("\n");
        if(i % 8 == 7)
        {
            printf("\n");
        }
    }
    blocks_to_bytes(cols, offset, blocks, rows, bytes);
    for(int i=0;i<rows+1;i++)
    {
        for(int x=0;x<8;x++)
        {
            printf("%d", bytes[i][x]);
        }
        printf("\n");
    }

    return 0;
}

void encode_char(const char character, bool bits[8])
{
    int num;
    num=(int)character;
    for(int i=0;i<8;i++)
    {
        bits[7-i]=(num%2==0) ? 0 : 1;
        num=num/2;
    }
}

char decode_byte(const bool bits[8])
{
    int character=0;
    for(int i=0;i<8;i++)
    {
        character=character+pow(2,i)*bits[7-i];
    }
    return (char)character;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8])
{
    bool bits[8];
    char character;
    for(int i=0;i<strlen(string)+1;i++)
    {
        character=string[i];
        encode_char(character, bits);
        for(int x=0;x<8;x++)
        {
            bytes[i][x]=bits[x];
        }
    }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
    bool bits[8];
    for(int i=0;i<rows;i++)
    {
        for(int x=0;x<8;x++)
        {
            bits[x]=bytes[i][x];
        }
        string[i]=decode_byte(bits);
    }
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
    int index=0;
    for(int i=0;i<offset;i++)
    {
        for(int x=0;x<cols;x++)
        {
            for(int q=0;q<8;q++)
            {
                if(index<rows)
                {
                    blocks[i*8+q][x]=bytes[index][q];
                }
                else
                {
                    blocks[i*8+q][x]=0;
                }
            }
            index++;
        }
    }
}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
    int index=0;
    for(int i=0;i<offset;i++)
    {
        for(int x=0;x<cols;x++)
        {
            if(blocks[i*8+0][x]==0&&blocks[i*8+1][x]==0&&blocks[i*8+2][x]==0&&blocks[i*8+3][x]==0&&blocks[i*8+4][x]==0&&blocks[i*8+5][x]==0&&blocks[i*8+6][x]==0&&blocks[i*8+7][x]==0)
            {
                for(int w=0;w<8;w++)
                {
                    bytes[index][w]=0;
                }
                return;
            }
            else
            {

                for(int q=0;q<8;q++)
                {
                    bytes[index][q]=blocks[i*8+q][x];
                }
            }
            index++;
        }
    }
}
