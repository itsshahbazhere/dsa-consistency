#include<iostream>
using namespace std;

void sayDigit(int n,string arr[]){
    if(n==0){
        return;
    }
    int lastDigit = n%10;
    n = n/10;
    sayDigit(n,arr);
    cout<<arr[lastDigit]<<" ";

}
int main(){

    int num;
    cout<<"Enter number: ";
    cin>>num;
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    sayDigit(num,arr);


    return 0;
}