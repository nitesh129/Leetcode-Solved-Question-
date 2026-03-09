class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
       int minCapacity = INT_MAX;
        int index = -1;

        for(int i = 0; i < capacity.size(); i++){
            if(capacity[i] >= itemSize && capacity[i] < minCapacity){
                minCapacity = capacity[i];
                index = i;
            }
        }

        return index;
    }
};