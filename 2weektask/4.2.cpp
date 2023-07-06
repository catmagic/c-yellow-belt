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

/*class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name);
  void ChangeLastName(int year, const string& last_name);
  string GetFullName(int year);
};*/
void testEmpty()
{
  Person Incognito;
  AssertEqual(Incognito.GetFullName(1),"Incognito");
  AssertEqual(Incognito.GetFullName(1),"Incognito");
  AssertEqual(Incognito.GetFullName(2),"Incognito");
  AssertEqual(Incognito.GetFullName(3),"Incognito");
  AssertEqual(Incognito.GetFullName(2),"Incognito");
  AssertEqual(Incognito.GetFullName(1),"Incognito");
  AssertEqual(Incognito.GetFullName(0),"Incognito");
  AssertEqual(Incognito.GetFullName(-1),"Incognito");
}

void uknownfirst()
{
  Person last;
  last.ChangeLastName(20,"11");
  AssertEqual(last.GetFullName(20),"11 with unknown first name");
  AssertEqual(last.GetFullName(20),"11 with unknown first name");
  AssertEqual(last.GetFullName(21),"11 with unknown first name");
  AssertEqual(last.GetFullName(22),"11 with unknown first name");
  AssertEqual(last.GetFullName(23),"11 with unknown first name");
  AssertEqual(last.GetFullName(19),"Incognito");
  AssertEqual(last.GetFullName(2),"Incognito");
  AssertEqual(last.GetFullName(3),"Incognito");
  AssertEqual(last.GetFullName(2),"Incognito");
  AssertEqual(last.GetFullName(1),"Incognito");
  AssertEqual(last.GetFullName(0),"Incognito");
  AssertEqual(last.GetFullName(-1),"Incognito");
}

void uknownlast()
{
  Person first;
  first.ChangeFirstName(20,"11");
  AssertEqual(first.GetFullName(20),"11 with unknown last name");
  AssertEqual(first.GetFullName(20),"11 with unknown last name");
  AssertEqual(first.GetFullName(21),"11 with unknown last name");
  AssertEqual(first.GetFullName(22),"11 with unknown last name");
  AssertEqual(first.GetFullName(23),"11 with unknown last name");
  AssertEqual(first.GetFullName(19),"Incognito");
  AssertEqual(first.GetFullName(2),"Incognito");
  AssertEqual(first.GetFullName(3),"Incognito");
  AssertEqual(first.GetFullName(2),"Incognito");
  AssertEqual(first.GetFullName(1),"Incognito");
  AssertEqual(first.GetFullName(0),"Incognito");
  AssertEqual(first.GetFullName(-1),"Incognito");
}
void common()
{
    Person person;
    person.ChangeFirstName(20,"11");
    person.ChangeLastName(20,"22");
    AssertEqual(person.GetFullName(20),"11 22");
    AssertEqual(person.GetFullName(20),"11 22");
    AssertEqual(person.GetFullName(21),"11 22");
    AssertEqual(person.GetFullName(22),"11 22");
    AssertEqual(person.GetFullName(23),"11 22");
    AssertEqual(person.GetFullName(19),"Incognito");
    AssertEqual(person.GetFullName(2),"Incognito");
    AssertEqual(person.GetFullName(3),"Incognito");
    AssertEqual(person.GetFullName(2),"Incognito");
    AssertEqual(person.GetFullName(1),"Incognito");
    AssertEqual(person.GetFullName(0),"Incognito");
    AssertEqual(person.GetFullName(-1),"Incognito");

    person.ChangeFirstName(19,"111");
    person.ChangeLastName(18,"222");


    AssertEqual(person.GetFullName(19),"111 222");
    AssertEqual(person.GetFullName(18),"222 with unknown first name");


    AssertEqual(person.GetFullName(20),"11 22");
    AssertEqual(person.GetFullName(20),"11 22");
    AssertEqual(person.GetFullName(21),"11 22");
    AssertEqual(person.GetFullName(22),"11 22");
    AssertEqual(person.GetFullName(23),"11 22");
    AssertEqual(person.GetFullName(17),"Incognito");
    AssertEqual(person.GetFullName(2),"Incognito");
    AssertEqual(person.GetFullName(3),"Incognito");
    AssertEqual(person.GetFullName(2),"Incognito");
    AssertEqual(person.GetFullName(1),"Incognito");
    AssertEqual(person.GetFullName(0),"Incognito");
    AssertEqual(person.GetFullName(-1),"Incognito");
}
int main() {
  TestRunner runner;
  runner.RunTest(testEmpty,"empty");
  runner.RunTest(uknownfirst,"uknownfirst");
  runner.RunTest(uknownlast,"uknownlast");
  runner.RunTest(common,"common");
  // добавьте сюда свои тесты
  return 0;
}
