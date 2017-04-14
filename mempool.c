#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct _mem_node
{
    struct _mem_node *next;
    void *ptr;//points to memory block
    int node_size;
};

struct _mem_node_list
{
    struct _mem_node_list *next;
    struct _mem_node *head;
    int node_size;
};

typedef struct _mem_node mem_node;
typedef struct _mem_node_list mem_node_list;
mem_node_list *head = NULL;


void init_pool()
{
    mem_node_list *tmp_ptr;
    int i = 0;
    for(i = 0;i < 5;i++)
    {
        mem_node *node_ptr = NULL;
        mem_node_list *tmp_node_list = (mem_node_list*)malloc(sizeof(mem_node_list));
        tmp_node_list->node_size = sizeof(int) * pow(2,i);
        if(i == 0)
        {
            head = tmp_node_list;
            tmp_ptr = head;
        }
        int j;
        for(j = 0;j < 5;j++)
        {
            mem_node *tmp_node = (mem_node*)malloc(sizeof(mem_node));
            tmp_node->next = NULL;
            tmp_node->ptr = malloc(sizeof(int) * pow(2,i));
            tmp_node->node_size = sizeof(int) * pow(2,i);
            if(j == 0)
            {
                tmp_node_list->head = tmp_node;
            }
            else
            {
                tmp_node->next = tmp_node_list->head;
                tmp_node_list->head = tmp_node;
            }
        }
        tmp_ptr->next = tmp_node_list;
        tmp_ptr = tmp_node_list;
    }
    tmp_ptr->next = NULL;
}

mem_node *GetMemory(int size)
{
    mem_node_list *ptr = head;
    while(ptr->next != NULL)
    {
        if(ptr->node_size >= size)
        {
            if(ptr->head != NULL)
                return ptr->head;
            else
            {
                int i = 0;
                for(i = 0; pow(2,i) / size == 0 ;i++)
                {
                }
                mem_node *tmp_node = (mem_node*)malloc(sizeof(mem_node));
                tmp_node->next = NULL;
                tmp_node->ptr = malloc(sizeof(int) * pow(2,i));
                tmp_node->node_size = sizeof(int) * pow(2,i);
                ptr->head = tmp_node;
                return tmp_node;
            }
        }
        ptr++;
    }
    printf("size if too big,please use malloc\n");
    return NULL;
}

void ReleseMemory(mem_node *node)
{
    mem_node_list *ptr = head;
    while(ptr->next != NULL)
    {
        if(node->node_size == ptr->node_size)
        {
            node->next = ptr->head->next;
            ptr->head = node;
            printf("release success\n");
            return;
        }
        ptr++;
    }
    printf("release memory error\n");
    return;
}

void destory_memory()
{
}

int main()
{
    init_pool();
    mem_node *node = GetMemory(sizeof(int) * 4);
    int *p = (int*)(node->ptr);
    *p = 4;
    ReleseMemory(node);
}

