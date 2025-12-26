class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        // prefixY[i] = number of 'Y' in customers[0..i-1]
        vector<int> prefixY(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixY[i + 1] = prefixY[i] + (customers[i] == 'Y');
        }

        int totalY = prefixY[n];
        int bestHour = 0;
        int minPenalty = INT_MAX;

        for (int j = 0; j <= n; j++) {
            int openHours = j;
            int openY = prefixY[j];
            int openN = openHours - openY;           // hours we were open but no customers
            
            int closedY = totalY - prefixY[j];       // hours we were closed but customers arrived
            
            int penalty = openN + closedY;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};
