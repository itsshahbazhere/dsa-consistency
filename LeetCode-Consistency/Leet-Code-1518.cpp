// 1518. Water Bottles
// https://leetcode.com/problems/water-bottles/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int emptyBottles = numBottles; // 15
        int drinkBottles = numBottles; //15
        int exchangeBottles = emptyBottles / numExchange; //3,3

        while(emptyBottles >= numExchange){ //15>4 6>4 3>4

            drinkBottles += exchangeBottles; //15+3=18+1=19
            emptyBottles += exchangeBottles - exchangeBottles*numExchange; //15+3-12=6+1-4=3
            exchangeBottles = emptyBottles / numExchange; //1,2 //0,3

        }

        return drinkBottles;
        
    }
};