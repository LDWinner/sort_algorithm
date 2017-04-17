#include <iostream>

using namespace std;

void ShellInsertSort(int a[],int n,int dk)
{
    for(int i = dk;i < n;i++)
    {
        if(a[i] < a[i - dk])
        {
            int value = a[i];
            int j = i;
            while(value < a[j - dk] && j - dk >= 0)
            {
                a[j] = a[j - dk];
                j = j - dk;
            }
            a[j] = value;
        }
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
}
