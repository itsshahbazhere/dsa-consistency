// 69. Sqrt(x)
// link: https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        
        int start = 0;
        int end = x;
        long long int mid = start+ (end-start)/2;
        int ans = -1;
       
        while(start<=end){

            long long int prod = mid*mid;

            if(prod == x){
                return mid;

            }
            else if(prod > x){
                end = mid-1;
            }
            else{
                start = mid+1;
                ans=mid;
            }
            mid = start+ (end-start)/2;

        }


        return ans;
    }
};