#include<bits/stdc++.h>
using namespace std;

typedef struct position r_data;

struct position{
    int x,y;
} pos;

r_data linearSearch(int data[][5], int value, int n)
{
    pos.x = -1;
    pos.y = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            if(data[i][j] == value){
                pos.x = i;
                pos.y = j;
                return pos;
            }
        }
    }

    return pos;
}

int main()
{
    int data[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
    int searchData = 9;
    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++)
            cout<<data[i][j]<<" ";
        cout<<endl;
    }
    pos = linearSearch(data, searchData, 2);
    cout<<"Search Number is: "<<searchData<<endl;
    if(pos.x != -1)
        cout<<"position: "<<pos.x+1<<" "<<pos.y+1<<endl;
    else
        cout<<"Data not found."<<endl;
    return 0;
}
