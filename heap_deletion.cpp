#include<iostream>
using namespace std;
void restoreup(int h[], int chd)
{
	int parent = chd/2;
	while (h[parent] < h[chd]){
		int temp = h[chd];
		h[chd] = h[parent];
		h[parent] = temp;
		chd = parent;
		parent = chd/2;
	}
}
void restoredown(int h[],int start,int size)
{
	int lchildindex = 2*start;
	int rchildindex =2*start+1;
	while (rchildindex <= size)
	{
		if ( h[lchildindex] < h[start] && h[rchildindex] < h[start] )
		{
			return;
		}
		else if ( h[lchildindex] > h[start] && h[lchildindex] >= h[rchildindex] )
		{
			int temp = h[start];
			h[start] = h[lchildindex];
			h[lchildindex] = temp;
			start = lchildindex;
			lchildindex = 2*start;
			rchildindex = 2*start+1;
		}
		else if ( h[rchildindex] > h[start] &&  h[lchildindex] <= h[rchildindex])
		{
			int temp = h[start];
			h[start] = h[rchildindex];
			h[rchildindex] = temp;
			start = rchildindex;
			lchildindex = 2*start;
			rchildindex = 2*start+1;
		}
		else {
			continue;
		}
	}
	if ( lchildindex == size && h[lchildindex] > h[start])
	{
		int temp = h[start];
		h[start] = h[lchildindex];
		h[lchildindex] = temp;
	}	
}
void insert (int h[],int *hsize,int value)
{
	(*hsize)++;
	h[*hsize] = value;
	restoreup(h,*hsize);
}
void print ( int h[],int *hsize){
	if (*hsize == 0)
	{
		cout<<"Empty Heap";
		return;
	}
	else
	{
		for (int i=1;i <= (*hsize);i++)
		{
			cout<<h[i]<<endl;
		}
	}
}
void del (int h[],int max,int *hsize)
{
	h[1] = h[*hsize];
	(*hsize)--;
	restoredown(h,1,*hsize);
	return;
}
int main()
{
	int h[1000];
	h[0] = 100000;
	int hsize = 0;
	for (int i=0;i<13;i++)
	{
		int j;
		cin>>j;
		insert (h,&hsize,j);
	}
	print(h,&hsize);
	cout<<endl;
	del (h,h[1],&hsize);
    print(h,&hsize);
	return 0;
}
