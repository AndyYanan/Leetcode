class Solution {
public:
    void dfs(vector<vector<int>> &image, int r, int c, int color, int tarColer){
        if((r < 0) || (c < 0) || (r >= image.size()) || (c >= image[0].size()) || (image[r][c] == color) || (image[r][c] != tarColer)){ 
            return;
        }
        image[r][c] = color;
        dfs(image, r-1, c, color, tarColer);
        dfs(image, r+1, c, color, tarColer);
        dfs(image, r, c-1, color, tarColer);
        dfs(image, r, c+1, color, tarColer);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int tarColer = image[sr][sc];
        dfs(image, sr, sc, color, tarColer);
        return image;
    }
};