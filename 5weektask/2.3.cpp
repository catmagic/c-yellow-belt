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

    Student(string name, string favouriteSong):Man(Name,"Student") {
        Name = name;
        FavouriteSong = favouriteSong;
    }

    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(string destination) {
      	dynamic_cast<Man>this.Walk();
	SingSong();
    
    }

    void SingSong() {
        cout << role_name()<< " sings a song: " << FavouriteSong << endl;
    }

public:
    string Name;
    string FavouriteSong;
};


class Teacher {
public:

    Teacher(string name, string subject) {
        Name = name;
        Subject = subject;
    }

    void Teach() {
        cout << role_name()<< " teaches: " << Subject << endl;
    }


public:
    string Subject;
};


class Policeman:Man {
public:
    Policeman(string name):Man(name,"Policeman"){}

    void Check(Man* m) {
        cout << role_name()<< " checks "<<m.Role<<". "<<m.Role<<"'s name is: " << m.Name << endl;
    }
};


void VisitPlaces(Teacher t, vector<string> places) {
    for (auto p : places) {
        t.Walk(p);
    }
}

void VisitPlaces(Student s, vector<string> places) {
    for (auto p : places) {
        s.Walk(p);
    }
}

void VisitPlaces(Policeman pol, vector<string> places) {
    for (auto p : places) {
        pol.Walk(p);
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