#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int testcase, dimension, statements;
    int x, y, z, w, x1, y1, z1;
    string query;
    
    cin>>testcase;
    
    while(testcase>0){

        cin>>dimension>>statements;
        map<string, int> cells;
    
        while(statements>0){
            long int sum=0;
        
            cin>>query;
            
            if(query=="UPDATE"){
                string key;
                cin>>x>>y>>z>>w;
                
                key= to_string(x)+to_string(y)+to_string(z);

                if(!cells.insert(pair<string, int>(key, w)).second){
                    cells.at(key)=w;
                }
            }  
            
            else if(query=="QUERY"){
            
                cin>>x>>y>>z>>x1>>y1>>z1; //z is the deminsion
                //if z<=111 444
                string beginKey, endKey;
            
                beginKey=to_string(x)+to_string(y)+to_string(z);
                endKey=to_string(x1)+to_string(y1)+to_string(z1);
                            
                if(cells.count(beginKey)==0){
                   cells.insert(pair<string, int>(beginKey, 0));
                }
            
                if(cells.count(endKey)==0){
                    cells.insert(pair<string, int>(endKey, 0));
                }
                              
                for(auto it =cells.find(beginKey); it!=cells.end(); ++it){
                    int value=stoi(it->first);
                    int first=(value/100)%10, second=(value/10)%10, third=value%10; 
                    
                    if(first>=x&&second>=y&&third>=z&&first<=x1&&second<=y1&&third<=z1){
                      sum+=it->second;
                    }
                                                        
                    if(it==cells.find(endKey))
                       break;

                               
                }
                cin.clear();
                cout<<sum<<endl;
            }
        
            statements--;
        }
        testcase--;   
    }

    return 0;
}
