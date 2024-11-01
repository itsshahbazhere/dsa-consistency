//  Pair Sum link: https://www.naukri.com/code360/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1


#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   
   vector<vector<int>>ans;
   for(int i=0; i<arr.size(); i++){
      vector<int>pair(2);
      for(int j=i+1; j<arr.size(); j++){
         if(arr[i]+arr[j] == s){
            pair[0] = min(arr[i],arr[j]);
            pair[1] = max(arr[i], arr[j]);
            ans.push_back(pair);
            
         }
      }
      
   }
   sort(ans.begin(), ans.end());
   return ans;

}





#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
  
  vector<vector<int>> ans;
   for(int i=0;i<arr.size();i++){

      for(int j=i+1;j<arr.size();j++){

         if(arr[i]+arr[j]==s){
            vector<int> temp;
            //1st put min then max for sorted output
            temp.push_back(min(arr[i],arr[j]));
            temp.push_back(max(arr[i],arr[j]));
            ans.push_back(temp);
         }
      }
   }
   sort(ans.begin(), ans.end());
   return ans;
}



