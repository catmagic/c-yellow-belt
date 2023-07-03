#include<iostream>
#include<vector>
using namespace std;
void PrintVectorPart(const vector<int>& numbers)
{
	
	auto itend=numbers.begin();
	while(itend!=numbers.end()&&*itend>=0)
	{
		++itend;
	}
	for(auto it=itend;it!=numbers.begin();)
	{
		--it;
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main() {
  PrintVectorPart({6, 1, 8, 5, -0});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}