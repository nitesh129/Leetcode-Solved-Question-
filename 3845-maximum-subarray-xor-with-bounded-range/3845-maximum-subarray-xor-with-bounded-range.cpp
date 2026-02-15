class Solution {
public:
    struct TrieNode {
        TrieNode* child[2];
        int count;
        
        TrieNode() {
            child[0] = child[1] = nullptr;
            count = 0;
        }
    };
    
    class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(int num) {
            TrieNode* node = root;
            for (int i = 15; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!node->child[bit])
                    node->child[bit] = new TrieNode();
                node = node->child[bit];
                node->count++;
            }
        }
        
        void remove(int num) {
            TrieNode* node = root;
            for (int i = 15; i >= 0; i--) {
                int bit = (num >> i) & 1;
                node = node->child[bit];
                node->count--;
            }
        }
        
        int maxXor(int num) {
            TrieNode* node = root;
            int ans = 0;
            
            for (int i = 15; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int opposite = 1 - bit;
                
                if (node->child[opposite] && node->child[opposite]->count > 0) {
                    ans |= (1 << i);
                    node = node->child[opposite];
                } else {
                    node = node->child[bit];
                }
            }
            
            return ans;
        }
    };
    int maxXor(vector<int>& nums, int k) {
          int n = nums.size();

            deque<int> minD, maxD;
            vector<int> px(n + 1, 0);

            for (int i = 0; i < n; i++)
                px[i + 1] = px[i] ^ nums[i];

            Trie trie;
            int left = 0;
            int ans = 0;

        trie.insert(px[0]);  // initially empty prefix

       for (int right = 0; right < n; right++) {

        // Maintain min deque
        while (!minD.empty() && nums[minD.back()] > nums[right])
            minD.pop_back();
        minD.push_back(right);

        // Maintain max deque
        while (!maxD.empty() && nums[maxD.back()] < nums[right])
            maxD.pop_back();
        maxD.push_back(right);

        // Shrink window if invalid
        while (!minD.empty() && !maxD.empty() &&
               nums[maxD.front()] - nums[minD.front()] > k) {

            trie.remove(px[left]);

            if (minD.front() == left)
                minD.pop_front();
            if (maxD.front() == left)
                maxD.pop_front();

            left++;
        }

        // Query maximum XOR for subarrays ending at right
        ans = max(ans, trie.maxXor(px[right + 1]));

        // Insert current prefix
        trie.insert(px[right + 1]);
     }

    return ans;

  }
};