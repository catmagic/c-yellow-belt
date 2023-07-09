#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix)
{
	vector<char> tmp;
	auto it=range_begin;
	for(;it!=range_end;++it)
	{
		tmp.push_back((*it)[0]);
	}
	int start=lower_bound(tmp.begin(),tmp.end(),prefix)-tmp.begin();
	int end=upper_bound(tmp.begin(),tmp.end(),prefix)-tmp.begin();
	return make_pair(range_begin+start, range_begin+end);
}
int main() {
  const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
  
  const auto m_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
  for (auto it = m_result.first; it != m_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto p_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
  cout << (p_result.first - begin(sorted_strings)) << " " <<
      (p_result.second - begin(sorted_strings)) << endl;
  
  const auto z_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
  cout << (z_result.first - begin(sorted_strings)) << " " <<
      (z_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}