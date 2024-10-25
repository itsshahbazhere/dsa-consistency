// https://leetcode.com/problems/counting-bits/


//Approach - 1 -Beats 100% -dynamic programing
// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(N)

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1);
        
        for(int i=0; i<=n; i++){

            ans[i] = ans[i>>1] + (i&1);
        }

        return ans;
    }
};





//Approach - 2  -Beats 100%
// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(N)

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1,0);
        for(int i=0; i<=n; i++){
            int cnt =__builtin_popcount(i); //STL
            ans[i] = cnt;
        }

        return ans;
    }
};


//Approach - 3  
// TIME COMPLEXITY - O(nlogn)
// SPACE COMPLEXITY - O(N)


class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1);
        for(int i=0; i<=n; i++){

            int cnt = 0;
            int num = i;
            while(num!=0){
                if(num&1 == 1){
                    cnt++;
                }
                num = num>>1;
            }
            ans[i] = cnt;
        }

        return ans;
    }
};