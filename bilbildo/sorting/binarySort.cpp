#include <iostream>

using namespace std;

// 非递归实现
// int binarySort(int array[], int size, int findx) {
//     int left = 0;
//     int right = size-1;

//     while (left <= right) {
//         int mid = (left+right)/2;
//         if (array[mid] == findx) {
//             cout << "Find!";
//             return mid;
//         }
//         else if (array[mid] > findx) 
//         {
//             right = mid - 1;
//         }
//         else 
//         {
//             left = mid + 1;
//         }
//     }
//     cout << "no!";

// }
//递归实现
int binarySort (int array[], int left, int right, int val) {
    if (left > right) {
        return -1;
    }
    int mid = (left + right)/2;
    if (array[mid] == val) {
        return mid;
    }
    else if (array[mid] < val) {
        return binarySort(array, mid+1, right, val);
    }
    else {
        return binarySort(array, left, mid-1,val);
    }

}
int main () {
    int arr[] = {2,4,5,6,7,8,9};

    cout << binarySort(arr, 0, 6, 8) << endl;

}