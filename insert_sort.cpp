#include <iostream>

using namespace std;


void insert_sort(int *data,int size)
{
    for(int i = 1;i < size;++i)
    {
        int value = data[i];
        int j = i - 1;
        while(j >= 0 && data[j] > value)
        {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = value;
    }
}

int main()
{
    int data[] = {2,3,1,6,2,8,4,3};
    insert_sort(data,sizeof(data)/sizeof(int));
    for(int i = 0;i < 8;i++)
        cout << data[i] <<endl;
    return 0;
}

