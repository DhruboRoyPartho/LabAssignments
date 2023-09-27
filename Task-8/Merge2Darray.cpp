#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cout<<"Enter 2D array row or column(square matrix): ";
    cin>>a;
    b = c = d = a;
    int mat1[a][b],mat2[c][d];
    cout<<"Enter 1st matrix data:"<<"("<<a<<"x"<<b<<")"<<endl;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>mat1[i][j];
        }
    }
    cout<<"Enter 2nd matrix data:"<<"("<<a<<"x"<<b<<")"<<endl;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>mat2[i][j];
        }
    }
    int row = max(a, c);
    int col = b+d;
    int mergeData[row][col]={0};
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            mergeData[i][j] = mat1[i][j];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++){
            mergeData[i][j+b] = mat2[i][j];
        }
    }
    cout<<"Merge data: ("<<row<<"x"<<col<<")"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<mergeData[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
