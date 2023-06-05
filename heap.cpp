/*Implementation of heap data structure using heap sort in cpp*/

#include <iostream>
using namespace std;

class heap1
{
public:
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            int loc = arr[i];
            arr[i] = arr[largest];
            arr[largest] = loc;
            heapify(arr, n, largest);
        }
    }

    void sort(int arr[], int n)
    {
        for (int k = n / 2 - 1; k >= 0; k--)
        {
            heapify(arr, n, k);
        }
    }

    void heapSort(int arr[], int n)
    {
        sort(arr, n);
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            heapify(arr, i, 0);
        }
    }

    void accept()
    {
        int n;
        cout << "Enter number of students: " << endl;
        cin >> n;
        int arr[n];
        cout << "Enter Marks: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        heapSort(arr, n);
        display(arr, n);
    }

    void display(int arr[], int n)
    {
        cout << "Sorted Array is : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }

        cout << "Minimum marks: " << arr[0] << endl;
        cout << "Maximum marks: " << arr[n - 1] << endl;
    }
};

int main()
{
    heap1 obj;
    obj.accept();
    return 0;
}