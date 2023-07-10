#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main()
{
    deque<string> total;
	string tmp;
	cin>>tmp;
	total.push_back(tmp);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		char op;
		string number;
		cin>>op>>number;
		total.push_front("(");
		total.push_back(") "+op+" "+number);

	}
	for(auto string s:total)
	{
        cout<<s;
	}
	cout<<endl;
	return 0;
}
