#include <iostream>
using namespace std;

void merge(int arr[],int left,int mid,int right){
    int n1= mid-left;
    int n2=right - mid;
    int le[n1] , ri[n2];
    for(int i= 0; i< n1 ; i++){
        le[i]= arr[left +i];
    }
    for (int j =0;j<n2 ; j++){
        ri[j]= arr[mid +1 + j];
    }
    int i=0, j = 0, k= left;
    // so sanh(quan trong)
    while(i< n1 && j< n2){
        if(le[i] <= ri[j]){
            arr[k] = le[i];
            i++;
        } else{
            arr[k] = ri[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = le[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k]=le[i];
        j++;
        k++;
    }
}
void merge_Sort(int arr[], int left, int right){
    if(left < right){
        int mid = left +(right-left)/2;
        merge_Sort(arr,left,mid);
        merge_Sort(arr, mid+1 ,right);
        merge(arr, left, mid, right);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    merge_Sort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}