//  Duplicate In Array link:https://www.naukri.com/code360/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1&leftPanelTabValue=PROBLEM

//we can do in a signle for loop as well
int findDuplicate(vector<int> &arr) 
{
    int size = arr.size();
    int ans = 0;
    for(int i=0; i<size; i++){
        ans^=arr[i];
        if(i){
            ans^=i;
        }
    }

    return ans;
	
}


int findDuplicate(vector<int> &arr) 
{
    //XOR in all array element
    int ans=0;
    for(int i=0; i<arr.size();i++){
        ans=ans^arr[i];

    }
    //xor 1 to (n-1)

    for(int i=1; i<arr.size();i++){
        ans=ans^i;
    }

    return ans;
	
}

