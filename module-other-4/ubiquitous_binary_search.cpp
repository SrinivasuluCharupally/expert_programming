// ubiquitous binary search

// source : https://www.geeksforgeeks.org/the-ubiquitous-binary-search-set-1/

int Floor(int A[], int l, int r, int key)
{
    int m;
 
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
 
    return A[l];
}
 
// Initial call
int Floor(int A[], int size, int key)
{
    // Add error checking if key < A[0]
    if( key < A[0] )
        return -1;
 
    // Observe boundaries
    return Floor(A, 0, size, key);
}
