#include <iostream>

using namespace std;

#define LEFT(n) 2*n+1
#define RIGHT(n) 2*n+2

void MaxHeap(int *data,int i,int size)
{
    int large_index;
    int l = LEFT(i);
    int r = RIGHT(i);
    if(l < size && data[l] > data[i])
        large_index = l;
    else
        large_index = i;
    if(r < size && data[r] > data[large_index])
        large_index = r;
    if(large_index != i)
    {
        data[large_index] = data[large_index] ^ data[i];
        data[i] = data[large_index] ^ data[i];
        data[large_index] = data[large_index] ^ data[i];
        MaxHeap(data,large_index,size);
    }
}


void BuidHeap(int *data,int size)
{   
    for(int i = size / 2 - 1;i >= 0;i--)
    {
        MaxHeap(data,i,size);
    }
}

int data[] = {2,5,6,8,10,1,4,3};
void HeapSort()
{
    int size = sizeof(data)/sizeof(int);
    BuidHeap(data,size);
    for(int i = size - 1; i > 0 ;i--)
    {
        data[0] = data[0] ^ data[i];
        data[i] = data[0] ^ data[i];
        data[0] = data[0] ^ data[i];
        MaxHeap(data,0,i);
    }
}

int main()
{
    HeapSort();
    for(int j = 0;j < 8 ;j++)
        cout<< data[j] << endl;
    return 0;
}

