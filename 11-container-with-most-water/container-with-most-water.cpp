class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right = height.size()-1;

        int area=0, cura=0;

        while(left<right){
          cura = min(height[left], height[right])*(right-left);
           area = max(cura,area);
          if(height[left]<height[right]){
            left++;
          }  
          else{
            right--;
          }
        }
        return area;
    }
};