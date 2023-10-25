#include<iostream>
using namespace std;

// Sắp xếp chọn     - selection sort
void SelectionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int min = i;
        for(int j = i + 1; j < size; j++)
            if(arr[min] > arr[j]) min = j;
        swap(arr[i], arr[min]);
    }
}
// Sắp xếp chèn     - insertion sort
void InsertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int j = i;
        while(j != 0 && arr[j - 1] > arr[j])
            swap(arr[j - 1], arr[j--]);
    }
}
// Sắp xếp nổi bọt  - bubble sort
void BubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - 1 - i; j++)
            if(arr[j] > arr[j + 1]) swap(arr[j + 1], arr[j]);
}
// Sắp xếp trộn     - merge sort
void merge(int a[], int b[], int arr[], int size_a, int size_b){
    int i = 0, j = 0, k = 0;
    while(i < size_a && j < size_b)
        if(a[i] < b[i]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    while(i < size_a) arr[k++] = a[i++];
    while(j < size_b) arr[k++] = b[j++];
}
void MergeSort(int arr[], int size){
    if(size < 2) return;
    int half = size/2;
    int a[half], b[size - half];
    for(int i = 0; i<half; i++) a[i] = arr[i];
    for(int i = half; i<size; i++) b[i - half] = arr[i];
    MergeSort(a, half);
    MergeSort(b, size - half);
    merge(a, b, arr, half, size - half);
}

// Sắp xếp nhanh    - quick sort
// int partition(int arr[], int first, int last){
//     int pivot = arr[first], cnt = first;
//     for(int i = first + 1; i <= last; i++)
//         if(arr[i] <= pivot) swap(arr[++cnt], arr[i]);
//     swap(arr[first], arr[cnt]);
//     return cnt;
// }
// void QuickSort(int arr[], int first, int last){
//     if(first < last){
//         int pivot = partition(arr, first, last);
//         QuickSort(arr, first, pivot - 1);
//         QuickSort(arr, pivot + 1, last);
//     }
// }
int partirion( int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
        for(int j = 0; j < r; j++){
            if(a[j]<= pivot){
                ++i;
                swap(a[j], a[i]);
            }
        }
        ++i;
        swap(a[i],a[r]);
        return i;
}
void quickSort(int a[], int l, int r){
    if(l<r){
        int p = partirion(a, l, r);
        quickSort(a, l, p-1);
        quickSort(a, p+1, r);
    }
    else return ;
}
int main(){
    int a[] = {7, 6, 5, 4, 3, 2, 1};
    quickSort(a, 0, 7);
    
    for(int i=0; i<7; i++) cout << a[i] << " ";
}



