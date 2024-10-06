class Solution {
public:
    vector<string> split(string& s) {
        vector<string> res;
        string m = "";
        for (char ch : s) {
            if (ch == ' ') {
                // cout<<m;
                if (!m.empty()) {
                    res.push_back(m);
                    m = "";
                }
            } else {
                m += ch;
            }
        }
        if (!m.empty()) {
            res.push_back(m);
//m = "";
        }
        return res;
    }
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> w1 = split(s1);
        for (auto m : w1) {
            cout << m;
        }
        cout << "\n";
        vector<string> w2 = split(s2);
        for (auto m : w2) {
            cout << m;
        }

        if (w1.size() < w2.size()) {
            swap(w1, w2);
        }

        int s = 0;
        int e = 0;
        int n1 = w1.size();
        int n2 = w2.size();

        while (s < n2 && w1[s] == w2[s]) {
            s++;
        }

        while (e < n2 && w1[n1 - e - 1] == w2[n2 - e - 1]) {
            e++;
        }

        return s + e >= n2;
    }
};