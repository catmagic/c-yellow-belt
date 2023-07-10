#include<iostream>
#include<string>
#include<deque>
 enum priority_operation
{PLUS_MINES=0,MULTI_DIVED=1,UNDEF=2,
};
using namespace std;
int main()
{
    deque<string> total;
	string tmp;
	cin>>tmp;
	total.push_back(tmp);
	int n;
	cin>>n;
	priority_operation current=priority_operation::UNDEF;
	priority_operation next=priority_operation::UNDEF;
	for(int i=0;i<n;++i)
	{
		char op;
		string number;
		cin>>op>>number;
		next=(op=='+'||op=='-')?(priority_operation::PLUS_MINES):(priority_operation::MULTI_DIVED);
		if(current<next)
		{
            total.push_front(string("("));
            total.push_back(string(") "));
		}
		else
		{
            total.push_back(string(" "));
		}
		total.push_back(string(1,op)+" "+number);

        current=next;
	}
	for(const string& s:total)
	{
        cout<<s;
	}
	cout<<endl;
	return 0;
}
