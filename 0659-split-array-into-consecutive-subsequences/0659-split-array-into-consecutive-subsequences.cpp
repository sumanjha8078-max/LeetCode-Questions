class Solution {
public:
    bool is_true(vector<int>& use){
        int n = use.size();
        for(int i = 0 ; i < n ; i++){
            if(use[i] == 0) continue;
            int l = i, r = i + 1, val = use[i];
            cout << val << "\n";
            while(r < n && use[r] >= use[r-1]) r++;
            cout << l << " " << r << "\n";
            if(r - l < 3){
                return false;
            } 
            for(int j = l ; j < r ; j++) use[j]--;
            i--;
        }
        return true;
    }
    bool isPossible(vector<int>& nums) {
        map<int,int> mp;
        for(const int& t : nums) mp[t]++;
        vector<int> v;
        for(const auto& p : mp) v.push_back(p.first);
        int l = 0, r = 1;
        int n = v.size();
        set<pair<int,int>> st;
        while(r < n){
            while(r < n && v[r] == v[r-1] + 1) r++;
            if(r - l < 3) return false;
            st.insert({l, r});
            l = r;
            r++;
        }
        if(l != n){
            return false;
        }
        for(const auto& p : st){
            vector<int> use;
            for(int i = p.first ; i < p.second ; i++) use.push_back(mp[v[i]]);
            if(!is_true(use)) return false;
        }
        return true;
    }
};