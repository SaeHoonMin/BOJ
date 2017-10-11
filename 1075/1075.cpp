#include <iostream>
using namespace::std;int i,n,f;int main(void){cin>>n>>f;n=n-n%100;while(1){if((n + i++)%f==0)break;}if (--i<10)cout<<"0";cout <<i;}