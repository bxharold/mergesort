// mergesort, adapted from pseudocode:
//     https://en.wikipedia.org/wiki/Merge_sort#Top-down_implementation

#include <stdio.h>
const int gsz = 10;
int ga[] = {9,1,4,7,3,8,2,0,5,6};
int gb[10];

void arrayCopy(int a[], int b[], int sz);
void arrayPrint(int a[], int sz);
void MergeSort(int A[], int B[], int n);
void splitMerge(int B[], int lft, int rt, int A[]);
void merge(int A[], int lft, int midpt, int rt, int B[]);

//  A[] is the array to be sorted. B[] is the intermediate array.
void MergeSort(int A[], int B[], int sz)     // sz is the global gsz
{
    arrayCopy(A, B, sz);
    splitMerge(B, 0, sz, A);   // sort data from B[] into A[]
}

// Split A[] into A[ lft .. midpt-1 ], A[ midpt.. rt-1 ].
//   splitMerge() both parts into B[]. merge from B[] to A[]
void splitMerge(int B[], int lft, int rt, int A[])
{
    if (lft == rt || (lft + 1 == rt))
        return;
    int midpt = (rt + lft) / 2;
    splitMerge(A, lft,  midpt, B);
    splitMerge(A, midpt,   rt, B);
    merge(B, lft, midpt, rt, A);
}

//  Left source half is A[ lft:midpt-1].
//  Right source half is A[midpt:rt-1   ].
//  Result is            B[ lft:rt-1   ].
void merge(int A[], int lft, int midpt, int rt, int B[])
{
    int i = lft; int j = midpt;

    for (int k = lft; k < rt; k++) {
        if (i < midpt && (j >= rt || A[i] <= A[j])) {
            B[k] = A[i++];
        } else {
            B[k] = A[j++];
        }
    }
}

void arrayCopy(int a[], int b[], int sz)
{
    for(int i=0; i<sz; i++) {
        b[i] = a[i];
    }
}

void arrayPrint(int a[], int sz)
{
    for(int i=0; i<sz; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    arrayPrint(ga, gsz);
    arrayCopy(ga, gb, gsz);
    arrayPrint(gb, gsz);
    MergeSort(ga, gb, gsz);
    arrayPrint(gb, gsz);
    arrayPrint(ga, gsz);
}

// cs50 codespace:  https://code.cs50.io/



