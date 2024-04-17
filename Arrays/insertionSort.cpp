void insertionSort(int arr[], int n)
{
    int i = 1;

    while (i < n)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        i++;
        arr[j + 1] = temp;
    }
    // we assumed arr[0] is already sorted

    // for (int i = 1; i < n; i++)
    // {
    //     int j = i - 1;
    //     int temp = arr[i];
    //     for (; j >= 0; j--)
    //     {
    //         if (arr[j] > temp)
    //         {
    //             // shift
    //             arr[j + 1] = arr[j];
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     arr[j + 1] = temp;
    // }

    // we assumed arr[0] is already sorted
}