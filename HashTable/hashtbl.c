#include <stdio.h>
#include "hashtbl.h"


struct ListNode
{
 ElementType Element;
 struct ListNode *next;
};

typedef Position List;

struct HashTbl
{
 int TableSize;
 List *TheLists;
};

int Hash(ElementType key,int TableSize)
{
 int pos = 0;
 pos = key % 10; 
 return pos;           
}
HashTable InitializeTable(int TableSize)
{
  HashTable Htlb;
  int i;
  
  if(TableSize < MiniTableSize)
  {
   printf("Table size too small\n");
   return NULL;             
  }         
  Htlb = malloc(sizeof(struct HashTbl));
  if(Htlb == NULL)
  {
   printf("no enough memory\n");
   return NULL;
  }
  
  Htlb->TableSize = TableSize;
  Htlb->TheLists = malloc(sizeof(List) * TableSize);
  if(Htlb->TheLists == NULL)
  {
   printf("no enough memory\n");
   return NULL;
  }
  
  for(i = 0; i < TableSize; i++)
  {
   Htlb->TheLists[i] = malloc(sizeof(struct ListNode));
   if(Htlb->TheLists[i] == NULL)
       printf("no enough memory");
   else
      Htlb->TheLists[i]->next = NULL; 
  }
  
  return Htlb;
}

Position Find(ElementType Key,HashTable H)
{
 Position P;
 List L;
 L = H->TheLists[Hash(Key,H->TableSize)];
 P = L->next;
 while(P != NULL && P->Element != Key)
      P = P->next;
 return P;
}

void Insert(ElementType Key,HashTable H)
{
 int index = 0;
 Position P;
 List L;
 
 P = Find(Key,H);
 if(P != NULL)
   return;
 L = H->TheLists[Hash(Key,H->TableSize)];
 P = malloc(sizeof(struct ListNode));
 P->Element = Key;
 P->next = L->next;
 L->next = P; 
}


int main()
{
 int a[5] = {1,4,9,16,25};
 int i;
 HashTable H;
 Position p = NULL;
 H = InitializeTable(10);

 for(i = 0; i < 5; i++)
 {
  Insert(a[i],H); 
 }
 p = Find(4,H);
 if(p != NULL)
 printf("find key %d\n",p->Element);

 system("pause");
 return 0;   
}
