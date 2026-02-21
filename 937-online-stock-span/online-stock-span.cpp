class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 0;
        while(!stk.empty() && stk.top().first <= price){
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({price,cnt+1});
        return cnt+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */