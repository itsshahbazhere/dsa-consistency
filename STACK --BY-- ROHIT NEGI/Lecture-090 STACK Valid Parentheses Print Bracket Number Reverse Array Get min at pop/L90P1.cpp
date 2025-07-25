#include<iostream>
#include<stack>
using namespace std;

// USING STACK
// T.C- O(N)
// S.C- O(N)

bool validParenthesis(string s, stack<char>st){

    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            st.push('(');
        }
        else{
            if(st.empty()){
                return 0;
            }
            else{
                st.pop();
            }
        } 
    }

    return st.size()==0;
}


// USING NORMAL APPROACH
// T.C- O(N)
// S.C- O(1)

bool isValidParenthesis(string s){

    int left = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            left++;
        }
        else{
            if(left == 0){
                return 0;
            }
            else{
                left--;
            }
        } 
    }

    return left==0;
}

int main(){

    stack<char>st;
    string s;
    cout<<"Enter a parenthesis string - ";
    cin>>s;

    
    cout<<"checking parenthisis is valid or not - "<<validParenthesis(s,st);
    cout<<"checking parenthisis is valid or not - "<<isValidParenthesis(s);

    
    
}