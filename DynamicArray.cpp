/******************************************************************************
Implement Own Dynamic Vector
*******************************************************************************/
#include <iostream>
using namespace std;

// Global Varaibles
int currentSize = 0;
int capacity = 10;
int *a = new int[capacity];

// Helper functions
int get(int index)
{
    if(index<0 || index>currentSize)
        return -1;
    else
       return a[index];
}

int set(int index, int value)
{
    if(index<0 || index>currentSize)
        return -1;
    else
       a[index] = value;
}

void push_back(int value)
{
    // cout<<"value :"<<value<<endl;
    // cout<<"currentSize:"<<currentSize<<endl;
    // cout<<"capacity:"<<capacity<<endl;
    
    if(currentSize == capacity)
    {
        cout<<"Re allocation required"<<endl;
        int *temp = new int[capacity*2];
        for(int i=0;i<currentSize;++i)
        {
            temp[i] = a[i];
        }
        delete[] a;
        capacity = capacity*2;
        a = temp;
    }
    a[currentSize] = value;
    currentSize = currentSize+1;
}

int remove(int index)
{
    if(index<=0 || index>currentSize)
        return -1;
    else
        for(int i = index;i<currentSize;++i)
        {
            a[i] = a[i+1];
        }
        currentSize = currentSize -1;
}

int getSize()
{
    return currentSize;
}

// Main Implementation
int main()
{
    //cout<<"All the Best for the preparation !!! Good Blessings"<<endl;
    cout<<"Before Vector size ->"<<getSize()<<endl;
    for(int i=0;i<10;++i)
    {
        push_back(i);
        cout<<" "<<get(i);
    }
    cout<<endl;
    cout<<"After Vector size ->"<<getSize()<<endl;
    cout<<"---Reallocation Execution---"<<endl;
    push_back(100);
    cout<<"After Reallocation Vector size ->"<<getSize()<<endl;
    cout<<a[getSize()-1]<<endl;
    return 0;
}



