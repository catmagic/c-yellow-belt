#include <iostream>
#include <string>
#include <vector>


//--------------------------------------------------------------------------------------------------
class Person
{
public:
    Person(const std::string& name, const std::string& occupation)
        : Name(name), Occupation(occupation)
    {

    }

    std::string get_name() const
    {
        return Name;
    }

    std::string get_occupation() const
    {
        return Occupation;
    }
    auto& log()const
    {
         std::cout << Occupation<<": "<< get_name()<<" ";
         return std::cout;
    }
    virtual void Walk(const std::string& destination) const
    {
        log()<< "walks to: " << destination << std::endl;
    }
private:
    const std::string Name;
    const std::string Occupation;
};
//-----------------------------------------------------------------------------------------S---------
class Student : public Person
{
public:
    Student(const std::string& name, const std::string& favouriteSong)
        : Person(name, "Student"), FavouriteSong(favouriteSong)
    {

    }

    void Learn() const
    {
       log() << " learns" << std::endl;
    }

    void Walk(const std::string& destination) const override
    {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const
    {
        log() << "sings a song: " << FavouriteSong << std::endl;
    }
public:
    const std::string FavouriteSong;
};
//--------------------------------------------------------------------------------------------------
class Teacher : public Person
{
public:
    Teacher(std::string name, std::string subject)
        : Person(name, "Teacher"), Subject(subject)
    {

    }

    void Teach() const
    {
        log() << "teaches: " << Subject << std::endl;
    }


public:
    const std::string Subject;
};
//--------------------------------------------------------------------------------------------------
class Policeman : public Person
{
public:
    Policeman(const std::string& name)
        : Person(name, "Policeman")
    {

    }

    void Check(const Person& p) const
    {
        log() << "checks " << p.get_occupation() << ". "
            << p.get_occupation() << "'s name is: " << p.get_name() << std::endl;
    }


};
//--------------------------------------------------------------------------------------------------
void VisitPlaces(const Person& pers, const std::vector<std::string>& places)
{
    for (const auto& p : places)
    {
        pers.Walk(p);
    }
}
//--------------------------------------------------------------------------------------------------
int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}
//--------------------------------------------------------------------------------------------------
