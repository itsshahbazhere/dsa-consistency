// Painter’s Partition Problem: https://bit.ly/31v3Jiy 

//TIME COMPLEXITY = O(log(high-low+1)*N)
//SPACE COMPLEXITY = O(1)

bool isPossible(vector<int> &boards, int k, int mid){

    int count=1;
    int boardSum = 0;

    for(int  i=0; i<boards.size(); i++){
        if(boardSum+boards[i] <= mid){
            boardSum+=boards[i];
        }
        else{
            count++;
            if(count>k){
                return false;
            }
            boardSum=boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = *max_element(boards.begin(), boards.end());
    int e = accumulate(boards.begin(), boards.end(),0);
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s<=e){

        if(isPossible(boards,k,mid)){
            e=mid-1;
            ans=mid;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;

    }
    return ans;
}