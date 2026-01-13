class Solution {

    public double good(int [][]arr,double mid){

        double above=0,below=0;
        for(int i=0;i<arr.length;i++){
            double x = arr[i][0],y=arr[i][1],l=arr[i][2];
            double area = l*l;
            if(y>=mid)above+=area;
            else if(y+l<=mid)below+=area;
            else{
                double habove = y+l-mid;
                double hbelow = mid-y;
                above+=habove*l;
                below+=hbelow*l;
            }
        }
        return above-below;
    }
    public double separateSquares(int[][] squares) {

        double l=0,r=2e9+1;
        for(int i=0;i<100;i++){
            double mid = l+(r-l)/2.0;
            double diff = good(squares,mid);
            
            if(diff>0)l=mid;
            else r=mid;
        }   
        return r;    
    }
}