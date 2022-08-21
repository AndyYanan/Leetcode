class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxContain = INT_MIN, h = 0;
        int front = 0, back = height.size()-1;
        while(front < back){
            h = min(height[front], height[back]);
            maxContain = max(maxContain, h*(back-front));
            if(height[front]>height[back]){
                back--;
            }else{
                front++;
            }
        }
        return maxContain;
    }
};