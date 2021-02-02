class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix.size()==1)
        {

        }
        else
        {
        int n = matrix.size();
        int temp;
        int row=n/2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<row;j++)
            {
                temp=matrix[j][i];
                matrix[j][i]=matrix[n-1-j][i];
                matrix[n-1-j][i]=temp;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
                
        }
        }
       
    }
};
