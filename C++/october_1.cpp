class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        long ans=numBottles;
        long count=0;
        while(numBottles>=numExchange)
        {
        count=numBottles/numExchange;
        ans+=count;
        numBottles%=numExchange;
        numBottles+=count;
        }
        return ans;
    }
};