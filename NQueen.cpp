
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:



    bool issafe(int row,int col,vector<string> & board,int n){
        int duprow=row;
        int dupcol=col;

        while(row >= 0 && col >=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;

        }
        row=duprow;
        col= dupcol;

        while(col >= 0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=duprow;
        col= dupcol;

        while(row < n && col >= 0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;

        }
        return true;

    }
    void slice(int col,vector<vector<string>> & ans,vector<string> & board,int n){
        if(col==n) {
            ans.push_back(board);
            return;
        } 
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n))  {
                board[row][col]='Q';
                slice(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> nQueen(int n){
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        for(int i=0;i<n;i++){
        board[i]=s;
        }
        slice(0,ans,board,n);
        return ans;
    }
};
int main(){
    Solution S;

    int n;
    cin>>n;
    vector<vector<string>> res=S.nQueen(n);

    for(auto row : res){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;

}