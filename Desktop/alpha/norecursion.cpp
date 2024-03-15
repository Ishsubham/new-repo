#include<iostream>
using namespace std;
long long int factorial(int n){
    if(n==0 or n==1)
    return 1;
    else
    return n * factorial(n-1);
}

int main(){
int n;
cin>>n;
long long int factorial(n);
cout<< factorial;
return 0;
}
