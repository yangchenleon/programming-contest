#include "string.h"
#include <stdio.h>

FILE* fin;
FILE* fout;

int main()
{
    fin = fopen("A.txt","r");
    fout = fopen("re.txt","w");
    char ch;
    while(EOF != fscanf(fin, "%c", &ch))
    {
        
        if(ch == '\n') 
        {
            printf("%c",ch);
            fprintf(fout, "%c", ch);
            fscanf(fin, "%c", &ch);
            while(ch==' '||ch=='\t'||ch=='\n')
                fscanf(fin, "%c", &ch);
        }
        printf("%c",ch);
        fprintf(fout, "%c", ch);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}