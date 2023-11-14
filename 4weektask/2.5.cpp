#include<iostream>
#include<algorithm>
#include<vector>

template <typename RandomIt>
void MergeSort(RandomIt range_begin,RandomIt range_end)
{
    if(range_end-range_begin<2)
    {
        return;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    MergeSort(elements.begin(),elements.begin()+(range_end-range_begin)/3);
    MergeSort(elements.begin()+(range_end-range_begin)/3,elements.begin()+2*(range_end-range_begin)/3);
    MergeSort(elements.begin()+2*(range_end-range_begin)/3,elements.end());
    std::vector<typename RandomIt::value_type> tmp_vect;
    std::merge(elements.begin(),elements.begin()+(range_end-range_begin)/3,elements.begin()+(range_end-range_begin)/3,elements.begin()+2*(range_end-range_begin)/3,std::back_inserter(tmp_vect));
    std::merge(tmp_vect.begin(),tmp_vect.end(),elements.begin()+2*(range_end-range_begin)/3,elements.end(),range_begin);
}
int main() {
  std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(std::begin(v), std::end(v));
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return 0;
}
