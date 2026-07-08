class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int oldimage = image[sr][sc];
        int ssr = image.size();
        int ssc = image[0].size();
        queue<pair<int,int>> q;
        image[sr][sc] = color;

        q.push({sr,sc});
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto &it:dir)
            {
                int nr = r + it[0];
                int nc = c + it[1];
                if(nr>=0  && nc>=0 && nr<ssr && nc<ssc && image[nr][nc] == oldimage)
                {
                    q.push({nr,nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};