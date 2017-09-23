#include <stdio.h>
typedef int ItemType ;

#define less(a,b)    ((a) < (b))
#define exch(a,b)    {ItemType tmp; tmp = a; a = b; b = tmp;}
#define cmpexch(a,b) if(less(b,a)) exch(a,b)

/***
selection sort 
input:
***/
void selection_sort(ItemType a[],int l,int r)
{
    int i,j;
    int min;
    int tmp;
    for(i = l; i < r; ++i)
    {    
         min = i;
         for(j = i + 1 ; j < r; ++j) // find mininum number index
         {
             if(a[j] < a[min])
                 min = j;  
         }
         //exchange two numbers
         tmp = a[i]; 
         a[i] = a[min];
         a[min] = tmp; 
     }   
}

/*
bubbling sort

*/
void bubbling_sort(ItemType a[],int l,int r)
{
    int i,j;
    for(i = l; i < r - 1; ++i)
    {    for(j = l; j < r - i - 1;++j)
        {
           cmpexch(a[j],a[j+1]);     
        }
    }
}

//insertion sort
void insertion_sort(ItemType a[],int l,int r)
{
    int i,j;
    ItemType t;
    for(i = r; i > l; --i) cmpexch(a[i-1],a[i]);
    for(i = l + 2; i < r; ++i)
    {   j = i;
        t = a[i];
        while(less(t,a[j - 1]))
        {
         a[j] = a[j - 1];
         j--;
        }
        a[j] = t;
    }     
}


void print_nums(ItemType a[],int length)
{
    int i;
    for(i = 0; i < length; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");     
}


int main(void)
{
   int a[10] = {8,6,7,10,20,4,9,50,60,33};
   printf("orignal arrays:"); 
   print_nums(a,10);
   bubbling_sort(a,0,10);
   printf("after sorting:"); 
   print_nums(a,10);
   system("pause"); 
   return 0;   
}
