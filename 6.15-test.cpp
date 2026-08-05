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

//快速排序

int partitionArray(vector<int>& array, int left, int right) {
    int pivot = array[right];
    int i = left;
    for (int j = left;j < right;j++) {
        if (array[j] <= pivot) {
            swap(array[i],array[j]);
            i++;
        }
    }
    swap(array[i],array[right]);
    return i;
}

void quick(vector<int>& array, int left,int right) {
    if (left >= right) {
       return;
    }

    int pivoIndex = partitionArray(array, left, right);

    quickSort(array, left, pivotIndex - 1);

    quickSort(array,pivoIndex + 1,right);
}


//堆排序

void heapify(vector<int>& array, int heapSize, int i) {
    int largest = i;

    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    // 检查左孩子是否更大
    if (leftChild < heapSize &&
        array[leftChild] > array[largest]) {
        largest = leftChild;
    }

    // 检查右孩子是否更大
    if (rightChild < heapSize &&
        array[rightChild] > array[largest]) {
        largest = rightChild;
    }

    // 如果最大的不是父节点，就交换并继续向下调整
    if (largest != i) {
        swap(array[i], array[largest]);

        heapify(array, heapSize, largest);
    }
}

void heapSort(vector<int>& array) {
    int size = static_cast<int>(array.size());

    // 从最后一个非叶子节点开始，建立最大堆
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    // 每次把堆顶最大值放到数组末尾
    for (int i = size - 1; i > 0; i--) {
        swap(array[0], array[i]);

        // i 后面的部分已经排好，只调整前面的堆
        heapify(array, i, 0);
    }
}


void countingSort(vector<int>& array) {
    if (array.empty()) {
        return;
    }

    int minValue = *min_element(array.begin(), array.end());
    int maxValue = *max_element(array.begin(), array.end());

    // 例如 minValue = -2，maxValue = 3
    // 那么一共需要记录 -2、-1、0、1、2、3，共 6 个数
    long long range =
        static_cast<long long>(maxValue) - minValue + 1;

    vector<int> count(static_cast<size_t>(range), 0);

    // 统计每个数出现的次数
    for (int value : array) {
        int index = value - minValue;
        count[index]++;
    }

    // 按照从小到大的顺序写回原数组
    int arrayIndex = 0;

    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            array[arrayIndex] = i + minValue;
            arrayIndex++;

            count[i]--;
        }
    }
}



// 对一个桶使用插入排序
void insertionSortBucket(vector<int>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(vector<int>& array, int bucketSize = 100) {
    if (array.empty()) {
        return;
    }

    if (bucketSize <= 0) {
        throw invalid_argument("bucketSize 必须大于 0");
    }

    int minValue = *min_element(array.begin(), array.end());
    int maxValue = *max_element(array.begin(), array.end());

    long long difference =
        static_cast<long long>(maxValue) - minValue;

    int bucketCount =
        static_cast<int>(difference / bucketSize + 1);

    vector<vector<int>> buckets(bucketCount);

    // 把每个数放入对应的桶
    for (int value : array) {
        int bucketIndex = (value - minValue) / bucketSize;
        buckets[bucketIndex].push_back(value);
    }

    int arrayIndex = 0;

    // 每个桶内部排序，然后依次写回原数组
    for (vector<int>& bucket : buckets) {
        insertionSortBucket(bucket);

        for (int value : bucket) {
            array[arrayIndex] = value;
            arrayIndex++;
        }
    }
}



// 根据某一位进行稳定的计数排序
void countingSortByDigit(vector<int>& array, long long exp) {
    int size = static_cast<int>(array.size());

    vector<int> output(size);
    vector<int> count(10, 0);

    // 统计这一位上的数字
    for (int value : array) {
        int digit = static_cast<int>((value / exp) % 10);
        count[digit]++;
    }

    // 转换成最终位置
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 必须从右向左遍历，以保持稳定性
    for (int i = size - 1; i >= 0; i--) {
        int digit =
            static_cast<int>((array[i] / exp) % 10);

        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    // 写回原数组
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void radixSort(vector<int>& array) {
    if (array.empty()) {
        return;
    }

    // 这个入门版本不处理负数
    for (int value : array) {
        if (value < 0) {
            throw invalid_argument(
                "当前 radixSort 版本只支持非负整数"
            );
        }
    }

    int maxValue =
        *max_element(array.begin(), array.end());

    // exp 分别表示个位、十位、百位……
    for (long long exp = 1;
         maxValue / exp > 0;
         exp *= 10) {
        countingSortByDigit(array, exp);
    }
}
