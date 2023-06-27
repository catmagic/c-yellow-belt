#include<iostream>
using namespace std;
int main()
{
    uint64_t result=0;
    uint64_t w,h,d;
    int N;
    int ro;
    cin>>N>>ro;
    for(int i=0;i<N;++i)
    {
        cin>>w>>h>>d;
        result+=ro*w*h*d;
    }
    cout<<result;
    return 0;
}
