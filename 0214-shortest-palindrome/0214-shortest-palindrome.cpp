#define mod (1000000007)
class Solution {
public:
    string shortestPalindrome(string s) {
        long long a = 0, b = 0;
        string use = s;
        int n = s.length();
        long long mul = 1;
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            a = a*29 + ((s[i] - 'a') + 1);
            b = b + mul*((use[i] - 'a') + 1);
            a %= mod;
            b %= mod;
            mul *= 29;
            mul %= mod;
            if(a == b){
                idx = i;
            }
        }
        string extra = "";
        for(int i = idx + 1 ; i < n ; i++) extra += s[i];
        reverse(extra.begin(), extra.end());
        string fans = "";
        for(const char& ch : extra) fans += ch;
        for(const char& ch : s) fans += ch;
        return fans;
    }
};