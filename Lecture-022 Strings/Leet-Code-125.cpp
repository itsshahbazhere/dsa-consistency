// - Valid Palindrome : https://leetcode.com/problems/valid-palindrome/

//optimised code------->

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
private:
char toLowerCase(char ch){
    if(ch>='A' && ch<='Z'){
        return ch-'A'+'a';
    }
    return ch;
}

bool alphaNumeric(char ch){
    return((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}

public:
    bool isPalindrome(string s) {

        int i=0;
        int j=s.size()-1;

        while(i<=j){

            while(i<j && !alphaNumeric(s[i])) i++;
            while(i<j && !alphaNumeric(s[j])) j--;

            if(toLowerCase(s[i]) != toLowerCase(s[j])){
                return false;
            }
            i++;
            j--;

            
        }

        return true;
        
    }
};




// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
private:
    char toLowerCase(char ch){
        if ((ch>= 'a' && ch<= 'z') || (ch>='0' && ch<='9')) {
            return ch;
        }
        return ch-'A'+'a';
    }
    bool isAlphaNumeric(char ch){
        return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' &&ch<='9'));
    }
    bool checkPalindrome(string s){

        int start=0;
        int end= s.length()-1;

        while(start<=end){
            if((s[start] != s[end])){
                return 0;
            }
            else{
                start++;
                end--;
            }
        }
        return 1;
    }

public:
    
    bool isPalindrome(string s) {
       
       //removing non-alphanumeric character
        string temp = "";
        for(int i=0; i<s.length(); i++){
            if(isAlphaNumeric(s[i])){
                temp.push_back(s[i]);
            }
            
        }

        //converting entire string in lowercase
        for(int i=0;i<temp.length();i++){
            temp[i] = toLowerCase(temp[i]); 
        }

        return checkPalindrome(temp);
    }
};





class Solution {
public:
    char toLowerCase(char ch){
        if(ch>= 'a' && ch<= 'z'){
            return ch;
        }
        return ch-'A'+'a';
    }
    bool isAlpha(char ch){
        return ((ch>='a' && ch<='z') || (ch>= 'A' && ch<='Z'));
    }
    bool isNumeric(char ch){
        return (ch>='0' && ch<= '9');
    }
    bool isAlphaNumeric(char ch){
        return (isAlpha(ch) || isNumeric(ch));
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start<=end){

            if( isAlphaNumeric(s[start]) && isAlphaNumeric(s[end]) ){
                if( toLowerCase(s[start]) ==  toLowerCase(s[end]) ){
                    start++;
                    end--;
                }
                else{
                    return 0;
                }
            }
            else if(!isAlphaNumeric(s[start])){
                start++;
            }
            else{ //!isAlphaNumeric(s[end]
                end--;
            }
        }

        return 1;
    }
};