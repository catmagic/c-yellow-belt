#include"phone_number.h"
#include<sstream>
PhoneNumber::PhoneNumber(const string &international_number)
{


    if(international_number[0]!='+'){throw invalid_argument("");}
    size_t pos=international_number.find('-');
    if(pos==string::npos){throw invalid_argument("");}
    country_code_=international_number.substr(1,pos-1);
    size_t pos2=international_number.find('-',pos+1);
    if(pos2==string::npos){throw invalid_argument("");}
    city_code_=international_number.substr(pos+1,pos2-1-pos);
    local_number_=international_number.substr(pos2+1);


    if(country_code_.size()==0||city_code_.size()==0||local_number_.size()==0)
    {
        throw invalid_argument("");
    }

}

string PhoneNumber::GetCountryCode()const{return country_code_;}
string PhoneNumber::GetCityCode()const{return city_code_;}
string PhoneNumber::GetLocalNumber()const{return local_number_;}
string PhoneNumber::GetInternationalNumber()const{return "+"+country_code_+"-"+city_code_+"-"+local_number_;}
