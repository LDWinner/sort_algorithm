#include <iostream>
#include <algorithm>

using namespace std;

void merge(int *data,int l,int m,int r)
{
    int *a = new int[m - l + 1];
    int *b = new int[r - m];
    copy(&data[l],&data[m + 1],a);
    copy(&data[m + 1],&data[r + 1],b);
    int i = 0,j = 0,k = l;
    while(i <= m - l && j < r - m)
    {
        if(a[i] <= b[j])
        {
            data[k] = a[i];
            i++;
        }
        else
        {
            data[k] = b[j];
            j++;
        }
        k++;
    }
    if(i > m - l)
    {
        while(j < r - m)
        {
            data[k] = b[j];
            k++;
            j++;
        }
    }
    if(j >= r - m)
    {
        while(i <= m - l)
        {
            data[k] = a[i];
            i++;
            k++;
        }
    }
}

void merge_sort(int *data,int l,int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        merge_sort(data,l,m);
        merge_sort(data,m + 1,r);
        merge(data,l,m,r);
    }
}

int main()
{
    int data[] = {20,9,5,1,4,3,7,2,2};
    int size = sizeof(data)/sizeof(int);
    merge_sort(data,0,size - 1);
    for(int i = 0;i < size;i++)
        cout << data[i] << endl;
}
