#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"responses.h"
class BusManager 
{
public:
  void AddBus(const std::string &bus, const std::vector<std::string> &stops) ;

  BusesForStopResponse GetBusesForStop(const std::string &stop) const ;
  StopsForBusResponse GetStopsForBus(const std::string &bus) const ;

  AllBusesResponse GetAllBuses() const ;
  std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;
};
