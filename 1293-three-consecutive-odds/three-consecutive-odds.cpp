class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
      int i =0;
      while(i<=arr.size()-3){
        if(arr[i]%2!=0){
            int count = 1;
            while(count<3){
               if(arr[i+count]%2==0){
                break;
               }
               count++;
            }
            cout<<count;
            if(count==3){
                return true;
            }
        }
        i++;
      }
      return false;

    }
};