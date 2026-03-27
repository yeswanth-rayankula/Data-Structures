class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        return a.first < b.first;
    }

    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>> mp;

        // calculate start and end point of each character 
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = {i, i};
            } else {
                mp[s[i]].second = i;
            }
        }

        vector<pair<int,int>> vec;
        for (auto &it : mp) {
            vec.push_back(it.second);
        }

        sort(vec.begin(), vec.end(), cmp);

        vector<int> ans;

        int start = vec[0].first;
        int end = vec[0].second;

        for (int i = 1; i < vec.size(); i++) 
        {
            if (vec[i].first <= end) 
            {
               end = max(end, vec[i].second);
            } 
            else 
            {
                ans.push_back(end - start + 1);
                start = vec[i].first;
                end = vec[i].second;
            }
        }

        ans.push_back(end - start + 1);

        return ans;
    }
};