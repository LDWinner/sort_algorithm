#include <iostream>

using namespace std;

int partition(int *data,int l,int r)
{
    int key = data[l];
    while(l < r)
    {
        while(data[r] > key && l < r)
        {
            --r;
        }
        //data[l] = data[r];
        swap(data[l],data[r]);
        while(data[l] <= key && l < r)
        {
            ++l;
        }
        swap(data[l],data[r]);
        //data[r] = data[l];
    }
   // data[l] = key;
    return l;
}

void quick_sort(int *data,int l,int r)
{
    if(l < r)
    {
        int p = partition(data,l,r);
        quick_sort(data,l,p - 1);
        quick_sort(data,p + 1,r);
    }
}

int main()
{
    int data[] = {2,6,1,33,5,4,88,2};
    quick_sort(data,0,7);
    for(int i = 0;i < 8;i++)
    {
        cout << data[i] << endl;
    }
}
