#include <iostream>
using namespace std;

void binarySearch(int *arr, int LB, int UB, int item){
    int beg = LB, end = UB, mid = (beg + end)/2, loc;
    while (beg <= end && arr[mid] != item)
    {
        if(item < arr[mid]){
            end = mid - 1;
        }
        else{
            beg = mid + 1;
        }
        mid = (beg + end)/2;
    }

    if(arr[mid] == item){
        loc = mid;
        cout << "Item found at location "<< loc + 1<< endl;
    }
    else{
        cout << "Item not found!" << endl;
    }
    
}

int main(){
    int arr[] = {2,3,5,6,7,8,9};
    int LB = 0, UB = 6, item = 3;
    binarySearch(arr, LB, UB, item);
    return 0;
}