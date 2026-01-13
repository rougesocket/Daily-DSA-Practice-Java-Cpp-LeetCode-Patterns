class Solution {
public:

    double good(double mid,vector<vector<int> > &arr){

        double above=0,below=0;
        for(int i=0;i<arr.size();i++){
            double x = arr[i][0],y=arr[i][1],l=arr[i][2];
            double area = l*l;
            if(y>=mid){
                above+=area;
            }
            else if(y+l<=mid){
                below+=area;
            }
            else{
                double habove = (y+l)-mid;
                double hbelow = mid-y;
                above+=habove*l;
                below+=hbelow*l;
            }
        }
        return above-below;
    }
    double separateSquares(vector<vector<int>>& squares) {
        

        double l = 0,r=2*1e9;

        for(int i=0;i<100;i++){
            double mid = l+(r-l)/2.0;

            double area = good(mid,squares);
            if(area>0)l=mid;
            else r=mid;
        }
        return r;
    }
};