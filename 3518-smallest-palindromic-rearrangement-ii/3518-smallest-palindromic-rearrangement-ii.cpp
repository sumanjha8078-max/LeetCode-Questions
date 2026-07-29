#define mod (1000000007)
class Solution {
public:
    long long comb(vector<long long>& hash, int k){
        long long ans = 1, count = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(hash[i] == 0) continue;
            long long val = hash[i], c = 0;
            while(val--){
                c++;
                count++;
                ans *= count;
                ans /= c;
                if(ans >= k) return ans;
            }
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<long long> hash(26, 0);
        for(int i = 0 ; i < n/2 ; i++) hash[s[i] - 'a']++;
        long long use1 = comb(hash, k);
        if(use1 < k) return "";
        long long count = n/2;
        string ans = "";
        for(int i = 0 ; i < n/2 ; i++){
            for(int j = 0 ; j < 26 ; j++){
                if(hash[j] > 0){
                    hash[j]--;
                    long long val = comb(hash, k);
                    hash[j]++;
                    if(val >= k){
                        ans += ('a' + j);
                        hash[j]--;
                        count--;
                        use1 = val;
                        break;
                    }
                    else{
                        k -= val;
                    }
                }
            }
            if(k == 1) break;
        }
        for(int i = 0 ; i < 26 ; i++){
            int use = hash[i];
            while(use--) ans += ('a' + i);
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if(n % 2 == 1) ans += s[n/2];
        for(const char& ch : rev) ans += ch;
        return ans;
    }
};