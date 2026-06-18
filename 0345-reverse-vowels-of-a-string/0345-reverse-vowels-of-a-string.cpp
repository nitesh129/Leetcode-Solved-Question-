class Solution {
public:
    bool isvowel(char ch){
        return ch == 'A'||  ch == 'E' || ch == 'I'|| ch == 'O'||ch == 'U' || ch == 'a'|| ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u';
    }
    string reverseVowels(string s) {
       int n = s.length();
       int i=0;
       int j=n-1;
       while(i<j){
          if(isvowel(s[i]) && isvowel(s[j])){
              swap(s[i],s[j]);
              i++;
              j--;
          }
          else if(isvowel(s[i]))j--;
          else if(isvowel(s[j]))i++;
          else {
             i++;
             j--; // no one is vowel 
          }

       }
       return s;
    }
};