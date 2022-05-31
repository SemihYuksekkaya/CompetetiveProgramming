#include <iostream>
#include <string>
#include <vector> 

using namespace std;


int main(){

    int N,K,tmp2;
    vector<int> arr;
    string tmp;
int cnt=0;
int tail=0;
    cin>>N;
    getline(cin,tmp);
    K = stoi(tmp);

    for(int i =0; i<N;i++){
        cin>>tmp2;
        arr.push_back(tmp2);
    }

    vector<vector<int>> lsq(N);


    lsq[0].push_back( arr[0]);
    

    for(int i=1; i<N; i++){
        for(int j=0;j<i;j++){
            
            if( (arr[j] < arr[i]) && (lsq[i].size() <= lsq[j].size())){
                lsq[i]=lsq[j];
            }
            else if((arr[j]==arr[i]) && (lsq[i].size() <= lsq[j].size())){
                tail=lsq[j].size()-1;
                cnt=0;

                while((tail>=0) && (lsq[j][tail] == arr[i])){
                    tail--;
                    cnt++;
                    
                }
                if(cnt<K){
                    lsq[i]=lsq[j];
                }
                else{
                    lsq[i]=lsq[j];
                    lsq[i].pop_back();
                }
            }
        }
        lsq[i].push_back(arr[i]);
    }
int max =0;
for(auto x :lsq){
    if(max< (int) x.size()) max = (int) x.size();
}

cout<<max<<endl;
    return 0;
}

