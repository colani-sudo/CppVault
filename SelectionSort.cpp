#include <iostream>

void printArr(int *arr, int n){
    std::cout << "\n[";
    for(int i=0; i<n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]";
}
void sort(int *arr, int n){
    int i,j;
    int min;
    for(i=0;i<n;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[min] > arr[j])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int arr[] = {4,3,7,8,1};
    sort(arr,5);
    printArr(arr,5);
    return 0; 
}