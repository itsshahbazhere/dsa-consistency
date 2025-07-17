// question - 1
#include <bits/stdc++.h> 

bool isVowel(char ch){
    if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u'){
        return true;
    } 
    return false;
}

string encodeString(string &s, int n) 
{
    for(int i=0; i<s.length(); i++){
        if(isVowel(s[i])){
            s[i]++;
        }
        else{
            s[i]--;
        }
    }
    return s;
}
