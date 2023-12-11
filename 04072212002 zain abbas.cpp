#include <iostream> 
using namespace std;

void selectionsort(int arra[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mid_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arra[mid_index] > arra[j])
            {
                mid_index = j;
            }
        }
        if (i != mid_index)
        {
            swap(arra[mid_index], arra[i]);
        }
    }
}

void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int cvalue = arr[i];
        int j = i - 1;
        for (j; j >= 0 && arr[j] > cvalue; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = cvalue;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* array = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i + 1] < array[i])   // chacking number of violations
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << "the array is already sorted ";
    }
    else if (count < n / 4)
    {
        insertionsort(array, n);               // calling the funcation 
        cout << "Using insertion sort" << endl;
        cout << "Number of violations: " << count << endl;
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
        {                                         // display the sorted array 
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else
    {
        selectionsort(array, n);
        cout << "Using selection sort" << endl;
        cout << "Number of violations: " << count << endl;
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
        {                                         // display the sorted array 
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    

    delete[] array;
    return 0;
}
