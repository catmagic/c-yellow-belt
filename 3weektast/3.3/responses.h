#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
struct BusesForStopResponse 
{
  std::vector<std::string> buses;
};

std::ostream &operator<<(std::ostream &os, const BusesForStopResponse &r) ;

struct StopsForBusResponse 
{
    std::string bus;
    std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;
};

std::ostream &operator<<(std::ostream &os, const StopsForBusResponse &r); 

struct AllBusesResponse 
{
    std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream &operator<<(std::ostream &os, const AllBusesResponse &r) ;
