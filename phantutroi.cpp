#include<iostream>

using namespace std;
int count_Element(int a[], int left ,int right, int x){
    int count = 0;
    for(int i= left ; i <= right; i++ ){
        if(a[i]==x){
            count++;
        }
    }
    return count;
}
int majority_Element(int a[],int left,int right){
    if(left == right){
        return a[left];
    }
    int mid = left +(right-left)/2;
    int left_major = majority_Element(a,left,mid);
    int right_major= majority_Element(a,mid+1,right);
    if(left_major == right_major){
        return left_major;
    }

    int left_Count = count_Element(a , left,right, left_major);
    int right_Count= count_Element(a,left ,right, right_major);
    if(left_Count > n/2){
        return left_major;
    }
    if(right_Count > n/2){
        return right_major;
    }
    return -1;

}
int main(){
    int a[] = {2, 2, 1, 2, 3, 2, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int result = majority_Element(a, 0, n - 1);
    if (result != -1) {
        cout << "Phan tu troi la: " << result;
    }
    else {
        cout << "Khong co phan tu troi";
    }
    return 0;
}