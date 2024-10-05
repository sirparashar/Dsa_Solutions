class Solution {
public:
    bool allzero(vector<int> count) {
        for (int n : count) {
            if (n != 0) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n2 < n1) {
            return false;
        }

        vector<int> count(26, 0);

        for (int i = 0; i < n1; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        if (allzero(count)) {
            return true;
        }

        for (int i = n1; i < n2; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - n1] - 'a']++;

            if (allzero(count)) {
                return true;
            }
        }
        return false;
    }
};