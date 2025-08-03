// https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/1722287967/

#include<bits/stdc++.h>
using namespace std;

//approach - 2 using queue
// T.C - O(N^2)
// S.C- O(N)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<int>q;
        for(int i=0; i<tickets.size(); i++){
            q.push(i);
        }

        int time = 0;
        while(tickets[k] != 0){
            tickets[q.front()]--;
            if(tickets[q.front()]>0){
                q.push(q.front());
            }
            q.pop();
            time++;
        }

        return time;
    }
};


// approach - 1 -- by rohit negi (same logic but code efficient)
// T.C - O(N)
// S.C- O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int time = 0;
        for(int i=0; i<=k; i++){
            time+=min(tickets[i],tickets[k]);
        }

        for(int i=k+1; i<tickets.size(); i++){
            time+=min(tickets[i],tickets[k]-1);
        }

        return time;
    }
};

// approach - 1 by me
// T.C - O(N)
// S.C- O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int cnt = 0;
        for(int i=0; i<=k; i++){
            if(tickets[i]<=tickets[k]){
                cnt+=tickets[i];
            }
            else{
                cnt+=tickets[k];
            }
        }

        for(int i=k+1; i<tickets.size(); i++){
            if(tickets[i]<tickets[k]){
                cnt+=tickets[i];
            }
            else{
                cnt+=tickets[k]-1;
            }
        }

        return cnt;
    }
};