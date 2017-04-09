#include<iostream>
using namespace std;
void print (int arr[],int size)
{
	for ( int i = 0 ; i < size ; i++)
	{
		cout<<arr[i]<<endl;
	}
}
void insertionsort ( int arr[], int size)
{
	for ( int i = 1 ; i < size ; i++)
	{
		int temp = arr[i];
		int j = i-1;
		while ( j>=0 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = temp;
    }
}
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    insertionsort(arr, n);
    print(arr,n);
	return 0;
}
