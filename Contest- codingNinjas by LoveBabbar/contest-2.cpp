// Contest 2  Link: https://bit.ly/3dUUrPK
// code-link: https://www.naukri.com/code360/contests/love-babbar-contest-ii/3583551/problems/14818?leftPanelTabValue=SUBMISSION


#include <bits/stdc++.h> 
int classTest(int n, vector<int> &a, int k) {

    // Sort in decreasing order (descending order)
    sort(a.begin(), a.end(), greater<int>()); 

    // reverse(a.begin(), a.end()); //no need to reverse
    
    int ans = a[k-1];
    return ans;

}

#include <bits/stdc++.h> 
int classTest(int n, vector<int> &a, int k) {
    sort(a.begin(), a.end(), greater<int>());
    return a[k-1];
}