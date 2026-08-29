void shellSort(int arr[], int size) {
    for (int gap = size/2; gap > 0; gap/=2) {
        for (int i = gap; i < size; i++) {
        int val = arr[i];
        int j = i - gap;
            while (j >= 0 && arr[j]>val) {
            arr[j+gap] = arr[j];
            j-=gap;
        }
        arr[j+gap] = val;
    }
}
}