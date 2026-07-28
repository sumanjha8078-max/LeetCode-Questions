class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0 ; i < n/2 ; i++){
            ans += s[i];
        }
        sort(ans.begin(), ans.end());
        string use = ans;
        reverse(use.begin(), use.end());
        if(n % 2 != 0) ans += s[n/2];
        for(const char& ch : use) ans += ch;
        return ans;
    }
};