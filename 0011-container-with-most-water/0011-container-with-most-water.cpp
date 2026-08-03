class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max_area=0;
        int curr_area=0;
        while(left<right) {

            // Curr area calculate karo
            curr_area=(right-left)*min(height[left],height[right]);
            max_area = max(max_area,curr_area);
            // Shorter side ko skip karo jab taak baadi height naa mile
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_area;
    }
};