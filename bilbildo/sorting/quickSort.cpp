#include <iostream>

using namespace std;

int findPivotPosition(int arr[], int L, int R) {
    int temp = arr[L];
    while (L<R) {
        while (L<R && arr[R] >= temp) {
            R--;
        }
        arr[L] = arr[R];
        while (L<R && arr[L] <= temp) {
            L++;
        }
        arr[R] = arr[L];
    }
    arr[L] = temp;
    return L;
}

void quickSort(int arr[], int L, int R) {
    if (L >= R) {
        return;
    }

    int position =  findPivotPosition(arr, L, R);
    quickSort (arr, L, position-1);
    quickSort (arr,position + 1, R);

}

int mian() {}
