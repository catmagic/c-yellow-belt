#include<iostream>
#include<string>
using namespace std;
int main()
{
	string result;
	cin>>result;
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		char op;
		string number;
		cin>>op>>number;
		result="("+result+") "+op+" "+number;
		
	}
	cout<<result;
	return 0;
}