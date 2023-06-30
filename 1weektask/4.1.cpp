#include<iostream>
#include<map>
#include<tuple>
#include<vector>
#include <algorithm>
#include <cstdint>

using namespace std;
/*enum class Lang {
  DE, FR, IT
};
struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};
*/
bool operator<(const Region&lhs, const Region&rhs)
{
    return make_tuple(lhs.std_name,lhs.parent_std_name,lhs.names,lhs.population)<
    make_tuple(rhs.std_name,rhs.parent_std_name,rhs.names,rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
    map<Region,int>result;
    if(regions.size()==0)
    {
        return 0;
    }
    using pair_type = decltype(result)::value_type;
    for(const auto region:regions)
    {
        ++result[region];
    }
    auto pr = std::max_element
(
    std::begin(result), std::end(result),
    [] (const pair_type & p1, const pair_type & p2) {
        return p1.second < p2.second;
    }
);
return pr->second;
}
/*
int main() {
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;

  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;

  return 0;
}
*/
