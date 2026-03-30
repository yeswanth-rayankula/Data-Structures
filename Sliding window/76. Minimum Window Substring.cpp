class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mt, ms;

        for(char c : t) mt[c]++;

        int required = mt.size();   
        int count = 0;        
        int j = 0, minLen = INT_MAX, start = 0;

        for(int i = 0; i < s.size(); i++) {
            ms[s[i]]++;

            if(ms[s[i]] == mt[s[i]]) {
                count++;
            }
            while(count == required && j<=i) {
                if(minLen > (i - j + 1)) {
                    minLen = i - j + 1;
                    start = j;
                }
                ms[s[j]]--;

                if(ms[s[j]] < mt[s[j]]) {
                    count--;
                }
                j++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};