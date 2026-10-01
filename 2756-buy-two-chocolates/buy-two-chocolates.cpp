class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        int a = INT_MAX;
        int b = INT_MAX;

        for(int x: prices){
            if(x<a){
                b = a;
                a = x;
            }
            else if(x<b){
                b = x;
            }
        }

        int cost = a + b;

        if(cost <= money) return money - cost;
        return money;
    }
};

/*
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int cost = prices[0] + prices[1];

        if (cost <= money)
            return money - cost;

        return money;
    }
};
*/