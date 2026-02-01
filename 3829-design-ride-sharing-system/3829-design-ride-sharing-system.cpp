class RideSharingSystem {
public:
    queue<int> riders;
    queue<int> drivers;
    unordered_set<int> activeRiders;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        activeRiders.insert(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {
        while(!riders.empty() && activeRiders.count(riders.front())==0){
            riders.pop();
        }
        if(riders.empty() || drivers.empty()){
            return {-1,-1};
        }
        int driver = drivers.front() ; drivers.pop();
        int rider = riders.front() ; riders.pop();
        activeRiders.erase(rider);
        return {driver , rider};
    }
    
    void cancelRider(int riderId) {
      activeRiders.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */