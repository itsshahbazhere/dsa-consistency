// https://leetcode.com/problems/last-stone-weight/description/


//approach 2
// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(n)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq(stones.begin(), stones.end());

        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            if(first!= second){
                pq.push(first-second);
            }

        }

        return pq.empty()? 0 : pq.top();
    }
};





//approach 1
// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(true){
            int first_max = -1;
            int second_max = -1;
            int idx1 = -1;
            int idx2 = -1;

            for(int i=0; i<stones.size(); i++){

                if(stones[i] == 0){
                    continue;
                }
                else if(stones[i]>first_max){
                    second_max = first_max;
                    first_max = stones[i];
                    idx2 = idx1;
                    idx1 = i;
                    
                }
                else if(stones[i]>second_max){
                    second_max = stones[i];
                    idx2 = i;
                }
            } 

            if(second_max == -1 && first_max == -1){
                return 0;
            }
            else if(second_max == -1){
                return first_max;
            }
            if(first_max == second_max){
                stones[idx1] = 0;
                stones[idx2] = 0;
            }
            else{
                stones[idx1] = first_max - second_max;
                stones[idx2] = 0;
            }
        }

        return 0;
    }
};