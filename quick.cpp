#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}



int main() {
    int n;
    cout << "Enter number of elements: "; 
    cin >> n;
    cout << "\n";
    int arr[n];
    
    for(int i =0; i<n; i++){
        arr[i] = rand() % 100000;
    }

    auto start = high_resolution_clock::now();
    quickSort(arr , 0, n-1);
    auto stop = high_resolution_clock::now();

    for(int i =0; i<n; i++){
        cout << arr[i] << endl;
    }

    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    return 0;
}
