class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int curr = 0;
        int mx = 0;
        map<char,int> mp;
        while(r < s.size()){
            if(mp.find(s[r]) == mp.end() || mp[s[r]] == 0){
                mp[s[r]]++;
                r++;
                curr++;
            }
            else{
                mx = max(mx,curr);
                while(mp[s[r]] != 0){
                    mp[s[l]]--;
                    curr--;
                    l++;
                }
            }
        }
        mx = max(mx,curr);
        return mx;
    }
};