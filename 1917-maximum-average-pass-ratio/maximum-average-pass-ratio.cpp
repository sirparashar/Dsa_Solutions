class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        // Lambda to calculate the potential gain for adding one extra student
        auto gain = [](int pass, int total) -> double {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max-heap to store the potential gain and class index
        priority_queue<pair<double, int>> pq;

        // Populate the priority queue with initial gains
        for (int i = 0; i < classes.size(); i++) {
            double initialGain = gain(classes[i][0], classes[i][1]);
            pq.push({initialGain, i});
        }

        // Distribute the extra students
        while (extra > 0) {
            auto [currentGain, idx] = pq.top();
            pq.pop();

            // Update the class by adding one extra student
            classes[idx][0]++;
            classes[idx][1]++;

            // Recalculate the gain for the updated class and push it back
            double newGain = gain(classes[idx][0], classes[idx][1]);
            pq.push({newGain, idx});

            extra--;
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0.0;
        for (const auto& cls : classes) {
            totalPassRatio += (double)cls[0] / cls[1];
        }

        return totalPassRatio / classes.size();
    }
};
