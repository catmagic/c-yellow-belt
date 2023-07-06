#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};
int GetDistinctRealRootCount(double a, double b, double c);
void TestWith2Root()
{
    AssertEqual(GetDistinctRealRootCount(1,0,-1),2);
    AssertEqual(GetDistinctRealRootCount(-1,0,1),2);
    AssertEqual(GetDistinctRealRootCount(1,2,-1),2);
    AssertEqual(GetDistinctRealRootCount(-1,-2,1),2);

     AssertEqual(GetDistinctRealRootCount(1,-1,0),2);
    AssertEqual(GetDistinctRealRootCount(-1,1,0),2);

    AssertEqual(GetDistinctRealRootCount(1,-3,2),2);
    AssertEqual(GetDistinctRealRootCount(1,3,2),2);
    AssertEqual(GetDistinctRealRootCount(1,-1,-2),2);
    AssertEqual(GetDistinctRealRootCount(1,1,-2),2);
     AssertEqual(GetDistinctRealRootCount(-1,3,-2),2);
    AssertEqual(GetDistinctRealRootCount(-1,-3,-2),2);
    AssertEqual(GetDistinctRealRootCount(-1,1,2),2);
    AssertEqual(GetDistinctRealRootCount(-1,-1,2),2);

    AssertEqual(GetDistinctRealRootCount(1,0,-1),2);
    AssertEqual(GetDistinctRealRootCount(-1,0,1),2);
    AssertEqual(GetDistinctRealRootCount(1,2,-1),2);
    AssertEqual(GetDistinctRealRootCount(-1,-2,1),2);
  //  AssertEqual(GetDistinctRealRootCount(5,10.0001,5),2);
}
void TestWith1Root()
{
   // AssertEqual(GetDistinctRealRootCount(5,10,5),1);
    AssertEqual(GetDistinctRealRootCount(1,2,1),1);
    AssertEqual(GetDistinctRealRootCount(-1,-2,-1),1);
    AssertEqual(GetDistinctRealRootCount(1,0,0),1);
    AssertEqual(GetDistinctRealRootCount(-1,0,0),1);

     AssertEqual(GetDistinctRealRootCount(0,1,1),1);
    AssertEqual(GetDistinctRealRootCount(0,1,-1),1);
    AssertEqual(GetDistinctRealRootCount(0,-1,1),1);
    AssertEqual(GetDistinctRealRootCount(0,-1,-1),1);
    AssertEqual(GetDistinctRealRootCount(0,1,0),1);
    AssertEqual(GetDistinctRealRootCount(0,-1,0),1);
}

void TestWith0Root()
{
   // AssertEqual(GetDistinctRealRootCount(5,9.99999,5),1);
    AssertEqual(GetDistinctRealRootCount(1,0,1),0);
    AssertEqual(GetDistinctRealRootCount(-1,0,-1),0);
    AssertEqual(GetDistinctRealRootCount(1,2,2),0);
    AssertEqual(GetDistinctRealRootCount(-1,-2,-2),0);

    AssertEqual(GetDistinctRealRootCount(0,0,1),0);
    AssertEqual(GetDistinctRealRootCount(0,0,-1),0);
}
/*int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
}*/

int main() {
  TestRunner tr;
  tr.RunTest(TestWith2Root,"2 root");
  tr.RunTest(TestWith1Root,"1 root");
  tr.RunTest(TestWith0Root,"0 root");
  // добавьте сюда свои тесты
  return 0;
}
