class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int l = 0;
        int r = 0;
        int wcnt = 1;
        while(r < sentence.size()){
            if(sentence[r] == ' ') wcnt++;
            else{
                int rr = r;
                while(l < searchWord.size() && rr < sentence.size() && sentence[rr] == searchWord[l] && (rr == 0 || sentence[rr-1] == ' ' || l != 0)){
                    cout << sentence[rr];
                    l++;
                    rr++;
                }
                if(l == searchWord.size()) return wcnt;
                else if(rr == sentence.size()) return -1;
                else l = 0;
            }
            r++;

        }
        return -1;
    }
};