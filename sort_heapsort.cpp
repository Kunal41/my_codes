#include<iostream>
using namespace std;
void restoredown ( int arr[],int start, int size)
{
	int lchildindex = start*2 + 1;
	int rchildindex = 2*start + 2;
	while ( rchildindex <= size )
	{
		if ( arr[lchildindex] < arr[start] && arr[rchildindex] < arr[start] )
		{
			return;
		}
		else if ( arr[lchildindex] > arr[start] && arr[lchildindex] > arr[rchildindex])
		{
			int temp = arr[lchildindex];
			arr[lchildindex] = arr[start];
			arr[start] = temp; 
			start = lchildindex;
			lchildindex = 2*start+1;
			rchildindex = 2*start+2;
		}
		else if ( arr[rchildindex] > arr[start] && arr[rchildindex] > arr[lchildindex])
		{
			int temp = arr[rchildindex];
			arr[rchildindex] = arr[start];
			arr[start] = temp;
			start = rchildindex;
			lchildindex = 2*start+1;
			rchildindex = 2*start+2;
	}
	}
	if ( lchildindex == size && arr[lchildindex] > arr[start])
	{
		int temp = arr[start];
		arr[start] = arr[lchildindex];
		arr[lchildindex] = temp;
	}	
	return;
}
void print (int arr[],int size)
{
	for (int i = 0; i < size ; i++)
	{
		cout<<arr[i]<<"	";
	}
}
void heapsort ( int arr[] , int size)
{
		int i;
		for ( i = (size-1)/2; i >= 0 ; i--)
		{
			restoredown(arr,i,size);	
		}	
		for (int j = size; j > 0 ; j--)
		{
			int temp = arr[j];
			arr[j] = arr[0];
			arr[0] = temp; 
			restoredown(arr,0,j-1);
		}
}
int main()
{
	int arr[] = {12,11,13,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	print(arr,n);
	cout<<endl;
	heapsort(arr,n-1);
	print(arr,n);
	return 0;	
}

