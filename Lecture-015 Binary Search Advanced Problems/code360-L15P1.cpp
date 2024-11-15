// Question Links:
// - Book Allocation Problem: https://www.naukri.com/code360/problems/allocate-books_1090540

//brute force logic --binary search
//TIME COMPLEXITY = O(log(high-low+1)*N)
//SPACE COMPLEXITY = O(1)

int countStu(vector<int>& arr, int pages){

    int stu=1;
    int pagesStudent = 0;
    for(int i=0; i<arr.size(); i++){
        if(pagesStudent+arr[i] <= pages){
            pagesStudent+=arr[i];
        }
        else{
            stu++;
            pagesStudent=arr[i];
        }
    }
    return stu;
}


int findPages(vector<int>& arr, int n, int m) {

    if(n<m) return -1;
    
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int stuCnt = countStu(arr, mid);
        if(stuCnt>m){
            low = mid+1;
        }
        else{
            high = mid-1;
            ans = mid;
        }

    }

    return ans;

}


//brute force logic --linear search
//TIME COMPLEXITY = O((high-low+1)*N)
//SPACE COMPLEXITY = O(1)

int countStu(vector<int>& arr, int pages){

    int stu=1;
    int pagesStudent = 0;
    for(int i=0; i<arr.size(); i++){
        if(pagesStudent+arr[i] <= pages){
            pagesStudent+=arr[i];
        }
        else{
            stu++;
            pagesStudent=arr[i];
        }
    }
    return stu;
}


int findPages(vector<int>& arr, int n, int m) {

    if(n<m) return -1;
    
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    for(int pages=low; pages<=high; pages++){

        int cntStu = countStu(arr,pages);
        if(cntStu == m){
            return pages;
        }
    }

    return -1;

}