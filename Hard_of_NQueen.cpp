#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


     void solve(int col,vector<vector<string>> & ans,vector<string> & res,vector<int> & leftRow,vector<int> & lowerDiagonal,vector<int> &upperDiagonal,int n){
        if(col == n) {
            ans.push_back(res);
            return ;

        }
        for(int row =0 ; row<n;row++){
            if(leftRow[row]==0 &&  lowerDiagonal[row + col]==0 && upperDiagonal[n-1 + col -row]==0){
                res[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row]=1;
                upperDiagonal[row]=1;
                solve(col+1,ans,res,leftRow,lowerDiagonal,upperDiagonal,n);
                res[row]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1 + col - row]=0;
                
            }
        }


     }

    vector<vector<string>> nQueen(int n){
        vector<vector<string>> ans;
        vector<string> res(n);
        string s(n,'.');

        for(int row=0;row<n;row++){
            res[row] = s;
        }
        vector<int> leftRow(n,0);
        vector<int> lowerDiagonal(2*n-1,0);
        vector<int> upperDaigonal(2*n-1,0);

        solve(0,ans,res,leftRow,lowerDiagonal,upperDaigonal,n);
        return ans;

    }

};
int main(){

    Solution S;
    int n;
    cin>>n;
    vector<vector<string>> result=S.nQueen(n);
    for(auto row: result){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;

}