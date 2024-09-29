// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {


        vector<int>ans;

        //count numbers and store in ans
        for(int i=0; i<arr.size(); i++){

            int cnt = 1;
            if(arr[i] == 1001) continue;
            for(int j=i+1; j<arr.size(); j++){
                if(arr[i] == arr[j]){
                    cnt++;
                    arr[j] = 1001;
                }
            }
            ans.push_back(cnt);
        }

        //checking all count is unique
        for(int i=0; i<ans.size(); i++){
            for(int j=i+1; j<ans.size(); j++){
                if(ans[i] == ans[j]){
                    return false;
                }
            }
        }


        return true;
    
    }
};