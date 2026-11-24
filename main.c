
#include <stdio.h>
#include <stdlib.h>

void heapify(int a[10], int n)
{
    int i, k, v, j, flag;

    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = a[k];
        flag = 0;

        while (!flag && 2 * k <= n)
        {
            j = 2 * k;

            if (j < n && a[j] < a[j + 1])
                j = j + 1;

            if (v >= a[j])
                flag = 1;
            else
            {
                a[k] = a[j];
                k = j;
            }
        }

        a[k] = v;
    }
}

int main()
{
    int n = 0, a[10], i, ch;

    for (;;)
    {
        printf("\n1. Create heap");
        printf("\n2. Extract max");
        printf("\n3. Exit");
        printf("\nRead choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nRead number of elements: ");
                scanf("%d", &n);

                if (n < 1 || n > 9)
                {
                    printf("\nInvalid number of elements");
                    n = 0;
                    break;
                }

                printf("\nRead elements:\n");

                for (i = 1; i <= n; i++)
                    scanf("%d", &a[i]);

                heapify(a, n);

                printf("\nElements after constructing heap:\n");

                for (i = 1; i <= n; i++)
                    printf("%d\t", a[i]);

                break;

            case 2:
                if (n >= 1)
                {
                    printf("\nElement deleted is %d", a[1]);

                    a[1] = a[n];
                    n--;

                    heapify(a, n);

                    printf("\nHeap after deletion:\n");

                    for (i = 1; i <= n; i++)
                        printf("%d\t", a[i]);
                }
                else
                {
                    printf("\nNo elements to delete");
                }

                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}
