#include "hashTable.h"
#include <iostream>
using namespace std;

int main(){
    HASHTABLE<int> t(10);
    int x;
    while(1){
        system("cls");
        t.print();
        cout<<"\n\n rep: ";
        cin>>x;
        if(x==1){
            cin>>x;
            t.add(x, 1);
        }else if(x==2){
            cin>>x;
            t._delete(x);
        }
    }
    return 0;
}