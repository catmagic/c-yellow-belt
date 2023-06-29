
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;
template <typename Num>
Num Sqr(const Num n);
template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p);
template <typename T>
vector<T>  Sqr(const vector<T>& vi);
template <typename Key, typename Value>
const map<Key, Value>  Sqr(const map<Key, Value>& m);
template <typename Num>
Num Sqr(const Num n)
{
    return n*n;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p)
{
    return make_pair(Sqr(p.first),Sqr(p.second));
}

template <typename T>
vector<T>  Sqr(const vector<T>& vi)
{
    vector<T> result;
    for(const auto element:vi)
    {
        result.push_back(Sqr(element));
    }
    return result;
}

template <typename Key, typename Value>
const map<Key, Value>  Sqr(const map<Key, Value>& m)
{
    map<Key, Value> result;
    for(const auto pairmap:m)
    {
        result[pairmap.first]=Sqr(pairmap.second);
    }
    return result;
}
/*int main()
{
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v))
    {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs))
    {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}*/
