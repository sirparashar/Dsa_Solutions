class Solution {
public:
    int minOperations(vector<string>& logs) {
        int op = 0;
        for (auto str : logs) {
            if (str == "../") {
                op--;
                if(op<0){
                    op=0;
                }
            } else if (str == "./") {
                continue;
            } else {
                op++;
            }
        }
        return op ;
    }
};