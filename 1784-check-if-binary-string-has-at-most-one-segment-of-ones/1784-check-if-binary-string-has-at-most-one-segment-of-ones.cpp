class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.length()==1 && s[0] == '1') return true;
        int i=1;
        while(i<s.length() && s[i]=='1'){
            i++;
        }
        while(i<s.length()){
            if(s[i]=='1') return false;
            i++;
        }
        
          return true; 
    }
};