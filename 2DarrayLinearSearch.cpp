//Author: Dhrubo Roy Partho
//Date: 27-09-2023

//Here the program is for static data. you can make it dynamic by taking size and data from user. Do it yourself.
//It is for 2x5 order matrix 2D array

#include<bits/stdc++.h>
using namespace std;

//Customizing struct data type name. here i am replacing struct position ----> r_data
typedef struct position r_data;

//taking struct variable for store position. We cannot return 2 or more values generally in return statement.
struct position{
    int x,y;
} pos;


//Function for Linear Search
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
    int searchData = 7;    // here you can change search data for check
    for(int i=0;i<2;i++){      //Loop for display 2D array
        for(int j=0;j<5;j++)
            cout<<data[i][j]<<" ";
        cout<<endl;
    }
    pos = linearSearch(data, searchData, 2);
    if(pos.x != -1)
        cout<<"position: "<<pos.x+1<<" "<<pos.y+1<<endl;   //Here I counted first data position is row = 1, col = 1
    else
        cout<<"Data not found."<<endl;
    return 0;
}
