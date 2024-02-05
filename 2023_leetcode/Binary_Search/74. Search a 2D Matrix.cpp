
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLen = matrix.size(),
        	colLen = matrix[0].size();
        int left = 0, right = rowLen * colLen - 1;
        while(right >= left){
        	int mid = left + (right - left) / 2;
        	if(matrix[mid/colLen][mid%colLen] < target){
        		left = mid + 1;
        	}else if (matrix[mid/colLen][mid%colLen] > target){
        		right = mid - 1;
        	}else{
        		return true;
        	}
        }	
        return false;
    }
};