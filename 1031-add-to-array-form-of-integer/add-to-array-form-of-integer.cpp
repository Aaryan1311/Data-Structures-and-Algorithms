class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int c = 0;
        for(int i = num.size()-1;i>=0;i--){
            int val = num[i] + k%10 + c;
            if(val > 9){
                c = 1;
                val -= 10;
            }
            else c = 0;
            num[i] = val;
            k /= 10;
        }
        if(c == 0 && k == 0) return num;
        else if(c != 0 && k == 0){
            vector<int> v;
            v.push_back(1);
            for(int i : num) v.push_back(i);
            return v;
        }
        else if(k != 0 && c == 0){
            vector<int> v;
            while(k > 0){
                v.push_back(k%10);
                k /= 10;
            }
            reverse(v.begin(),v.end());
            for(int i : num) v.push_back(i);
            return v;
        }
        else{
            vector<int> v;
            int val = 0;
            while(k > 0){
                val = k%10 + c;
            if(val > 9){
                c = 1;
                val -= 10;
            }
            else c = 0;
                v.push_back(val);
                k /= 10;
            }
            if(c != 0) v.push_back(1);
            reverse(v.begin(),v.end());
            for(int i : num) v.push_back(i);
            return v;
        }
    }
};