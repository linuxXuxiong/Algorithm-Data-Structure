#include <stdio.h>

struct node{
       int item;
       struct node *next;       
};
typedef struct node *link;

//int josephur_function(List)
int main()
{
  int i = 0;
  int s = 0;
  int N = 10;
  int M = 5;
  link x;
  link head = malloc(sizeof(struct node));
   
  head->item = 1;
  x = head; 
  head->next = head;
  for(i = 2 ; i <= N; i++)
  {
     x->next = malloc(sizeof(struct node));
     x = x->next;
     x->item = i;
     x->next = head;
  }
  while(x != x->next)
  {
   for(i = 1; i < M; ++i) x = x->next;
   x ->next = x->next->next;        
  }
  printf("%d\n",x->item);
  
  system("pause");
  return 0;
}


