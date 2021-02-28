#include<bits/stdc++.h>
using namespace std;
// Gop a[l,...,m] va a[m+1,...,h]
long long Merge(long long a[],long long n,long long l,long long m,long long r)
{
	long long i,j,k,dem = 0;
	long long n1 = m-l+1;
	long long n2 = r -m; // ( r-(m+1)+1)
	// Tao mang tam
	long long L[n1],R[n2];
	// copy du lieu vao mang tam
	for(long long i = 0 ; i < n1 ; i++)
		L[i] = a[l+i];
	for(long long j = 0 ; j < n2 ; j++)
		R[j] = a[m+1+j];
	// gop 2 mang tam vua roi vao mang a
	i = 0; // vi tri mang con dau tien
	j = 0; // vi tri mang con thu hai
	k = l; // chi so cua mang a
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j]) a[k++] = L[i++];
		else {a[k++] = R[j++];dem++;}
	}
	// Copy cac phan tu con lai cua mang L vao a (neu co)
	while(i < n1) a[k++] = L[i++];
	// Copy cac phan tu con lai cua mang R vao a ( neu co)
	while(j < n2) a[k++] = R[j++];dem++;
}

long long Merge_sort(long long a[],long long n,long long l,long long r)
{
	long long dem = 0;
	if(l < r)
	{
		long long m = (l+r)/2;
		dem += Merge_sort(a,n,l,m);
		dem += Merge_sort(a,n,m+1,r);
		dem += Merge(a,n,l,m,r);
	}
	return dem;
}

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		cout<<Merge_sort(a,n,0,n-1)<<endl;	
	}
}
