#include <stdio.h>
#include <time.h>
int linearSearch(int arr[],int l,int h,int ele){
    if(l>h){
        return -1;
    }
    if(arr[l]!=ele){
        return linearSearch(arr, ++l, h, ele);
    }
    else{
        return l;
    }
    return -1;
}
int binarySearch(int arr[],int l,int h,int ele){
    int mid=(l+h)/2;
    if(arr[mid]==ele){
        return mid;
    }
    else if(ele>arr[mid]){
        l=mid+1;
        return binarySearch(arr, l, h, ele);
    }
    else{
        h=mid-1;
        return binarySearch(arr, l, h, ele);
    }
    return -1;
}

int main( ){
    int arr[30],n,i,ele,opt,pos;
    time_t start,end;
    printf("Enter the number of elements in the array :");
    scanf("%d",& n);
    for(i=0;i<n;i++){
        scanf("%d",& arr[i]);
    }
    printf("Enter element to be searched :");
    scanf("%d",& ele);
    printf("enter 1 : linear search\nenter 2 : binary search\n");
    scanf("%d",& opt);
    if(opt==0){
        start=time(NULL);
        pos=linearSearch(arr,0,n-1,ele);
        end=time(NULL);
    }
    else{
        start=time(NULL);
        pos=binarySearch(arr,0,n-1,ele);
        end=time(NULL);
    }
    printf("element found at %d index\n",pos);
    printf("time : %.4f\n",difftime(end, start));
}