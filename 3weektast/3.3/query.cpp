#include"query.h"
using namespace std;
istream &operator>>(istream &is, Query &q) {
  string command;

  is >> command;
  if (command == "NEW_BUS") {
    int stop_count;
    q.type = QueryType::NewBus;
    is >> q.bus>>stop_count;
    q.stops.clear();
    for (int i = 0; i < stop_count; ++i) {
      string stop;
      is >> stop;
      q.stops.push_back(stop);
    }
  }
  if (command == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }
  if (command == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
	  is>>q.bus;
  }
  if (command == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }
  return is;
}
