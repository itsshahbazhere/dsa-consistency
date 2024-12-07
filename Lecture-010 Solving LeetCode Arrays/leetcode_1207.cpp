// 1207. Unique Number of Occurrences
// link:https://leetcode.com/problems/unique-number-of-occurrences/description/


// TIME COMPLEXITY - O(nlogn)
// SPACE COMPLEXITY - O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        vector<int>counts;
        sort(arr.begin(),arr.end());
        int cnt=1;

        for(int i=0; i<arr.size(); i++){
            
            if(i+1<arr.size() && arr[i] == arr[i+1]){
                cnt++;
            }
            else{

                counts.push_back(cnt);
                cnt=1;
            }
        }

        sort(counts.begin(), counts.end());
        for(int i=0; i<counts.size(); i++){
            if(i+1<counts.size() && counts[i] == counts[i+1]) return false;
        }

        return true;
        
    }
};



// TIME COMPLEXITY - O(N^2)
// SPACE COMPLEXITY - O(N)
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