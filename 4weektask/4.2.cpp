#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
class Person {
public:
  void ChangeFirstName(int year, const string &first_name) {
    // добавить факт изменения имени на first_name в год year
    firstName[year] = first_name;
  }
  void ChangeLastName(int year, const string &last_name) {
    // добавить факт изменения фамилии на last_name в год year
    lastName[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string firstNameS = "", lastNameS = "";

    auto it = firstName.upper_bound(year);
    // cout<<it->first<<" "<<year<<endl;
    // cout<<it->second<<endl;
    if (it != firstName.begin()) {
      it--;
      firstNameS = it->second;
      // cout<<it->first<<" "<<year<<endl;
      // cout<<it->second<<endl;
    }

    // cout << firstNameS << endl;
    //  cout<<"Nya:years "<<year<<"\n yeasr
    //  first"<<firstName.begin()->first<<"\nyers in
    //  map"<<firstName.lower_bound(year)->first<<endl;
    /*if (lastName.upper_bound(year) != lastName.end())

    {*/
    it = lastName.upper_bound(year);
    /*cout<<it->first<<" "<<year<<endl;
    cout<<it->second<<endl;*/
    if (it != lastName.begin()) {
      it--;
      lastNameS = it->second;
      /*cout<<it->first<<" "<<year<<endl;
      cout<<it->second<<endl;*/
    }
    //}
    stringstream ss;
    if (!firstNameS.empty()) {
      if (!lastNameS.empty()) {
        ss << firstNameS << " " << lastNameS;
      } else {
        ss << firstNameS << " with unknown last name";
      }
    } else {
      if (!lastNameS.empty()) {
        ss << lastNameS << " with unknown first name";
      } else {
        ss << "Incognito";
      }
    }
    return ss.str();
  }

private:
  map<int, string> firstName, lastName;
};
/*int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
     cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
     cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
     cout << person.GetFullName(year) << endl;
  }

  return 0;
}*/