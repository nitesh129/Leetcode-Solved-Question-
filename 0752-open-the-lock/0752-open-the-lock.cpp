class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>visited (deadends.begin(), deadends.end());
        queue<string>que;
        int level=0;
        que.push("0000");
       if (visited.count("0000")) return -1;
        while(!que.empty()){
            int N = que.size();
            while(N--){
                string curr = que.front();
                que.pop();
                if(curr == target) return level;
                for(int i=0;i<4;i++){
                    char ch = curr[i];
                    curr[i] = (ch == '9' ? '0' : ch + 1);
                    if(!visited.count(curr)){
                        que.push(curr);
                        visited.insert(curr);
                    }
                    curr[i] = (ch == '0' ? '9' : ch - 1);
                    if(!visited.count(curr)){
                        que.push(curr);
                        visited.insert(curr);
                    }
                    curr[i] = ch;

                }
            }
            level++;
        }
        return -1;
    }
};