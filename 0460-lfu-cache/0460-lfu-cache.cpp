class LFUCache {
public:
    int cap;
    int size;
    map<int,list<vector<int>>>freq;
    unordered_map<int , list<vector<int>>::iterator>mp;
    LFUCache(int capacity) {
        cap = capacity;
        size=00;
    }
    void makemostfreqused(int key){
        auto&vec = *(mp[key]);
        int val  = vec[1];
        int f = vec[2];
        freq[f].erase(mp[key]);
        if(freq[f].empty()){
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key,val,f});
        mp[key] = freq[f].begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        auto vec = *(mp[key]);
        int val = vec[1];
        makemostfreqused(key);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto &vec = *(mp[key]);
            vec[1] = value;
            makemostfreqused(key);
        }
        else if(size<cap){
            size++;
            freq[1].push_front(vector<int>({key,value,1}));
            mp[key] = freq[1].begin();
        } 
        else{
            auto &kaun_sa_list = freq.begin()->second;
            int key_to_delete = kaun_sa_list.back()[0];
            kaun_sa_list.pop_back();
            if(kaun_sa_list.empty()){
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front(vector<int>({key,value,1}));
            mp.erase(key_to_delete);
            mp[key]=freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */