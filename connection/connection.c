#include <stdio.h>

#define N    1000


int weighted_quick_union();

int main()
{
    
#if 0
   int i,j,id[N];
   int p,q;
   for(i = 0;i < N; i++)
       id[i] = i;
   while(scanf("%d %d",&p,&q) == 2)
   {
    for(i = p; i != id[i]; i = id[i]);
    for(j = q; j != id[j]; j = id[j]);
    if(i == j) continue;
    id[i] = j;
    printf("%d %d\n",p,q);     
   } 
#endif
   weighted_quick_union();
   getchar();
   return 0;
    
}


int weighted_quick_union()
{
   int i,j,id[N],size[N];
   int p,q;
   for(i = 0;i < N; i++)
   {
       id[i] = i;
       size[i] = 1;
   }
   
   while(scanf("%d %d",&p,&q) == 2)
   {
    for(i = p; i != id[i]; i = id[i]);
    for(j = q; j != id[j]; j = id[j]);
    if(i == j) continue;
    
    if(size[i] > size[j])
    {
     id[j] = i;
     size[i] += size[j];
    }else
    {
     id[i] = j;
     size[j] += size[i];    
    }
    printf("%d %d\n",p,q);     
   } 
   
 //  getchar();
   return 0;   
} 
