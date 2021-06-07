#include <stdio.h>
#include<stdlib.h>
  #include <time.h>
  
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
  
  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  
  // Print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  // Driver code
  int main() {
      int n, i, j, temp,c;
      while(1){
      printf("enter n\n");
      scanf("%d",&n);
    int arr[n];
      printf("Genrating random nos.:\n");
   srand(time(0));
  for (c = 0; c < n; c++){
    arr[c]=rand()%100 +1;
    printf("%d ",arr[c]);
   }
    clock_t begin = clock();
  
    heapSort(arr, n);
  
    printf("  Sorted array is \t");
    printArray(arr, n);
     clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\n\nEXECUTION TIME : %.10fseconds\n", time_spent);
      }
  }