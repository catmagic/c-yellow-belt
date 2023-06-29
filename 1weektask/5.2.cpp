
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;
template <typename Key, typename Value>
Value&  GetRefStrict(map<Key, Value>& m,const Key key )
{   if(m.find(key)==m.end())
    {
        throw runtime_error("");
    }

    return m[key];
}
/*int main()
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}
*/
