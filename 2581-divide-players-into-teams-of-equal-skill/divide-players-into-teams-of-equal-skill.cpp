class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        if (skill.size()%2 != 0) {
            cout<<'p';
            return -1;
        }

        int i = 0;
       int j = skill.size() - 1;
        long long res=0;

        long long sum = 0;
        long long  cursum = skill[0] + skill[skill.size() - 1];
        while (j > i) {
            sum = skill[i] + skill[j];
            if (sum != cursum) {
                return -1;
            }
            cout<<skill[i]<<skill[j]<<"\n";
            res += skill[i] * skill[j];
            i++;
            j--;
            
        }

        return res;
    }
};