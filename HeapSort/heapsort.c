#include <stdio.h>
//#define Swap(x,y) (typeof(x) tmp; tmp = x, x = y; y = tmp)

static void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;        
}

void MinHeapFixDown(int a[],int i, int n)
{
 int j,tmp;
 
 tmp = a[i];
 j = 2 * i + 1;
 
 while(j < n)
 {
  if(j + 1 < n && a[j + 1] < a[j])
         j++;
  
  if(a[j] >= tmp)
          break;
  a[i] = a[j];
  i = j;
  j = 2 * i + 1;
 }
  a[i] = tmp;
}


void MinheapsortTodescendarray(int a[], int n)  
{  
    int i = 0;
    int tmp = 0;
    for (i = n - 1; i >= 1; i--)  
    {  
        //Swap(a[i], a[0]);
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;  
        MinHeapFixDown(a, 0, i);  
    }  
}  

void MakeMinHeap(int a[],int n)
{
    int i = 0;
    for(i = n / 2 - 1; i >= 0; --i)
        MinHeapFixDown(a,i,n);    
}

void HeapSort(int a[], int n)
{
  MakeMinHeap(a,n);
  MinheapsortTodescendarray(a,n);
}

int main(void)
{
   int a[10] =  {10,20,30,40,8,2,7,50,60,49};
   int i = 0;
   HeapSort(a,10);
   for(i = 0; i < 10; ++i)
   printf("%d ",a[i]);
   
   system("pause"); 
}
