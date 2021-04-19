#include<iostream>
using namespace std;
int main(){
    int arr[41]={0,1,1};
    for(int i=3;i<41;i++)   
        arr[i]=arr[i-1]+arr[i-2];
    int a;
    cin>>a;
 
    for(int i=0;i<a;i++){
        int num;
        cin>>num;
        if(num==0)  cout<<"1 0\n";
        else if(num==1) cout<<"0 1\n";
        else cout<<arr[num-1]<<" "<<arr[num]<<'\n';
    }
}