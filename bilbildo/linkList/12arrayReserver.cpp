#include <iostream>

using namespace std;

void reserver12(int array[],int size) {
    int* left = array;
    int* right = array+size-1;
    while(left < right)
    {
        if ((*left & 0x1) == 1) {
            left++;
            continue;
        };
        if ((*right & 0x1) == 0) {
            right--;
            continue;
        }

        int a = *left;
        *left = *right;
        *right = a;
        left++;
        right--;
    }
}

int main() {
    int array[] = {3,5,67,87,34,4,23,56,12};
    reserver12(array,(sizeof(array)/sizeof(array[0])));
    for (const int a:array) {
        cout << a << ' ';
    }

}