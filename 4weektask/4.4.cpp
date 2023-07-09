#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
template <typename RandomIt>
pair<RandomIt, RandomIt>
FindStartsWith(RandomIt range_begin, RandomIt range_end, const string &prefix) {
  auto firstIt = lower_bound(range_begin, range_end, prefix);
  int dif = range_end - range_begin;
  if (count(range_begin, range_end, "z") == dif) {

    return make_pair(firstIt, range_end);
  }

  string prefix_n = "";
  int i = 1;

  for (auto it = prefix.crbegin(); it != prefix.crend(); ++it) {
    int n = (*it + i - 'a') / 33;
    prefix_n = char(((*it + i - 'a') % 33) + 'a') + prefix_n;
    i = n;
  }
  auto secondIt = lower_bound(range_begin, range_end, prefix_n);
  return make_pair(firstIt, secondIt);
}
int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " "
       << (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " "
       << (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}