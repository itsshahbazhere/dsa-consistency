https://leetcode.com/problems/boats-to-save-people/

// TIME COMPLEXITY - O(nlogn)
// SPACE COMPLEXITY - O(1)

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

       //sorting array in ascending order
        sort(people.begin(), people.end());

        int start = 0;
        int end = people.size()-1;
        int boatsCount = 0;

        while(start <= end){
            
            if(people[start] + people[end] <= limit){
                boatsCount++;
                start++;
                //end--;
            }
            else{
                boatsCount++;
                //end--;
            }
            end--; //declare one time
        }

        return boatsCount;

        
    }
};