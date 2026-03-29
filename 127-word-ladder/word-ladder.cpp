class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        for(string s : wordList) words.insert(s);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        words.erase(beginWord);
        while(!q.empty()){
            pair<string,int> p = q.front();
            string s = p.first;
            int step = p.second;
            for(int i = 0;i<s.size();i++){
                string temp = s;
                for(int j = 0;j<26;j++){
                    temp[i] = (char)('a'+j);
                    if(words.find(temp) != words.end()){
                        if(temp == endWord) return step+1;
                        words.erase(temp);
                        q.push({temp,step+1});
                    } 
                }
            }
            q.pop();
        }
        return 0;
    }
};