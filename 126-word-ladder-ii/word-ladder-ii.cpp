class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> level;
    vector<vector<string>> ans;
    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.size();
        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currLevel = level[word];
            string temp = word;

            for (int i = 0; i < wordLen; i++) {
                char original = temp[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                    if (dict.count(temp)) {
                        if (!level.count(temp)) {
                            level[temp] = currLevel + 1;
                            q.push(temp);
                            parent[temp].push_back(word);
                        }
                        else if (level[temp] == currLevel + 1) {
                            parent[temp].push_back(word);
                        }
                    }
                }
                temp[i] = original;
            }
        }
        if (level.count(endWord)) {
            vector<string> path = {endWord};
            dfs(endWord, beginWord, path);
        }

        return ans;
    }
};