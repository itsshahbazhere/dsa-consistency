// https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=PROBLEM



// TIME COMPLEXITY = O(N^2)
// SPACE COMPLEXITY = O(1)
// optimal approach
#include <bits/stdc++.h> 
long long mergeArr(long long *&arr, int low, long long mid, int high){

    vector<long long>temp;
    int left = low;
    int right = mid+1;
    long long cnt = 0;

    while(left<=mid && right<=high){

        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

    return cnt;

}
long long mergeSort(long long *&arr, int low, int high){

    long long cnt = 0;

    if(low>=high) return cnt;
    long long mid = low + (high - low)/2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += mergeArr(arr, low, mid, high);

    return cnt;

}
long long getInversions(long long *arr, int n){
    
    return mergeSort(arr,0,n-1);
   
}



// TIME COMPLEXITY = O(N^2)
// SPACE COMPLEXITY = O(1)

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    
    long long cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }

    return cnt;
}