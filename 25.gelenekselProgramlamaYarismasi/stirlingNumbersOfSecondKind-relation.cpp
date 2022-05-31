#include <iostream>
#include <string>
#include <vector> 
#include <cmath>
#include <utility>

using namespace std;
 
long long stirlingNum(int a,int k,pair<long long,bool>** table );


const int md =1000000007; 

int main(){

    int N;
    cin>>N;
    pair<long long ,bool>**table = new pair<long long,bool>*[N+1];
    for(int i =0;i<=N;i++){
        table[i]=new pair<long long,bool>[N+1];
        for(int j=0; j<=N ;j++){
            table[i][j].first=0;
            table[i][j].second=false;
        }
    }

    vector<long long> res;
    for(int i=1;i<N;i++){
        
         cout<<stirlingNum(N,i,table)%md<<" ";

    }
    cout<<"1"<<endl;
    for(int i=1;i<N;i++){
        
        delete [] table[i];
    }
    return 0;
}




long long stirlingNum(int a,int k ,pair<long long,bool>** table){
    
    if(a==0 && k==0) {
        table[a][k].first= 1;
        table[a][k].second=true;
        }
    else if (a==0) {
        table[a][k].first= 0;
        table[a][k].second=true;
        }
    else if (k==0) {
        table[a][k].first= 0;
        table[a][k].second=true;
        }
    else{

        if(table[a-1][k].second==false){
            stirlingNum(a-1,k,table);
        }
        if(table[a-1][k-1].second==false){
            stirlingNum(a-1,k-1,table);
        }

        table[a][k].first= (((k * table[a-1][k].first) % md ) + table[a-1][k-1].first) % md;
        table[a][k].second=true;
            
    }
    
    return table[a][k].first;

}