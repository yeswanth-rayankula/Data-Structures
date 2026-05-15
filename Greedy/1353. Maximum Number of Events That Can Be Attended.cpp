class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }

    int maxEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end(), cmp);

        int maxDay = 0;

        for(auto &e : events)
        {
            maxDay = max(maxDay, e[1]);
        }

        set<int> days;

        for(int i = 1; i <= maxDay; i++)
        {
            days.insert(i);
        }

        int ans = 0;

        for(auto &e : events)
        {
            int start = e[0];
            int end = e[1];

            auto it = days.lower_bound(start);

            if(it != days.end() && *it <= end)
            {
                ans++;
                days.erase(it);
            }
        }

        return ans;
    }
};