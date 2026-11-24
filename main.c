#include <stdio.h>
#include <stdlib.h>

void towerofhanoi(int n, char source, char dest, char temp)
{
    if(n>1)
    {
        towerofhanoi(n-1,source,temp,dest);
        printf("\n Move %d disc from %c to %c ", n,source,dest);
        towerofhanoi(n-1,temp,dest,source);

    }
    else
        printf("\n Move %d disc from %c to %c ",n,source,dest);

}
int main ()
{
    int n;
    printf("\n Read no of discs:");
    scanf("%d",&n);
    towerofhanoi(n,'S','D','T');
    return 0;
}
