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


/*class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  }

  int Denominator() const ;
};
*/
void test_empty_consructor()
{
    Rational zero;
     Rational alt_zero(0,3);
      Rational alt2_zero(0,-3);
    AssertEqual(zero.Numerator(),0);
    AssertEqual(zero.Denominator(),1);
      AssertEqual(alt_zero.Numerator(),0);
    AssertEqual(alt_zero.Denominator(),1);
      AssertEqual(alt2_zero.Numerator(),0);
    AssertEqual(alt2_zero.Denominator(),1);
}
void simple_rational()
{
    Rational half(1,2);
    AssertEqual(half.Numerator(),1);
    AssertEqual(half.Denominator(),2);
    Rational minus_half(-1,2);
    AssertEqual(minus_half.Numerator(),-1);
    AssertEqual(minus_half.Denominator(),2);
    Rational alt_half(-1,-2);
    AssertEqual(alt_half.Numerator(),1);
    AssertEqual(alt_half.Denominator(),2);
    Rational alt_minus_half(1,-2);
    AssertEqual(alt_minus_half.Numerator(),-1);
    AssertEqual(alt_minus_half.Denominator(),2);
}
void not_simple_rational()
{
    Rational r3_5(12,20);
    AssertEqual(r3_5.Numerator(),3);
    AssertEqual(r3_5.Denominator(),5);
    Rational minus_r3_5(-12,20);
    AssertEqual(minus_r3_5.Numerator(),-3);
    AssertEqual(minus_r3_5.Denominator(),5);
    Rational alt_r3_5(-12,-20);
    AssertEqual(alt_r3_5.Numerator(),3);
    AssertEqual(alt_r3_5.Denominator(),5);
    Rational alt_minus_r3_5(12,20);
    AssertEqual(alt_minus_r3_5.Numerator(),3);
    AssertEqual(alt_minus_r3_5.Denominator(),5);
}
int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(test_empty_consructor,"error empty");
  runner.RunTest(simple_rational,"error simply");
  runner.RunTest(not_simple_rational,"error not simply");
  return 0;
}
