/*
	INSERTION SORT
	1. INPLACE SORT
	2. UNSTABLE SORT
	3. DATA INDEPENDENT - as uses n^2 comparison to sort the data.
*/
#include<iostream>
using namespace std;
void swap ( int *i,int *j){
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
int main()
{
	int arr[5] = {4,7,3,8,2};
	for ( int i = 0; i < 4 ; i++)
	{
		for ( int j = i+1 ; j < 5 ; j++)
		{
			if ( arr[i] > arr[j])
			{
				swap( &arr[i],&arr[j]);
			}
		}
	}
	for ( int k = 0 ; k < 5 ; k++)
	{
		cout<<arr[k]<<endl;
	}
	return 0;
}
