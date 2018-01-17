#include <iostream>

using namespace std;

void selection_sort(int *data,int size)
{
    for(int i = 0; i < size; ++i)
    {
        int min = data[i];
        int min_index = i;
        for(int j = i; j < size; ++j)
        {
            if(min > data[j])
            {
                min = data[j];
                min_index = j;
            }
        }
        swap(data[i],data[min_index]);
    }
}

int main()
{
    int data[] = {20, 9, 5, 1, 4, 3, 7, 2, 2};
    int size = sizeof(data) / sizeof(int);
    selection_sort(data, size);
    for(int i = 0; i < size; i++)
        cout << data[i] << endl;
}
