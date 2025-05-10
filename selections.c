#include <stdio.h>
int main()
{
    int wall = 0;
    int arr[10] = {3, 4, 2, 5, 6, 1, 7, 10, 8, 9};
    while (wall < 10)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                arr[j] < arr[i];
                arr[wall] = arr[i];
            }
            wall++;
        }
    }
      for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);

    }


    return 0;
}