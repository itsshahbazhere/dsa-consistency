// 443. String Compression
// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i=0;
        int n = chars.size();
        int ansIndex = 0;
        while(i<n){
            int j=i+1;
            while(j<n && chars[i] == chars[j]){
                j++;
            }
            chars[ansIndex++] = chars[i];
            int count = j-i;
            if(count>1){
                string cnt = to_string(count);
                for(int k=0; k<cnt.length(); k++){
                    chars[ansIndex++] = cnt[k];
                }
            }

            i=j;
        }

        return ansIndex;
    }
};