class Solution {
public:
    int minSwaps(string s) {

        int n = s.size();
        int b = 0, swp = 0;
        int end = n - 1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                b++;
            } else {
                b--;
            }
            if (b < 0) {
                while (i < end && s[end] != '[') {
                    end--;
                }
                swap(s[i],s[end]);
                swp++;
                b=1;
            }
        }
        return swp;
    }
};