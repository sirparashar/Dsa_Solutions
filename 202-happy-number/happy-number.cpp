#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            int sumOfSquares = 0;
            
            while (n > 0) {
                int digit = n % 10;
                sumOfSquares += digit * digit;
                n /= 10;
            }
            
            n = sumOfSquares;
        }

        return n == 1;
    }
};
