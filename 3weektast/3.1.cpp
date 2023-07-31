#include"phone_number.h"
#include<sstream>
PhoneNumber::PhoneNumber(const string &international_number)
{
    stringstream ss(international_number);
    char c;
    ss>>c;
    if(c!='+'){throw invalid_argument("");}
    ss>>c;
    while(c!='-')
    {country_code_+=c;}
    ss>>c;
    while(c!='-')
    {city_code_+=c;}
    while(ss>>c)
    {
    local_number_+=c;
    }
    if(country_code_.size()==0||city_code_.size()==0||local_number_.size()==0)
    {
        throw invalid_argument("");
    }

}

string PhoneNumber::GetCountryCode()const{return country_code_;}
string PhoneNumber::GetCityCode()const{return city_code_;}
string PhoneNumber::GetLocalNumber()const{return local_number_;}
string PhoneNumber::GetInternationalNumber()const{return "+"+country_code_+"-"+city_code_+"-"+local_number_;}
