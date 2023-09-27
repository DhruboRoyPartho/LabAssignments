#include<iostream>
using namespace std;

int main()
{
    int n,x,mn,mx;
    cout<<"How many number do you want to enter: ";
    cin>>n;
    int data[n+1];
    cin>>x;
    mn = mx = x;
    data[0] = x;
    for(int i=1;i<n;i++){
        cin>>x;
        if(x < mn) mn = x;
        if(x > mx) mx = x;
        data[i] = x + data[i-1];
    }
    cout<<"What do you need:\n\t1.SUM\n\t2.AVERAGE\n\t3.BOTH"<<endl;
    int selector;
    cin>>selector;
    switch(selector){
    case 1:
        cout<<"SUM is: "<<data[n-1]<<endl;
        break;
    case 2:
        cout<<"AVERAGE is: "<<(float)(data[n-1]/(float)n)<<endl;
        break;
    case 3:
        cout<<"SUM is: "<<data[n-1]<<endl;
        cout<<"AVERAGE is: "<<(float)data[n-1]/(float)n<<endl;
        break;
    default:
        cout<<"You have choose a wrong selector"<<endl;
    }
    return 0;
}
