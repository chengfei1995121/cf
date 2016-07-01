#include<stdio.h>
#include<stdlib.h>
static int m_heap[30];
static int m_size=0;
int get_weizhi(int data)
{
	int i;
	for(i=0;i<=m_size;i++)
	{
		if(data==m_heap[i])
		{	return i;
		    break;
		}
	}
	return -1;
}
static void filheap(int start)
{
	int c=start;
	int p=(c-1)/2;
	int tem=m_heap[c];
	while(c>0)
	{
		if(tem>m_heap[p])
			break;
		else
		{
			m_heap[c]=m_heap[p];
			c=p;
			p=(p-1)/2;
		}
	}
	m_heap[c]=tem;
}
void insert(int n)
{
	m_heap[m_size]=n;
	filheap(m_size);
	m_size++;
}
static void fildown(int start,int end)
{
	int c=start;
	int p=2*c+1;
	int tem=m_heap[c];
	while(p<=end)
	{
		if(p<end&&m_heap[p]>m_heap[p+1])
			p++;
		if(tem<m_heap[p])
			break;
		else
		{
			m_heap[c]=m_heap[p];
			c=p;
			p=(2*p)+1;
		}
	}
	m_heap[c]=tem;
}
int delete(int data)
{
	int n;
	n=get_weizhi(data);
	if (n == -1)
		return -1;
	m_heap[n]=m_heap[--m_size];
	fildown(n,m_size-1);
	return 0;
}
void printfheap()
{
	int i;
	for(i=0;i<m_size;i++)
	{
		printf("%d ",m_heap[i]);
	}
}
int main()
{
	int a[10]={80,20,30,40,50,13,16,18,39,27};
	int i;
	for(i=0;i<10;i++)
	{
		insert(a[i]);
	}
	printfheap();
	printf("\n");
	i=30;
	delete(i);
	printfheap();
	printf("\n");
	return 0;
}