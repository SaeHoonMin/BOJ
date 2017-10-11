#include <iostream>
#include <string>
using namespace::std;
using std::string;


int main()
{
	int arr[26]={0};
	string S;
	cin>>S;

	int max=0;
	int maxindex;

	for(int i=0; i<S.length();i++)
	{
		if(S[i] >= 65 && S[i] <= 90)
			S[i] = S[i] + 32;
		arr[S[i]-97]++;
		if(arr[S[i]-97]>max)
		{
			max=arr[S[i]-97];
			maxindex = S[i]-97;
		}
	}
	for(int i=0; i<26;i++)
	{
		if(arr[i]==max && i!=maxindex)
		{
			cout<<"?";
			return 0;
		}
	}
	cout<<(char)(maxindex+97-32);

}