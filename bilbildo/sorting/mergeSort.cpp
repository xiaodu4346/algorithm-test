#include <iostream>
#include <vector>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    vector<int>brr;
    int i = left;
    int j = mid+1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[mid+1]) {
            brr.push_back(arr[i]);
            i++;
        }
        else  {
           brr.push_back(arr[j]);
           j++;
        }
    }
    while (i <= mid) {
       brr.push_back(arr[i++]);
    }
    while (j <= right) {
        brr.push_back(arr[j++]);
    }
    int k = left;
    for (int temp : brr)
    {
        arr[k++] = temp;
    }
}

void mergeSort(int arr[],int i, int j) {
    if (i >= j) {
        return;
    }
    int mid = (i + j)/2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);
    merge(arr, i, mid, j);

}
int main() {




}