// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/description/


//optimised solution 100% beats tc- O(N+M)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>arr1(1001,0);
        vector<int>arr2(1001,0);

        for(int i=0;i<nums1.size();i++){
            int index = nums1[i];
            arr1[index]++;  //not use index-1 bcz if value is zero give error
        }
        for(int i=0;i<nums2.size();i++){
            int index = nums2[i];
            arr2[index]++;
        }

        nums1.clear();
        for(int i=0;i<1001;i++){
            if(arr1[i] >= 1 && arr2[i] >= 1){
               
                nums1.push_back(i);
            }
        }

        return nums1;

    }
};



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        //using set to remove duplicate element
        set<int>ans; 
        int i = 0;
        int n = nums1.size();
        int m = nums2.size();
        while(i<n){
            int j=0;
            while(j<m){
                if(nums1[i] == nums2[j]){
                    ans.insert(nums1[i]);
                }
                j++;
            }
            i++;
        }

        //agin convet ans into vector form bcz return type is vector
        vector<int>uniqueAns(ans.begin(),ans.end());
        return uniqueAns;
    }
};


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0;
        int j=0;

        vector<int>ans;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                if(ans.size() == 0){
                    ans.push_back(nums1[i]);

                }
                else if(ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
                }
                
                i++;
                j++;
                
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }

        return ans;
        
    }
};