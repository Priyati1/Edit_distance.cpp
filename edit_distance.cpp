#include<iostream>
using namespace std;
int edit_distance(char *s1,char*s2,int i,int j,int dp[100][100]){
	//base case
	if(i==0){//length of s1
		return dp[i][j]=j;
	}
	if(j==0){//length of s2
		return dp[i][j]=i;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	//recursive case
	if(s1[i-1]==s2[j-1]){
		return dp[i][j]=edit_distance(s1,s2,i-1,j-1,dp);
	}
	else{
		int opt1=1+edit_distance(s1,s2,i-1,j-1,dp);
		int opt2=1+edit_distance(s1,s2,i,j-1,dp);
		int opt3=1+edit_distance(s1,s2,i-1,j,dp);
		return dp[i][j]=min(opt1,min(opt2,opt3));
	}
}
int main(){
	char s1[100],s2[100];
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	cin>>s1>>s2;
	int i=strlen(s1);
	int j=strlen(s2);
	cout<<edit_distance(s1,s2,i,j,dp)<<endl;
	return 0;
}