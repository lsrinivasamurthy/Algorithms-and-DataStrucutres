/******************************************************************************
Allocate Min No of Pages
Book Allocation Problem
Max No of Pages allocated should be minimum.

Binary Search can be implemented if we know the search space
*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(const vector<int>& arr, int m, int barrier){
    int allocated_students = 1;
    int allocated_pages = arr[0];
    for(int i=1;i<arr.size();i++){
        if(allocated_pages + arr[i] <= barrier){
            allocated_pages+=arr[i];
        }
        else{
            allocated_students++;
            allocated_pages = arr[i];
        }
    }
    return (allocated_students <= m);
}

int allocate_books(const vector<int>& arr, int m)
{
    int n = arr.size();
    int low = arr[0];
    int high = arr[0];
    for(int i=1;i<n;i++){
        low = max(low,arr[i]);
        high += arr[i];
    }
    int result = high;
    
    while(low <= high){
        int mid = (low + high) / 2;
        if(isPossible(arr,m,mid)){
            result = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }// end of while Binary Search
    return result;
}

int main()
{
    cout << allocate_books({12, 34, 67, 90}, 2) << endl;
    return 0;
}
