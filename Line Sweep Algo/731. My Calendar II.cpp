class MyCalendarTwo {
public:
    // vector<pair<int,int>> vec;
    map<int,int> mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        int count = 0;
        mp[startTime]++;
        mp[endTime]--;
        for(auto i: mp)
        {
            count+=i.second;
            if(count>=3)
            {
                mp[startTime]--;
                mp[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */