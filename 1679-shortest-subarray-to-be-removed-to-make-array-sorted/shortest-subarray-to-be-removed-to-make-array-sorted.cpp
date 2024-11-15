class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left =0;
        int n = arr.size();

        while(left<n-1 && arr[left]<=arr[left+1]){
            left++;
        }
        if(left==n-1){
            return 0;
        }

        int right = n-1;
        while(right>0 && arr[right]>=arr[right-1]){
            right--;
        }

        int res = min(n-left-1,right);

        int i =0; int j=right;

        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                res = min(res,j-i-1);
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};