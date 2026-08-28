void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = arr[i];
        int k = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                k = j;
            } 
        }
        if (k!=i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }

}