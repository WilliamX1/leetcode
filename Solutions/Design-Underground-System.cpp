#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem {
private:
    map<int, vector<int>> get_in_time;
    map<string, int> stationNameToInt;
    int stationInt;
    map<vector<int>, vector<int>> time; 
public:
    UndergroundSystem() {
        stationInt = 0;
    };

    void checkIn(int id, string stationName, int t) {
        auto iter = stationNameToInt.find(stationName);
        if (iter == stationNameToInt.end()) stationNameToInt.insert(make_pair(stationName, stationInt++));
        iter = stationNameToInt.find(stationName);

        vector<int> s = {t, iter->second};
        get_in_time.insert(make_pair(id, s));
    }
    
    void checkOut(int id, string stationName, int t) {
        auto iter = get_in_time.find(id);

        int start_station = iter->second[0];
        int start_time = iter->second[1];

        get_in_time.erase(iter);

        auto iter_find_station = stationNameToInt.find(stationName);
        if (iter_find_station == stationNameToInt.end()) stationNameToInt.insert(make_pair(stationName, stationInt++));
        iter_find_station = stationNameToInt.find(stationName);

        int end_station = iter_find_station->second;
        int end_time = t;

        vector<int> f = {start_station, end_station};
        auto iter_find_time = time.find(f);
        if (iter_find_time == time.end()) {
            vector s = {1, end_time - start_time};
            time.insert(make_pair(f, s));
        } else {
            iter_find_time->second[0]++;
            iter_find_time->second[1] += end_time - start_time;
        };
    }
    
    double getAverageTime(string startStation, string endStation) {
        int start_station = stationNameToInt.find(startStation)->second;
        int end_station = stationNameToInt.find(endStation)->second;
        vector<int> v = {start_station, end_station};
        auto iter = time.find(v);
        return iter == time.end() ? 0.0 : double(iter->second[1]) / double(iter->second[0]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */