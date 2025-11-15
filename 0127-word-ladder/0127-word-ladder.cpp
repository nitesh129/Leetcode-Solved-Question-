class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>bank(begin(wordList),end(wordList));
        unordered_set<string>visited;
        queue<string>que;
        que.push(beginWord);
        int level=1;
        visited.insert(beginWord);
        while(!que.empty()){
            int N = que.size();
            while(N--){
                string result = que.front();
                que.pop();
                if(result == endWord) return level;
                for(char ch = 'a';ch<='z';ch++){
                    for(int i=0;i<result.length();i++){
                        string neighbour = result;
                        neighbour[i]=ch;
                        if(visited.find(neighbour) == visited.end() && bank.count(neighbour)){
                            que.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }
            }
            level++;
         }
      return 0;

    }
};