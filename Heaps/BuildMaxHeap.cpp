#include<iostream>
using namespace std;

void buildMaxHeap(int & arr)
{
    int index = arr.size;

    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
        }
        index--;
    }
}
int main()
{
    int [] arr = {2,4,5,9,7};
    buildMaxHeap(arr);
    
    return 0;
}
