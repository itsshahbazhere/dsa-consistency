// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1?page=1&difficulty%5B%5D=1&category%5B%5D=Tree&sortBy=submissions


#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long perfectPairs(vector<int>& nums) {

//         int n = nums.size();
//         long long cnt = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int a = nums[i];
//                 int b = nums[j];
//                 if(min(abs(a-b),abs(a+b))<=min(abs(a),abs(b)) && max(abs(a-b),abs(a+b))>=max(abs(a),abs(b))){
//                     cnt++;
//                 }
//             }
//         }

//         return cnt;
//     }
// };


// class Solution {
// public:
//     int minSensors(int n, int m, int k) {

//         int range = 2*k+1;
//         int ans = 0;

//         for(int i=1; i<=n; i++){
//             if(range*i >= n){
//                 ans = i;
//                 break;
//             }
//         }

//         int remHeight = m - 2*k - 1;
//         if(remHeight<1){
//             return ans;
//         }
//         else{
//             for(int j=1; j<=m; j++){
//                 if(range*j>=remHeight){
//                     ans = ans + ans*j;
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }
    
// };

class Solution {
public:
    int minSensors(int n, int m, int k) {

        int range = 2*k+1;
        int a = ceil(n/range);
        int b = ceil(m/range);
        cout<<a<<" "<<b<<endl;

        return  a*b;
    }
    
};


int main(){

    Solution obj;
    cout<<obj.minSensors(5,5,1)<<endl;

    cout<<ceil((float)5/3)<<endl;


    return 0;
}