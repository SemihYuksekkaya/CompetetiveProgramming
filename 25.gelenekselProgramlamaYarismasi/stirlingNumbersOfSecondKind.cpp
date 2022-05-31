#include <iostream>
#include <string>
#include <vector> 
#include <cmath>

using namespace std;

long long comb(int n , int r);
long long fact(int n);
long long sigm(int n,int k);
const int md =1000000007; 
int main(){
    int N;
    cin>>N;

    long long * res= new long long[N];

    for(int i =1;i<=N;i++){
        res[i-1]= (sigm(N,i)/fact(i)) % md ;
    }


    for(int i=0;i<N-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<res[N-1]<<endl;
    
    cout<< "fact 11 "<<fact(11)<<endl;

    delete [] res;
    return 0;
}


long long comb(int n , int r){
    return (fact(n)/ ((fact(r)*fact(n-r))  )) %  md; //% md)   %  md;    

}

long long fact(int n){
    long long res=1;
    for(int i =2;i<=n;i++){
        res=(res*i)% md;
    }
    return res % md; 
}
long long sigm(int n,int k){
    long long  res=0;
    for(int i=0;i<=k;i++){
        res= (res + (  ( ((long long) pow(-1,i) * comb(k,i)) % md  )  * (  ((long long) pow(k-i,n))%md ) )   % md ) % md;
    }
    return res % md;
}