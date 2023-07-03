#include<vector>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
vector<string> SplitIntoWords(const string& s)
{
	stringstream ss(s);
	vector<string> result;
	string tmp;
	while(ss>>tmp)
	{
		result.push_back(tmp);
	}
	return result;
}
/*int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}*/