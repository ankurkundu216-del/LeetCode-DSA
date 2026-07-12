class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double max_area = 0.0;
        
        // Brute force all combinations of triplets (i, j, k)
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];
                    
                    // Shoelace formula for area
                    double current_area = 0.5 * std::abs(
                        x1 * (y2 - y3) + 
                        x2 * (y3 - y1) + 
                        x3 * (y1 - y2)
                    );
                    
                    max_area = std::max(max_area, current_area);
                }
            }
        }
        
        return max_area;
    }
};