#include <algorithm>
#include <iostream>
#include <vector>
template <typename T>
void RemoveDuplicates(vector<T>& elements)
{
    std::sort(elements.begin(), elements.end());
 	auto last = std::unique(elements.begin(), elements.end());
 	elements.erase(last, elements.end());
}