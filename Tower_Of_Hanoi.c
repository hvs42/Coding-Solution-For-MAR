#include<stdio.h>

void toh(int n,char beg, char end,char aux)
{
    if (n==1)
    {
        printf("Moved disk 1 from %c to %c \n",n,beg,end);
        return;
    }
    else
    {
        toh(n-1,beg,aux,end);
        printf("Moved disk %d from %c to %c  \n",n,beg,end);
        toh(n-1,aux,end,beg);
    }
}

int main() 
{ 
    int n=3;
    toh(n, 'A', 'C', 'B');
    return 0; 
} 