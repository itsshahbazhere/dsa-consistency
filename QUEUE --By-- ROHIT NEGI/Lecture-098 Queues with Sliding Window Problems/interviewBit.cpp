// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;



// Approach - 2
// T.C- O(n)
// S.C- O(n)

string solve1(string A) {
    string B = "";
    vector<char>cnt(26,0);
    queue<int>q;
    
    for(int i=0; i<A.length(); i++){
        if(cnt[A[i]-'a'] >= 1){
            cnt[A[i]-'a']++;
            while(!q.empty() && cnt[q.front()-'a'] > 1){
                q.pop();
            }
            if(q.empty()){
                B+='#';
            }
            else{
                B+=q.front();
            }  
        }
        else{
            cnt[A[i]-'a']++;
            q.push(A[i]);
            while(cnt[q.front()-'a'] > 1){
                q.pop();
            }
            B+=q.front();
        }
        
    }
    
    return B;
}





// Approach - 1 
// T.C- O(n^3)
// S.C- O(n)


char checkNonRepeated(vector<char>&repeated){
    
    for(int i=0; i<repeated.size(); i++){ 
        int cnt = 0;
        for(int j=0; j<repeated.size(); j++){
            if(repeated[i] == repeated[j]){
                cnt++; //1
                if(cnt == 2){
                    break;
                }
            }
        }
        if(cnt <= 1){
            return repeated[i];
        }
    }
    
    return '#';
}

string solve(string A) {
    string B = "";
    vector<char>repeated;
    
    for(int i=0; i<A.length(); i++){
        if(B==""){
            B+=A[i]; 
            repeated.push_back(A[i]); 
        }
        else{
            repeated.push_back(A[i]);
            B+=checkNonRepeated(repeated);
        }
        
    }
    
    return B;
}


int main(){

   cout<<solve1("abadbc")<<endl; //aabbdd
   cout<<solve1("abcacdbd")<<endl; //aaabbbd#
   
}