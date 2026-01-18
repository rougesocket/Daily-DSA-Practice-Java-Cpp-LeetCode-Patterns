class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        
        int n = grid.size(),m=grid[0].size();
        int ans = 1;

        vector<vector<int> > prefixrow(n,vector<int> (m,0)),prefixcol(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefixrow[i][j]=((j>=1)?prefixrow[i][j-1]: 0)+grid[i][j];
            }
        }

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                prefixcol[i][j]=((i>=1)?prefixcol[i-1][j]: 0)+grid[i][j];
            }
        }

        
        for(int k=min(m,n);k>=2;k--){

            for(int i=0;i+k<=n;i++){
                for(int j=0;j+k<=m;j++){
                    //rowsum

                    int row = prefixrow[i][j+k-1]-((j>=1)?prefixrow[i][j-1]:0);
                    bool isValid = true;
                    for(int p=i+1;p<i+k;p++){
                        int curr = prefixrow[p][j+k-1]-((j>=1)?prefixrow[p][j-1]:0);
                        if(curr!=row){
                            isValid = false;
                            break;
                        }
                    }
                    if(!isValid)continue;
                    //colsum

                    for(int p=j;p<j+k;p++){
                        int curr = prefixcol[i+k-1][p]-((i>=1)?prefixcol[i-1][p]:0);
                        if(curr!=row){
                            isValid = false;
                            break;
                        }
                    }
                    if(!isValid)continue;

                    //diagonal

                    int d1=0,d2=0;
                    for(int p=0;p<k;p++){
                        d1+=grid[i+p][j+p];
                        d2+=grid[i+p][j+k-p-1];
                    }
                    if(d1==d2 && d1==row)return k;
                }
            }

        }
        return 1;
    }
};