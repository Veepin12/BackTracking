//
//  N_Queen.cpp
//  DSA_with_Cpp
//
//  Created by Veepin_Chaudhary on 28/03/26.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    
   
    
    void slice(int col,vector<string> & board,vector<vector<string>> & ans,vector<int> & leftrow,vector<int> & lowerdiagonal,vector<int> &upperdiagonal,int N){
        if(col==N){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<N;row++){
            if(leftrow[row]==0 && lowerdiagonal[row + col] == 0 && upperdiagonal[N-1 + col -row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerdiagonal[row + col]=1;
                upperdiagonal[N-1 + col - row]=1;

                slice(col+1,board,ans,leftrow,lowerdiagonal,upperdiagonal,N);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiagonal[row + col]=0;
                upperdiagonal[N-1 + col - row]=0;

            }
            
        }
        
    }
    
    vector<vector<string>> Que(int N) {
        vector<vector<string>> ans;
        vector<string> board(N);
        string s(N,'.');
        for(int i=0;i<N;i++){
            board[i]=s;
        }
        vector<int> leftrow(N,0);
        vector<int> lowerdiagonal(2*N-1,0);
        vector<int> upperdiagonal(2*N-1,0);
        
        slice(0,board,ans,leftrow,lowerdiagonal,upperdiagonal,N);
        return ans;
    }
    
};

int main(){
    Solution S;
    int N;
    cin>>N;
    vector<vector<string>> Queen=S.Que(N);
    for(auto row : Queen){
        for(auto ele : row){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
    
}


