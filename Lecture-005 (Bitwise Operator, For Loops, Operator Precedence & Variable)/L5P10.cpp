#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter any poitive number:";
    cin>>n;

    bool isPrime=1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            // cout<<"Not Prime!";
            isPrime=0;
            break;
        }

    }

    if(isPrime==true){
        cout<<"Yes it's Prime number."<<endl;
    }
    else{
        cout<<"Not a Prime number."<<endl;
    }

    



    return 0;
}