  #include <stdio.h>
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
  }
void inform(){
   printf("\nNAME - MANISH BHAGAT \nCLASS - BCA\nSECTION - A\nSUBJECT - DS LAB\n");

 }
  void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
     inform();
  }


   int main() {
    int arr[8], n, i;
    printf("\n-----------Enter Array of size 8 in random manner:------------------\n");

    for(i=0; i<=7; i++) {
	scanf("%d", &arr[i]);
    }

    n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);
}
