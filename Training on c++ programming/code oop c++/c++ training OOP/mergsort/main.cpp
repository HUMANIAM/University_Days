
#include<iostream>
using namespace std;

#define MAX 4
void sortarr(int arr[],int in,int m,int f)
{
cout<<" intail ="<<in<<"        mid = "<<m<<"     final =  "<<f<<endl;
//get the legnth of every array
int n1,n2;
n1=m-in+1;
n2=f-m;
//create two arrays to hold the subarrays
int Left[n1],Right[n2];
for(int i=0;i<n1;i++)
Left[i]=arr[in+i];
//copy the second array into the right array
for(int i=0;i<n2;i++)
Right[i]=arr[m+1+i];

//start know to compare the two arrays
int k,i,j;
k=in;
i=j=0;
while(i<n1 && j<n2)
{
if(Left[i]>=Right[j])
arr[k++]=Left[i++];
else
arr[k++]=Right[j++];
}

//put the rest of arrs as them
while(j<n2)
{arr[k++]=Right[j++];}
while(i<n1)
{arr[k++]=Left[i++];}

cout<<"In this array I have sorted subarray"<<endl;

for(int i=in;i<f+1;i++)
cout<<arr[i]<<"    ";
cout<<endl;
}
//this is the shared object
void mergesort(int arr[],int i, int f)
{
if(i<f)
{
int m=i+(f-i)/2;
mergesort(arr,i,m);
mergesort(arr,m+1,f);
sortarr(arr,i,m,f);
}
}

//sort this subarrays

void printarr(int arr[])
{
for(int i=0;i<MAX;i++)
cout<<arr[i]<<"    "<<endl;
cout<<endl;
}
//the main function
int main()
{

int arr[MAX];
for(int i=0;i<MAX;i++)
arr[i]=i;

cout<<"Before sorting"<<endl;
printarr(arr);
mergesort(arr,0,MAX-1);
cout<<"After sorting"<<endl;
printarr(arr);
return 0;
}
