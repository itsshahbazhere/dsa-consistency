// https://leetcode.com/problems/trapping-rain-water/


// Approach 3 
//Optimised than other approaches beats 100%
// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0;
        int right = n-1;
        int waterTrap = 0;

        int left_max = 0;
        int right_max = 0;
        while(left < right){

            if(height[left] <= height[right]){
                left_max = max(left_max, height[left]);
                waterTrap += left_max - height[left];
                left++;
            }
           
            else{ //(height[right] > height[left])
                right_max = max(right_max, height[right]);
                waterTrap += right_max - height[right]; 
                right--;
            }
        }
        return waterTrap;
    }
};


// Approach 2
// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(N)

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);

        int trapWater = 0;

        left[0] = height[0];
        right[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            left[i] = max(left[i-1],height[i]);
        }

        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1],height[i]);
        }
        
    
        for(int i=0; i<n; i++){
            trapWater += min(left[i],right[i]) - height[i];
        }

        return trapWater;
    }
};




// Approach 1
// TIME COMPLEXITY = O(N^2)
// SPACE COMPLEXITY = O(1)

class Solution {
public:
    int trap(vector<int>& height) {

        int trapWater = 0;

        for(int i=0; i<height.size(); i++){
            int left = i-1;
            int right = height.size()-1;
            int left_max = INT_MIN;
            int right_max = INT_MIN;

            for(int j=i; j>=0; j--){
                left_max = max(left_max , height[j]);
            }
             for(int k=i; k<height.size(); k++){
                right_max = max(right_max , height[k]);
            }

            trapWater += min(left_max, right_max) - height[i];
        }

        return trapWater;
        
    }
};