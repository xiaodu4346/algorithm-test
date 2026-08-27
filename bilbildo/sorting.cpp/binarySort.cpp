#include <iostream>

using namespace std;


int binarySort(int array[], int size, int findx) {
    int left = 0;
    int right = size-1;

    while (left <= right) {
        int mid = (left+right)/2;
        if (array[mid] == findx) {
            cout << "Find!";
            return mid;
        }
        else if (array[mid] > findx) 
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    cout << "no!";

}


int main () {
    int arr[] = {2,4,5,6,7,8,9};
    binarySort(arr,7,1);
}