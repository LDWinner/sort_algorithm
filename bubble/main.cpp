#include <iostream>

using namespace std;

void bubble(int *data,int size)
{
    for(int i = 0;i < size;++i)
    {
        for(int j = 1;j < size - i;++j)
        {
            if(data[j - 1] > data[j])
                swap(data[j-1],data[j]);
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
