#include<iostream>
#include <cmath>
using namespace std;

void PrintResult(int*arr,int n)
{
    for (int i=1; i!= n+ 1;++i)
         cout <<"("<< i << ","<< arr[i]<< ")"<<"";
     cout << endl;
}

bool Verify(int*arr,int i)
{
    /* ��ǰ���i - 1�бȽϣ�����ǰ����λ���Ƿ�Ϸ���*/
    for (int k = 1; k != i;++k)
        if (arr[k]== arr[i]|| abs(i - k)== abs(arr[i]- arr[k]))
            return false;
    return true;
}
/* ��Ȼֻ����һ��һά���飬���������Ѿ��������㹻����Ϣ��
��Ϊÿһ��ֻ�ܷ�һ���ʺ�����һά����ĵ�i��λ�ô�ŵ�
���ڵ�i�е���һ�У���j�У��Ϸ����˻ʺ�����ݹ麯��
ÿ�δ���һ�У�ֱ����n�У��±��1��ʼ����*/
void NQueens(int*arr,int i, int n)
{
    /* �������ڵ�i�еĵ�j�з���һ���ʺ�*/
    for (int j = 1; j != n+1;++j)
     {
         arr[i] = j;
         printf("i = %d, j =%d\n",i,j);
        if (Verify(arr, i))
         {
            /* ����ݹ����Ľ��������ǵ�n�з�����ϣ�
             ���ԣ����ݹ麯���ӵ���NQueens(arr, i + 1, n)����ʱ��
             ���ǻص��˵�i�У������������ʵ�λ�á�����i + 1�е�
             ����λ�ö����������ʱ������ĵ��þͻ᷵�أ�Ҳ��
             �ǽ�������ν�Ļ��ݡ�������ݲ���Ҫ��ʾ�Ļָ���ǰ��
             ���û�������Ϊ����Ҫ����Ϣû�б��ƻ���*/
            if (i== n)
                 PrintResult(arr, n);
            else
                 NQueens(arr, i +1, n);//��һ�з��ûʺ�
         }
     }
}

/*
void backtrack (int t) �ݹ���ݵ�ģ�� 
{
if (t>n) output(x);
else
for (int i=f(n,t);i<=g(n,t);i++) {
x[t]=h(i);
if (constraint(t)&&bound(t)) backtrack(t+1);
}
}
*/
int main()
{
    int n;
     cin >> n;
    int *arr =new int[n +1];
     NQueens(arr, 1, n);
     system("pause");
    return 0;
}
