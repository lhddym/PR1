#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global array stored 1-10000
int arr[10000]; 

// sequential search £¨iterative version) 
//count from 1 to 10000, and compare each one with key
int seqiter(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}



// sequential search (recursive version)
int seqrecur(int arr[], int index, int n, int key) {
    if (index >= n) { //if have found all indexs
        return -1;
    }else if (arr[index] == key){
        return index;
    } else {
           return seqrecur(arr, index + 1, n, key);
}
}

// index initial value = 0
int seqrecurInitial(int arr[], int n, int key) {
    return seqrecur(arr, 0, n, key);
}



// binary search£¨iterative version) 
int biniter(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // take the mid and compare it with key
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}



// binary search (recursive version)
int binrecur(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binrecur(arr, mid + 1, high, key);
    else
        return binrecur(arr, low, mid - 1, key);
}

// low initial value = 0, high initial value = n
int binrecurInitial(int arr[], int n, int key) {
    return binrecur(arr, 0, n - 1, key);
}

// main function
int main() {
    // values to be tested
    int N_values[] = {100, 500, 1000, 2000, 4000, 6000, 8000, 10000};
    int num_N = sizeof(N_values) / sizeof(N_values[0]); // calculate the number of 'N'
    
    int key = -1; // the worst situation: key not in arr
    
    // print the header
    printf("N\tSeqIter\t\tSeqRecur\tBinIter\t\tBinRecur\n");
    
    // test every N
    int i;
    for (i = 0; i < num_N; i++) {
        int N = N_values[i];
        
        // initialise the arr as 1-n-1
        int j;
        for (j = 0; j < N; j++) {
            arr[j] = j;
        }
        
        // set the number of repetitions
        int K_seq = 1000000 / N;  // sequence search
        if (K_seq < 100) K_seq = 100;
        int K_bin = 10000000;      // binary search
    
        
        
        
        // sequential search £¨iterative version) 
        clock_t start = clock();
        int k;
        for (k = 0; k < K_seq; k++) {
            seqiter(arr, N, key);
        }
        clock_t end = clock();
        double t_seqIter = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // sequential search (recursive version)
        start = clock();
        for (k = 0; k < K_seq; k++) {
            seqrecurInitial(arr, N, key);
        }
        end = clock();
        double t_seqRecur = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // inary search£¨iterative version) 
        start = clock();
        for (k = 0; k < K_bin; k++) {
            biniter(arr, N, key);
        }
        end = clock();
        double t_binIter = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // binary search (recursive version)
        start = clock();
        for (k = 0; k < K_bin; k++) {
            binrecurInitial(arr, N, key);
        }
        end = clock();
        double t_binRecur = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        // print the outcome
        printf("%d\t%f\t%f\t%f\t%f\n", N, t_seqIter, t_seqRecur, t_binIter, t_binRecur);
    }
    
    system("pause");
    return 0;
}

