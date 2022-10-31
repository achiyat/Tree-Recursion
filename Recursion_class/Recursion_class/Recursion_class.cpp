
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

int bbb()
{
    return 0;
}


int aaa()
{
    bbb();
    return 0;
}



int ADD(int num)
{
    if (num == 5)
    {
        return 0;
    }
    printf("%d\n", num);
    return ADD(num + 1) + 1;
}

int main()
{

    int a = ADD(1);

    return 0;
} 
