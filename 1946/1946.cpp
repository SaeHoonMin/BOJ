#include <iostream>
#include <vector>
#include <algorithm>



typedef struct Applicant
{
    int a;
    int b;
}Applicant_t;

bool isBig(const Applicant & a1,const  Applicant& a2)
{
  return a1.a < a2.a;   
}

using namespace::std;

int main(void)
{
  int T;
  
  cin>>T;
  for(int i = 0 ; i < T ; i++)
  {
    int n;
    cin>>n;
    vector<Applicant> applicants;
    Applicant appli;
    for(int i = 0 ; i< n ; i++)
    {
        cin>>appli.a>>appli.b;
        applicants.push_back(appli);
    }
    
    sort(applicants.begin(), applicants.end(), isBig);

    int ans = 1;
    int recentB = applicants[0].b;
    
    for(int j = 1  ; j < applicants.size(); j++)
    {
        if( recentB > applicants[j].b)
        {
            ans++;
            recentB = applicants[j].b;
        }
    }
    
    
    cout<<ans<<"\n";
  }
    
}