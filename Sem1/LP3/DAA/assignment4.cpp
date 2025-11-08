#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int row,int col,vector<string> &board,int n){
    for(int i = 0;i<n;i++){
        if(i!=col && board[row][i] == 'Q'){
            return false;
        }
    }
    for(int i = 0;i<n;i++){
        if(i!=row && board[i][col] == 'Q'){
            return false;
        }
    }

    int r = row - 1;
    int c = col - 1;

    while(r >= 0 && c>=0){
        if(board[r][c] == 'Q'){
            return false;
        }
        r--;
        c--;
    }

    r = row + 1;
    c = col + 1;

    while(r < n && c < n){
        if(board[r][c] == 'Q'){
            return false;
        }

        r++;
        c++;
    }

    r = row + 1;
    c = col - 1;

    while(r < n && c >= 0){
        if(board[r][c] == 'Q'){
            return false;
        }

        r++;
        c--;
    }

    r = row - 1;
    c = col + 1;

    while(r >= 0 && c < n){
        if(board[r][c] == 'Q'){
            return false;
        }

        r--;
        c++;
    }

    return true;
}

void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    bool f = 0;

    for(int r = 0;r<n;r++){
        if(board[r][col] == 'Q'){
            f = 1;
            break;
        }
    }

    if(f == 1){
        solve(col +1,ans,board,n);
        return;
    }

    for(int row = 0;row < n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            solve(col+1,ans,board,n);
            board[row][col] = '.';
        }
    }
}

int main(){
    int n;
    cout<<"Enter n: \n";
    cin>>n;

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0;i<n;i++){
        board[i] = s;
    }

    int r;
    int c;

    cout<<"Enter row: \n";
    cin>>r;

    cout<<"Enter column: \n";
    cin>>c;

    if(!isSafe(r,c,board,n)){
        cout<<"Invalid position\n";
        return 0;
    }

    board[r][c] = 'Q';

    solve(0,ans,board,n);

    if(ans.size() == 0){
        cout<<"No valid combination\n";
        return 0;
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(ans[i][j][k]=='Q'){
                    cout<<"Q"<<" ";
                }
                else{
                    cout<<"_"<<" ";
                }
            }

            cout<<endl;

        }
        cout<<"----------------------------------"<<endl;
    }

    return 0;
}