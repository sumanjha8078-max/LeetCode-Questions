class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        map<char,int> mp;
        for(const char& ch : word) mp[ch]++;
        vector<int> v;
        for(const auto& p : mp) v.push_back(p.second);
        sort(v.rbegin(), v.rend());
        int ans = 0;
        for(int i = 0 ; i < v.size() ; i++){
            ans += i/8 + 1;
        }
        return ans;
    }
};