class Solution {
public:
    
    bool consecutive(vector<int>&hand,int size, int i, int n){
        int next = hand[i]+1;
        hand[i]=-1;
        int count = 1;
        i+=1;
        while(i<n && count<size){
            if(hand[i]==next){
                next = hand[i]+1;
                hand[i]=-1;
                count++;
            }
            i++;
        }
        return count==size;
    }
    
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(hand.size()%groupSize!=0){
            return false;
        }
         
         sort(hand.begin(), hand.end());

         for(int i =0; i<n; i++){
            if(hand[i]>=0){
                if(!consecutive(hand,groupSize,i,n)){
                    return false;
                }
            }
         }

         return true;


    }
};