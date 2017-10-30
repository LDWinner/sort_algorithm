#include <iostream>
using namespace std;

void ShellInsertSort(int *data,int size,int dk)
{
    for(int tmp = 0; tmp < dk; tmp++)
    {
        int i = tmp + dk;
        for(; i < size; i+=dk)
        {
            int value = data[i];
            int j = i - dk;
            while(j >= 0 && value < data[j])
            {
                data[j + dk] = data[j];
                j -= dk;
            }
            data[j + dk] = value;
        }
        for(int i = 0;i < size;i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
}

void shellSort(int a[],int n)
{
    int dk = n / 2;
    while(dk >= 1)
    {
        ShellInsertSort(a,n,dk);
        dk = dk / 2;
    }
}


int main()
{
    int a[8] = {3,1,5,7,2,4,9,6};
    shellSort(a,8);
    for(int i = 0;i < sizeof(a) / sizeof(int);i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}
