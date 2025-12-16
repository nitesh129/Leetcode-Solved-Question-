class Solution {
public:
    typedef pair<int,int>p;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int ,vector<p>>time_meetings;
        for(auto &meeting : meetings){
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time =  meeting[2];
            time_meetings[time].push_back({person1,person2});
        }
        vector<bool>know_secret(n,false);
        know_secret[0] = true;
        know_secret[firstPerson] = true;
        for(auto &it : time_meetings){
            int t = it.first;
            vector<p> meets = it.second;
            unordered_map<int,vector<int>>adj; // person1 -> {person2 , perosn 3 , person4}
            unordered_set<int>visited; // dont push the person who know the secret in queue twice
            queue<int>que; // store the person who know the secret and spread the secret by using the bfs 
            for(auto &[person1,person2] : meets){
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);
                if(know_secret[person1] == true && !visited.count(person1)){
                    que.push(person1);
                    visited.insert(person1);
                }
                if(know_secret[person2] == true && !visited.count(person2)){
                    que.push(person2);
                    visited.insert(person2);
                }

            }
            while(!que.empty()){
                int curr_person = que.front();
                que.pop();
                for(auto & nextperson : adj[curr_person]){
                    if(know_secret[nextperson]==false){
                        know_secret[nextperson]= true;
                        que.push(nextperson);
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<know_secret.size();i++){
            if(know_secret[i]==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};