#include <stdio.h>

#define WIELKOSC 50

int getString(char s[]);

void strMatch(char* master, char* str, int iter, int iter2);


//**********************************************************


int main(void)
{
    char master[WIELKOSC], str[WIELKOSC];

    getString(master);
    getString(str);
    strMatch(master, str, 0, 0);


    return 0;
}

//**********************************************************


void strMatch(char* master, char* str, int iter, int iter2)
{
    if(master[iter]=='\0'&&str[iter2]=='\0')
    {
        printf("TRUE");
        return;
    }
    else if(master[iter]=='*')
    {
        while(str[iter2]!=master[iter+1])
        {
            iter2++;
            if(master[iter+1]=='\0')
            {
                printf("TRUE");
                return;
            }
            else if(str[iter2]=='\0')
            {
                printf("FALSE");
                return;
            }
        }
        iter++;
        strMatch(master, str, iter, iter2);
    }
    else if(master[iter]=='?')
    {
        iter++;
        iter2++;
        strMatch(master, str, iter, iter2);
    }
    else if(master[iter]!=str[iter2])
    {
        printf("FALSE");
        return;
    }
    else
    {
        iter++;
        iter2++;
        strMatch(master, str, iter, iter2);
    }
}

int getString(char s[])
{

    char ch;
    int i=0;

    while( (ch = getchar()) != '\n'   &&   ch != EOF )
    {
        s[i] = ch;
        ++i;
    }

    s[i] = '\0';

    fflush(stdin);

    return i;
}
