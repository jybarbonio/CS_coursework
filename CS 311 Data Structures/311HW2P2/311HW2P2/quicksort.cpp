// CS311 Quick Sort - plug in your partition and it should work


#include<iostream>
using namespace std;

// partitions the array a into smaller than pivot and others.
int partition(int a[], int f, int r)
{
    cout << ".. Partition called with " << "front " << f << " and rear " << r << endl;
    int pivot = a[f];  // pivot is the first element
    int small = f; // pointer from the left
    int large = r; // pointer from the right 

    while (small <= large)//until they cross
    {
        // loop for finding out of place pairs and swap them
        // ** until the small and large cross
        if (a[large] > pivot)               //    if small OK, move left
        {
            large--;
        }
        else if (a[small] < pivot)          //    if large OK, move right
        {
            small++;
        }
        else
        {
            if (a[small] >= pivot && a[large] < pivot)        //    if both are bad, swap and then move
            {
                int temp = a[small];
                a[small] = a[large];
                a[large] = temp;
                small++;
                large--;
            }
            else
            {
                large--;
            }
        }

    }//end of while

  // ** return the partition point where
  // those smaller than pivot are before what is returned
  // ** there is a special cases and a regular case

    if (small < 1)
    {
        return 1;
    }
    else
    {
        return small;    // return first slot of large section
                     // small should point the first element of larger (higher than the pivot) partition
    }
}


// sorting a's section starting at f and ending at r
void quicksort(int a[], int f, int r)
{
    if (f >= r) return;

    cout << "QuickSort front is " << f << " and rear is " << r << endl;

    int beg = partition(a, f, r);

    quicksort(a, f, beg - 1);  // sort the small section in place
    quicksort(a, beg, r);    // sort the large section in place
}


int main()
{
    int x;
    int nums[10];
    cout << "How many elements? (must be less than 10) ";
    cin >> x;
    cout << "Enter elements one per line.." << endl;
    for (int i = 0; i < x; i++)
    {
        cin >> nums[i];
    }

    quicksort(nums, 0, x - 1);

    cout << "FINAL RESULT:" << endl;
    for (int i = 0; i < x; i++) // up to the partition
    {
        cout << nums[i];
    }
    cout << endl;
}