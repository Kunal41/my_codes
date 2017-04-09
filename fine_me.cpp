#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num ; int numarr[100]; int q ;
	cin>>num;
	for ( int i = 0 ; i < num ; i++ )
	{	
		cin>>numarr[i];
	}
	int queries;
	cin>>queries;
	while  ( queries > 0 )
	{
		int k ;
		cin>>k;
		sort (numarr,numarr+num);
		cout<<numarr[k-1]<<endl;
		num--;
	}
	return 0;
}
