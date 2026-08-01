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

// //插入排序
// void insertionSort(vector<int> & array) {
//     for (int i=1;i<array.size();i++) {
//         int key=array[i];
//         int j=i-1;

//         while(j>=0 && array[j]>key) {
//             array[j+1] = array[j];
//             j--;
//         }
//         array[j+1] =key;
//     }

 
// }

//归并排序
void merge(vector<int>& array, int left, int mid, int right) {
    vector<int> temp;

    int i = left;      // 指向左边区间的开头
    int j = mid + 1;   // 指向右边区间的开头

    // 左右两边都还有元素时，谁小就先放进 temp
    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp.push_back(array[i]);
            i++;
        } else {
            temp.push_back(array[j]);
            j++;
        }
    }

    // 如果左边还有剩余元素，全部放进 temp
    while (i <= mid) {
        temp.push_back(array[i]);
        i++;
    }

    // 如果右边还有剩余元素，全部放进 temp
    while (j <= right) {
        temp.push_back(array[j]);
        j++;
    }

    // 把排好序的 temp 放回原数组对应位置
    for (int k = 0; k < temp.size(); k++) {
        array[left + k] = temp[k];
    }
}

// 归并排序：排序 array[left] 到 array[right] 这一段
void mergeSort(vector<int>& array, int left, int right) {
    // 如果这一段只有 0 个或 1 个元素，就不用排序
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    // 排左半边
    mergeSort(array, left, mid);

    // 排右半边
    mergeSort(array, mid + 1, right);

    // 把两个已经有序的半边合并
    merge(array, left, mid, right);
}
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
