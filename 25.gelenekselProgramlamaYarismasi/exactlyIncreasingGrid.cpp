#include <iostream>
#include <string>
#include <vector> 
#include <utility>
#include <bits/stdc++.h>
using namespace std;


int main(){

	int N,M;
	string tmp;
	int tmp2;
	cin>>N;
	getline(cin,tmp);
	M = stoi(tmp);

vector<int> lst;

	for(int i = 0;i<N;i++){

		for(int j=0;j<M-1;j++){
			cin>>tmp2;
            lst.push_back(tmp2-(i+j));
		}
		getline(cin,tmp);
		tmp2=stoi(tmp);
        lst.push_back(tmp2-(i+M-1));
	}

    sort(lst.begin(), lst.end());

int max=0, cur=0;
    for(int i=1;i<(int) lst.size();i++){
        
        if(lst[i]==lst[i-1]){
            cur++;
            if(max<cur){
                max=cur;

            } 
        } 
        else   cur=1;
    }

cout<<(N*M-max)<<endl;
    return 0;
}