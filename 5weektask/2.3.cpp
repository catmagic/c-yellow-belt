#include <iostream>
#include <string>
#include <vector>

using namespace std;

Class Man
{
public:
	Man(string name,string role):Name(name),Role(role){}
	string role_name()
	{
		return Role+": "+Name;
	}
	void Wakl(string destination)
	{
		cout<<role_name()<< " walks to: " << destination << endl;
	}
public:
	const string Name;
	const string Role;
}
class Student :man{
public:

	Student(string name, string favouriteSong):Man(Name,"Student"),FavouriteSong(favouriteSong){}

    void Learn() {
        cout << role_name() << " learns" << endl;
    }
	void SingSong() {
        cout << role_name()<< " sings a song: " << FavouriteSong << endl;
    }
    void Walk(string destination) {
      	dynamic_cast<Man>this.Walk();
	SingSong();
    
    }
public:
    const string FavouriteSong;
};


class Teacher {
public:

    Teacher(string name, string subject):Man(name,"Teacher"),Subject(subject) {}

    void Teach() {
        cout << role_name()<< " teaches: " << Subject << endl;
    }


public:
    const string Subject;
};


class Policeman:Man {
public:
    Policeman(string name):Man(name,"Policeman"){}

    void Check(Man* m) {
        cout << role_name()<< " checks "<<m.Role<<". "<<m.Role<<"'s name is: " << m.Name << endl;
    }
};


void VisitPlaces(Man* t, vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}




int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}