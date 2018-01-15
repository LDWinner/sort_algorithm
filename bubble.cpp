#include <iostream>

using namespace std;

void bubble(int *data,int size)
{
    for(int i = 0;i < size;++i)
    {
        for(int j = size - 1;j > i;--j)
        {
            if(data[j] < data[j - 1])
                swap(data[j],data[j - 1]);
        }
    }
}

int main()
{
    int data[] = {6,9,5,4,2,3,10};
    int size = sizeof(data)/sizeof(int);
    bubble(data,size);
    for(int i = 0;i < size;i++)
        cout << data[i] << endl;
    return 0;
}

