#include <stdio.h>

void merge(int* a,int start,int end,int n)
{
    int mid=(start+end)/2;
    int i=start,j=mid+1,k=start;
    int temp[n];

    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        temp[k++]=a[i++];
        
        else
        temp[k++]=a[j++];      
    }

    while(i<=mid)
    temp[k++]=a[i++];
    
    while(j<=end)
    temp[k++]=a[j++];
    

    for(i=start;i<=end;i++)
    a[i]=temp[i];
}

void mergesort(int* a,int start,int end,int n)
{
    if(start>=end)
    return;

    int mid=(start+end)/2;

    mergesort(a,start,mid,n);
    mergesort(a,mid+1,end,n);

    merge(a,start,end,n);
}


int main() 
{
    int size;
    scanf("%d",&size);
    int a[size];
    
    for(int i=0;i<size;i++)
    scanf("%d",&a[i]);

    mergesort(a,0,size-1,size);

    for(int i=0;i<size;i++)
    printf("%d ",a[i]);
    
}