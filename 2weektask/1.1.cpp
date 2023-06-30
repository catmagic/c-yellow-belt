#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string command;
  is>>command;
  if(command=="NEW_BUS")
  {
    int stop_count;
    q.type=QueryType::NewBus;
    is>>q.bus;
    q.stops.clear();
    for(int i=0;i<stop_count;++i)
    {
        string stop;
        is>>stop;
        q.stops.push_back(stop);
    }

  }
  if(command=="BUSES_FOR_STOP")
  {

  }
  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
  vector<string> stops;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {

  if(r.stops.size()==0)
  {
    return os<<"No stop"<<endl;
  }
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops)
  {
        for(const auto stop:stops)
        {
            buses_to_stops[bus].push_back(stop);
            stops_to_buses[stop].push_back(bus);
        }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const
  {
    vector<string> result;
    auto it =stops_to_buses.find(stop);
    if(it!=stops_to_buses.end())
    {
        for(const string bus:stops_to_buses.at(stop))
        {
            result.push_back(bus);
        }

    }
    return {result};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const
  {
    vector<string> result;
    auto it =buses_to_stops.find(bus);
    if(it!=buses_to_stops.end())
    {
        for(const string stop:buses_to_stops.at(bus))
        {
            result.push_back(stop);
        }

    }
    return {result};
    // Реализуйте этот метод
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
  }
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
   //   cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
    //  cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
