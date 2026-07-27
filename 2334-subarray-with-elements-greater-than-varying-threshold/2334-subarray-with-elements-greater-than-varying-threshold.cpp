class DSU{
    public:
    vector<int> parent, rank;
    DSU(int n){
        for(int i = 0 ; i < n ; i++) parent.push_back(i);
        for(int i = 0 ; i < n ; i++) rank.push_back(1);
    }

    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool is_same(int x, int y){
        if(find(x) == find(y)) return true;
        return false;
    }

    void join(int x, int y){
        if(is_same(x, y)) return;
        int x1 = find(x), y1 = find(y);
        if(rank[x1] >= rank[y1]){
            parent[y1] = x1;
            rank[x1] += rank[y1];
        }
        else{
            parent[x1] = y1;
            rank[y1] += rank[x1];
        }
    }

};

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        DSU d(n);
        vector<pair<int,int>> v;
        map<int,int> mp;
        for(int i = 0 ; i < n ; i++) v.emplace_back(nums[i], i);
        sort(v.begin(), v.end());
        vector<int> active(n);
        int r = n-1;
        for(int i = 1 ; i <= n ; i++){
            int val = threshold/i;
            while(r >= 0 && v[r].first > val){
                int idx = v[r].second;
                active[idx] = 1;
                if(idx > 0 && active[idx-1]) d.join(idx, idx-1);
                if(idx < n-1 && active[idx+1]) d.join(idx, idx + 1);
                if(d.rank[d.find(idx)] >= i) return i;
                r--;
            }
        }
        return -1;
    }
};