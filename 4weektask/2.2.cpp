#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    while(n)
    {
        v.push_back(n);
        --n;
    }
    for(auto el:v)
    {
        cout<<el<<" ";
    }
    cout<<endl;
    while(prev_permutation(v.begin(),v.end()))
    {
        for(auto el:v)
        {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
