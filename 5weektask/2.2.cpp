#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<cmath>
#include<sstream>
#include<iomanip>
const double pi=3.14;
using namespace std;
class Figure
{
public:
    virtual string Name() const =0;
    virtual double Perimeter() const =0;
    virtual double Area() const =0;
};
class Triangle:public Figure
{
public:
    Triangle(int a,int b,int c)
    {
        perimeter=a+b+c;
        double s=perimeter/2;//semi perineter
        area=sqrt(s*(s-a)*(s-b)*(s-c));
    }
    virtual string Name()const override{return "TRIANGLE";}
    virtual double Perimeter() const override{return perimeter;}
    virtual double Area()const override{return area;}
private:
    double perimeter;
    double area;

};
class Rect:public Figure
{
public:
    Rect(int a,int b)
    {
        perimeter=2*a+2*b;
        area=a*b;
    }
    virtual string Name()const override{return "RECT";}
    virtual double Perimeter() const override{return perimeter;}
    virtual double Area()const override{return area;}
private:
    double perimeter;
    double area;

};
class Circle:public Figure
{
public:
    Circle(int r)
    {
        perimeter=2*pi*r;
        area=pi*r*r;
    }
    virtual string Name()const override{return "CIRCLE";}
    virtual double Perimeter() const override{return perimeter;}
    virtual double Area()const override{return area;}
private:
    double perimeter;
    double area;

};

shared_ptr<Figure> CreateFigure(istringstream &is)
{
    string type;
    is>>type;
    if(type=="RECT")
    {
        int a,b;
        is>>a>>b;
        return  make_shared<Rect>(a,b);
    }
    if(type=="TRIANGLE")
    {
        int a,b,c;
        is>>a>>b>>c;
        return  make_shared<Triangle>(a,b,c);
    }
    int r;
    is>>r;
    return make_shared<Circle>(r);
}
int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
