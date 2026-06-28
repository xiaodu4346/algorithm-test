#include <iostream>
#include <vector>

using namespace std;

// void bubbleSort(vector<int>& array) {
//     for (int i = 0; i < array.size(); i++) {
//         for (int j = 0; j < array.size() - 1 - i; j++) {
//             if (array[j] > array[j + 1]) {
//                 int temp = array[j + 1];
//                 array[j + 1] = array[j];
//                 array[j] = temp;
//             }
//         }
//     }
// }
    
//冒泡排序
// int main() {
//     //实现冒泡排序
//     vector<int>array1;
//     array1.push_back(20);
//     array1.push_back(123);
//     array1.push_back(415);
//     array1.push_back(257);
//     array1.push_back(398);
//     array1.push_back(234);

//     bubbleSort(array1);
//     for (int i = 0; i < array1.size(); i++) {
//         cout << array1[i] << endl;
//     }
// }

// //选择排序
// void selectSort(vector<int> & array) {
//     for (int i=0;i<array.size()-1;i++) {
//         for (int j=i+1;j<array.size();j++) {
//             if(array[j]<array[i]) {
//                 int temp = array[j];
//                 array[j] = array[i];
//                 array[i] = temp;
//             }
//         }
//     }
    
// }


int main () {

    vector<int>array2;
    array2.push_back(20);
    array2.push_back(123);
    array2.push_back(415);
    array2.push_back(257);
    array2.push_back(398);
    array2.push_back(234);

  
    for (int i = 0; i < array2.size(); i++) {
    cout << array2[i] << endl;
    }



}