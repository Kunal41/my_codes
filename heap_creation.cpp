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
int main()
{
	int h[1000];
	h[0] = 100000;
	int hsize = 0;
	for (int i=0;i<7;i++)
	{
		int j;
		cin>>j;
		insert (h,&hsize,j);
 	}
	print(h,&hsize);
	cout<<endl;
	
	return 0;
}
