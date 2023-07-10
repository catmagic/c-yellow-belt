#include"responses.h"
using namespace std;
ostream &operator<<(ostream &os, const BusesForStopResponse &r) {

  if (r.buses.size() == 0) {
    return os << "No stop";
  }
  for (const string &bus : r.buses) {
    os << bus << " ";
  }
  return os;
}



ostream &operator<<(ostream &os, const StopsForBusResponse &r) {
  // Реализуйте эту функцию
	auto itstop=r.buses_to_stops.find(r.bus);
	if(r.buses_to_stops.cend()==itstop)
	{
		return os<<"No bus";
	}

    for(const auto stop:itstop->second)
	{
		auto itbus=r.stops_to_buses.find(stop);
		os<<"Stop "<<stop<<":";
		if(itbus->second.size()==1)
		{
			os<<" no interchange";
		}
		else
		{
			for(const auto bus:itbus->second)
			{
				if(bus!=r.bus)
				{
					os<<" "<<bus;
				}
			}
		}
		os<<endl;
	}

  return os;
}



ostream &operator<<(ostream &os, const AllBusesResponse &r) {
  // Реализуйте эту функцию
  if (r.buses_to_stops.size() == 0) {
    return os << "No buses";
  }
  for (const auto bus_and_stops : r.buses_to_stops) {
    os << "Bus " << bus_and_stops.first << ":";
    for (const auto stop : bus_and_stops.second) {
      os << " " << stop;
    }
    os << endl;
  }
  return os;
}
