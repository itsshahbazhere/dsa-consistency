#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void print(vector<int>arr, int n, int k){
    queue<int>q;

    for(int i=0; i<k-1 && i<n; i++){
        q.push(arr[i]);
    }

    for(int i=k-1; i<n; i++){

        q.push(arr[i]);
        int p = k;

        while(p--){
            cout<<q.front()<<" ";
            q.push(q.front());  
            q.pop();
        }

        q.pop();
        cout<<endl;
    }

}

int main(){

    vector<int>arr={1,5,6,7,9,2,3,4};
    print(arr,arr.size(),3);

    
    return 0;

}