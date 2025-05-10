#include <stdio.h>

int main()
{
    int temp;
    int n;

    printf("ENTER HOW MANY NUMBERS YOU WANT TO BE ARRANGED:");

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {

        printf("ENTER THE NUMBERS YOU WANT TO BE ARRANGED:");
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
        
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);

    }

        return 0;
}