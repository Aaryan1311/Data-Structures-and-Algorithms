class Solution {
public:
    int countMonobit(int n) {
    int i=0;
    int count=0;
     while(pow(2,i)-1<=n){
        count++;
        i++;
     }
     return count;
    }
};

