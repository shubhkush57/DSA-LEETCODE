class StockSpanner {
public:
    stack<pair<int,int>>stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int days  =1;
        while(!stk.empty() && stk.top().first<=price){
            days += stk.top().second;
            stk.pop();

        }
        stk.push({price,days});

        return days; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */