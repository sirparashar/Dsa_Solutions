class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWaitTime = 0;
        int curt = 0;
        
        for(int i = 0; i < customers.size(); i++) {
            // If the current time is less than the customer's arrival time, update current time to the arrival time
            if (curt < customers[i][0]) {
                curt = customers[i][0];
            }
            // Calculate the waiting time for the current customer
            int waitTime = curt + customers[i][1] - customers[i][0];
            // Update the total waiting time
            totalWaitTime += waitTime;
            // Update the current time to when this customer's service is completed
            curt += customers[i][1];
        }

        // Calculate and return the average waiting time
        return totalWaitTime / customers.size();
    }
};
