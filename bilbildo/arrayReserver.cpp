#include <iostream>
#include <cstring>

using namespace std;

void reserve(char a[], int size)
{
    char* left = a;
    char* right = a+size-1;

    while (left < right) {

        char p = *right;
        *right = *left;
        *left = p;
        right--;
        left++;
    }

}

int main() {
    char array[] = "nihao wodeshhijie";
    reserve(array,strlen(array));
    cout << array;

}