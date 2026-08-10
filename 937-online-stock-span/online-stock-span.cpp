class StockSpanner {
public:
    vector<int> prices;
    stack<int> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        
        prices.push_back(price);
        
        int n = prices.size();
        int span = 0;
        
        while (!st.empty() && prices[st.top()] <= price)
            st.pop();
    
        if (!st.empty())
            span = n - 1 - st.top();
        else span = n;

        st.push(n - 1);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */