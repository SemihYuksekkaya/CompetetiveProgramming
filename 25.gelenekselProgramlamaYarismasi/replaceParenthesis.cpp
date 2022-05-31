#include <iostream>
#include <string>
using namespace std;

int main(){
    int len;
    string str;
    string tmp;
    getline(cin,tmp);
    getline(cin,str);
    len = stoi(tmp); 
    int parCount=0;
    int i = 0;
    string res;
    while(i <len){
        if(str[i]=='('){
            parCount++;
            i++;
            while(parCount!=0){
                if(str[i]=='('){
                    parCount++;
                }
                else if(str[i]==')'){
                    parCount--;
                }
                i++;
            }
            res.append("...");
        }
        else{
            res.append(1,str[i]);
            i++;
        }


    }

cout<<res<<endl;

}