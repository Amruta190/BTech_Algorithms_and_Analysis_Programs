#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Insertion_Sort(int[],int);
int main()
{
    int n,*a,i,k;
    clock_t st,et;
    double total_time; 
    //system("cls");
    printf("Enter the size of array:")   ;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("Sufficient space could not be allocated!");
        return 0;
    }
    printf("Choose one of the options\n");
    printf("1.Best case\n2.Average case\n3.Worst case\n");
    scanf("%d",&k);
    switch (k)
    {
    case 1:
        for (i = 0; i < n; i++) 
        {
            a[i] = i + 1;
        }
        break;
    case 2:
        srand(time(0));
        for(i = 0; i<n; i++)
        {
            //a[i] = rand();
            a[i] = rand() % n + 1;
        }
        break;    
    case 3:
        for (i = 0; i <n; i++) 
        {
            a[i] = n-i ;
        }
        break;
    
    default:printf("Enter either 1 or 2 !");
        break;
    }
    printf("\nElements before sorting:\n");
    //for(i=0;i<n;i++)
        //printf("%d\t",a[i]);
    st=clock();
    Insertion_Sort(a,n);
    et=clock();
    total_time = (double)(et-st)/CLOCKS_PER_SEC;     
    printf("\nElements after sorting:\n");
    //for(i=0;i<n;i++)
        //printf("%d\t",a[i]);
    printf("\nThe time taken is %lf",total_time);     
    return 0;    
}
int Insertion_Sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
	    	// Insert a[i] into the sorted part of the array, i.e., a [1: i-1]
	    	int j=i-1;		
		while(j>=0 && a[j]>key)    
		{
			a[j+1]=a[j];  // move a[j] to its next position  in the right side
			j--;            
		}
		a[j+1]=key;
    }    
        
}