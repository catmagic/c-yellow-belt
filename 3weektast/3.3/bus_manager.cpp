#include"bus_manager.h"
#include<map>
using namespace std;
void BusManager::AddBus(const string &bus, const vector<string> &stops)
{
    for (const auto stop : stops)
    {
        buses_to_stops[bus].push_back(stop);
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string &stop) const
{
    vector<string> result;
    auto it = stops_to_buses.find(stop);
    if (it != stops_to_buses.end())
    {
        for(const string bus : stops_to_buses.at(stop))
        {
            result.push_back(bus);
        }
    }
    return {result};
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string &bus) const
{

    return StopsForBusResponse{bus,buses_to_stops,stops_to_buses};
}

AllBusesResponse BusManager::GetAllBuses() const
{
    return {buses_to_stops};
}
