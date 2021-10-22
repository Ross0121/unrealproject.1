#include <stdio.h>
int checkSorted(int *X, int sX); // declaring the function
void combine(int *X, int *Y, int sX, int sY); // declaring the function

int main()
{
    int m,n; // declaring the variables for size of array A and B
    printf("Enter the size of 1st array :\n");
    scanf("%d",&m);
    printf("Enter the size of 2nd array :\n");
    scanf("%d",&n);
    int A[m],B[n]; // declaring the arrays A and B
    printf("Enter the elements of array A :\n");
    for(int i=0; i<m; i++)
    {
        scanf("%d",&A[i]); // inputing the array A elements from user
    }
    printf("Enter the elements of array B :\n");
    for(int j=0; j<n; j++)
    {
        scanf("%d",&B[j]);  // inputing the array B elements from user
    }
    if(checkSorted(A,m) && checkSorted(B,n)) // checking if both araays are sorted in increasing order
    {
        printf("The sorted array is : \n");
       combine(A,B,m,n); // calling combine function to add both arrays 
    }
    else if(checkSorted(A,m) && !checkSorted(B,n)) // checking if array B is not sorted and array A is sorted and printing the error 
    {
        printf("Input array B is not sorted in increasing order.\n");
    }
    else if(!checkSorted(A,m) && checkSorted(B,n))  // checking if array A is not sorted and array B is sorted and printing the error
    {
        printf("Input array A is not sorted in increasing order.\n");
    }
    else  // when both the arrays A and B are not sorted
    {
        printf("Input array A and B both are not sorted in increasing order.\n");
    }
}

int checkSorted(int *X, int sX) // functions to check arrays are sorted or no
{
    int count = 0;
    for(int i=0;i<sX-1;i++) // loop for checking iff the elements of the array are in strictly increasing order
	{
		if(X[i]<X[i+1])
		{
			count++; // incrementing count by 1 if it is strictly increasing
		}
	}
	if( sX-1 == count) // if count is same as (number of elements - 1) returning 1 else 0 
	{
	   
		return 1;
	}
    else if(sX == 0) // if number of elements in the array is 0 then also return 1
    {
        return 1;
    }
	else
	{
		return 0;
	}
}
void combine(int *X, int *Y, int sX, int sY)// function to combine the two arrays into a single sorted array
{
    int a[sX+sY];// declaring a array of length equal sum of lengths of the two arrays that are to be stored 
    int f=0,g=0,c=0;// defining variable f to keep track of values in first array X, defining variable g to keep track of values in second array Y, defining c variable for counting the number of values inserted in combined array as there might be somevalues same in the array 
    for(int i = 0; (f<sX||g<sY) ; i++)// loop to combine the two sorted arrays into an single sorted array
    {
        if((X[f] < Y[g])&&(f<sX)&&(g<sY))// checking if element at corresponding position in X less than element in Y if yes then increase the value of f so that f corresponding element in X can be checked against g element in Y and also checking if both of the arrays elements are not yet inserted
            {
                a[i]=X[f];// storing the value of least in a[i] as we want a sorted array in ascending order
                f=f+1;// increasing the index for X array as it has been stored
                c=c+1;// increasing the count of elements that have been stored
            }
            else if((X[f] == Y[g])&&(f<sX)&&(g<sY))// checking if element at corresponding position in X is equal to element in Y if yes then increase the value of f and g both so that next check should occur on both of the arrays current+1 index and also checking if both of the arrays elements are not yet inserted
            {
                a[i]=X[f];// storing the value from any of the arrays as both are same
                f=f+1;// increasing f index by 1
                g=g+1;// also increasing g index byy 1 as both elements at this index are same
                c=c+1;// increasing the count of elements that have been stored 
            }
            else if((X[f] > Y[g])&&(f<sX)&&(g<sY))// checking if array2 has the smaller element than array 1 at the indexes being compared and also checking if both of the arrays elements are not yet inserted
            {
                a[i]=Y[g];//// inserting the uninserted array2's elements into combined array as array2 has smaller element than array1 at corresponding position
                g=g+1;   //increasing the index as this index element has been inserted 
                c=c+1;  // increasing the count of elements that have been stored
            }
            else{        // This else will execute when either one array's all elements or both of the array's all elements have been inserted
                if(g<sY)// checking if the array 2's all elements have already been inserted or not if not then execute this  
                {
                a[i]=Y[g];// inserting the uninserted array2's elements into combined array
                g=g+1;//increasing the index as this index element has been inserted 
                c=c+1;// increasing the count of elements that have been stored
                }
                if(f<sX)// checking if the array 1's all elements have already been inserted or not if not then execute this  
                {
                a[i]=X[f];// inserting the uninserted array1's elements into combined array
                f=f+1;//increasing the index as this index element has been inserted 
                c=c+1;// increasing the count of elements that have been stored
                }
            }
            
    }
    for(int i = 0; i < c; i++)// loop for printing the final combined array
    {
        printf("%d  ",a[i]);// printing the final combined sorted array
    }
    
}
