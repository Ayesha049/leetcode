class UndergroundSystem {
public:
    map<int,pair<string,int>>checkin;
    map<string,map<string,pair<double,int> > >mp;
    UndergroundSystem() {
        checkin.clear();
        mp.clear();
    }
    
    void checkIn(int id, string s, int t) {
        checkin[id] = make_pair(s,t);
    }
    
    void checkOut(int id, string s, int t) {
        string ps = checkin[id].first;
        int pt = checkin[id].second;
        int diff = t-pt;
        double total = mp.find(ps) != mp.end() ? mp[ps].find(s) != mp[ps].end() ? mp[ps][s].first :0 : 0;
        // cout<<ps<<" "<<s<<" "<<total+diff<<endl;
        int c = 0;
        if(total != 0) {
            c = mp[ps][s].second;
        }
        mp[ps][s] = make_pair(total+diff,c+1);
        
    }
    
    double getAverageTime(string ps, string s) {
        double total = mp.find(ps) != mp.end() ? mp[ps].find(s) != mp[ps].end() ? mp[ps][s].first :0 : 0; 
        double c = 0;
        if(total != 0) {
            c = mp[ps][s].second;
        }
        // cout<<ps<<" "<<s<<" "<<total<<" "<<c<<endl;
        return c != 0 ? total/c : 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */