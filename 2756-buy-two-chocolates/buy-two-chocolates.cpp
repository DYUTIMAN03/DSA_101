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