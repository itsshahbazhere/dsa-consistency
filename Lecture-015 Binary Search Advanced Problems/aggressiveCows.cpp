// - Aggressive Cows: https://bit.ly/3dkuQ2B 

//TIME COMPLEXITY = O(log(maxi-mini)*N)
//SPACE COMPLEXITY = O(1)

bool isPossible(vector<int> &stalls, int k,int mid){

    int countCow = 1;
    int lastPos = stalls[0];

    for(int i=1; i<stalls.size(); i++){

        if(stalls[i]-lastPos >= mid){
            countCow++;
            if(countCow==k){
                return true;
            }
            lastPos=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());
    int s=0;
    int e= maxi-mini;
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        
        if(isPossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}