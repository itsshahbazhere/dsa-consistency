// 3Sum 
// link: https://www.naukri.com/code360/problems/triplets-with-given-sum_893028

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());

    for(int i=0;i<n;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum>K){
                k--;
            }
            else if(sum<K){
                j++;
            }
            else{
                vector<int>temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }

    return ans;
}