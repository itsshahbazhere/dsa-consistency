// https://leetcode.com/problems/median-of-two-sorted-arrays/

//1 think approach in O(log(n+m)) time complexity and space complexity O(1)




//2 this is done in O(n+m) time complexity and O(1) space complexity optimised than 3rd one

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i=0;
        int n = nums1.size();
        int j=0;
        int m = nums2.size();

        //find index that we want to need for median no need to create any vector bcz its need extra space
        int size=n+m;
        int idx1 = (size)/2;
        int idx2 = idx1 -1;

        int Ele1 = INT_MIN;
        int Ele2 = INT_MIN;

        int cnt=0;


        while(i<n && j<m){

            if(nums1[i] <=nums2[j]){
                if(cnt == idx1) Ele1 = nums1[i];
                if(cnt == idx2) Ele2 = nums1[i];

                i++;
                cnt++;
            }
            else{
                if(cnt == idx1) Ele1 = nums2[j];
                if(cnt == idx2) Ele2 = nums2[j];
                j++;
                cnt++;
            }
        }

        while(i<n){
            if(cnt == idx1) Ele1 = nums1[i];
            if(cnt == idx2) Ele2 = nums1[i];
            cnt++;
            i++;
        }
        while(j<m){

            if(cnt == idx1) Ele1 = nums2[j];
            if(cnt == idx2) Ele2 = nums2[j];
            j++;
            cnt++;
        }
        
        //finding median if the total size is odd or even
    
        if(size % 2 == 0){
            return (Ele1+Ele2)/2.0;
        }
        else{
            return Ele1;
        }

        return -1;
        
    }
};



//3 this is done in O(n+m) time complexity and O(n+m) space complexity

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i=0;
        int n = nums1.size();
        int j=0;
        int m = nums2.size();

        //merge to sorted array

        vector<int>ans;

        while(i<n && j<m){

            if(nums1[i] <=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }

        int size = ans.size();
        
        //finding median in odd or even size of new merge array

        if(size % 2 == 0){
            int mid = size/2;
            return (ans[mid-1] + ans[mid])/2.0;
        }
        else{
            return ans[size/2];
        }

        return -1;
        
    }
};