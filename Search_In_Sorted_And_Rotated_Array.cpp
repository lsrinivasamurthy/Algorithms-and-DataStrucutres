/******************************************************************************
Search in Sorted and Rotated Array
*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int search_sorted_rotated_array(vector<int> arr,int key)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low + high) /2;
        if(arr[mid] == key){
            return mid;
        }
        
        // check which part is already sorted ?
        if(arr[mid]>arr[0]){ // left half is sorted
            if(key >= arr[0] && key < arr[mid]){ // key lies in the range of sorted half.
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }
        else{ // Right half is sorted
            if(key>arr[mid] && key <=arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
    } // end of while loop- Binary Search
    return -1;
}

int main()
{
    cout<<"key found at :"<<search_sorted_rotated_array({5, 6, 7, 8, 9, 10, 1, 2, 3}, 10);
    return 0;
}
