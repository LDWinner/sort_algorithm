#include <iostream>

using namespace std;

int partition(int *data,int l,int r)
{
    int key = data[l];
    int i = l;
    int j = r;
    while(i < j)
    {
        while (data[j] > key && i < j) {
            --j;
        }
        data[i] = data[j];
        while (data[i] <= key && i < j) {
            ++i;
        }
        data[j] = data[i];
    }
    data[i] = key;
    return i;
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
