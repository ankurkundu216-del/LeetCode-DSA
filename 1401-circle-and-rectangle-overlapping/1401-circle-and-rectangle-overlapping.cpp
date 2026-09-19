class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int near_x = max(x1,min(xCenter,x2));
        int near_y = max(y1,min(yCenter,y2));
        int dist_x = near_x - xCenter;
        int dist_y = near_y - yCenter;
        int sq_dist = (dist_x*dist_x)+(dist_y*dist_y);
        return sq_dist <= radius*radius;
    }
};