#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void selection_sort(int arr[ ],int n){
    int min,temp;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
                min=j;
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    printf("elements after sorting :\n");
    for(int i=0;i<n;i++){
        printf("%d->",arr[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    clock_t start,end;
    int n,arr[100];
    // insert code here...
    printf("enter the number of elements in the array :");
    scanf("%d",& n);
    printf("enter the elements of the array :\n");
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
    printf("elements are initialized in array\n");
    printf("selection sort :\n");
    start=clock( );
    selection_sort(arr,n);
    end=clock( );
    printf("time required is %.8f\n",((double)(end-start)/CLOCKS_PER_SEC));
    return 0;
}