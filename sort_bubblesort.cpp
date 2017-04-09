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
	int arr[5] = {5,2,7,6,3};
	for (int i = 0 ; i < 4 ; i++)
	{
		for ( int j = 0 ; j < 4-i ; j++)
		{
			if ( arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
	for ( int k = 0 ;  k < 5 ; k++)
	{
		cout<<arr[k]<<endl;
	}
	return 0;
}
