#include <cstdio>
int main(){int s=9e+6,b=-s,a,n;scanf("%d",&n);while(n--){scanf("%d",&a);b=a>b?a:b;s=a<s?a:s;}printf("%d %d",s,b);}