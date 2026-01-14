class Solution {
public:
    double findArea(double mid, vector<vector<int>> & squares){
        double area=0;
        for(auto &it : squares){
            int y = it[1];
            int l = it[2];
            if(y >= mid){
                continue;
            }else if(y+l <= mid){
                area +=1LL*l*l;
            }else{
                //partial
                double h = mid - y;
                area += (h * l);
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        long long totalArea = 0;
        double minY = INT_MAX, maxY=INT_MIN;
        for(auto &it : squares){
            minY = min((int)minY , it[1]);
            maxY = max((int)maxY , it[1]+it[2]);
            totalArea += 1LL*it[2]*it[2];
        }
        double half = totalArea / 2.0;
        for(int iter = 0; iter < 80; iter++){
            double mid = minY + (maxY - minY)/2.0;
            double areaBelow = findArea(mid, squares);
            if (areaBelow >= half) maxY = mid;
            else minY = mid;
        }
        return maxY;
    }
};