class Solution {
public:
    int vowel_count(string &word){
         int count =0;
         for(char ch : word){
            if(ch=='a' || ch=='e' || ch=='i' || ch == 'o' || ch == 'u'){
                count++;
            }
         }
         return count;
    }
    string rev(string word){
        string ans = "";
        for(int i=word.length()-1;i>=0;i--){
            ans+=word[i];
        }
        return ans;
    }
    string reverseWords(string s) {
          int n = s.length();
          int original_count =0;
          int i=0;
          string first_word = "";
          while(s[i]!=' ' && i<n){
             first_word+=s[i];
             i++;
          }
          original_count = vowel_count(first_word);
           string ans ="";
           ans+=first_word;
          for(int j=i+1;j<n;j++){
            if(s[j]==' ') continue;
            string word = "";
            while(s[j]!=' ' && j<n){
                word+=s[j];
                j++;
            }
            int count_vowel = vowel_count(word);
            if(count_vowel == original_count){
                string neww = rev(word);
                ans+=" "+neww;
            }
            else{
                ans+=" "+word;
            }
        }
      return ans;
    }
};