class Solution {
public:
    bool checkOverlap(int r, int xc, int yc,
                      int x1, int y1, int x2, int y2) {

        int dx = max(x1, min(xc, x2));
        int dy = max(y1, min(yc, y2));

        int distX = xc - dx;
        int distY = yc - dy;

        return distX * distX + distY * distY <= r * r;
    }
};