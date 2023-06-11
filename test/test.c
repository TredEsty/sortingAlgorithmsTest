#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<string.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void merge3(int arr[], int left[], int middle1[], int middle2[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0, l = 0;
 
    while (i < n1 && j < n2 && k < n3) {
        if (left[i] < middle1[j]) {
            if (left[i] < middle2[k]) {
                arr[l++] = left[i++];
            } else {
                arr[l++] = middle2[k++];
            }
        } else {
            if (middle1[j] < middle2[k]) {
                arr[l++] = middle1[j++];
            } else {
                arr[l++] = middle2[k++];
            }
        }
    }
 
    while (i < n1 && j < n2) {
        if (left[i] < middle1[j]) {
            arr[l++] = left[i++];
        } else {
            arr[l++] = middle1[j++];
        }
    }
 
    while (i < n1 && k < n3) {
        if (left[i] < middle2[k]) {
            arr[l++] = left[i++];
        } else {
            arr[l++] = middle2[k++];
        }
    }
 
    while (j < n2 && k < n3) {
        if (middle1[j] < middle2[k]) {
            arr[l++] = middle1[j++];
        } else {
            arr[l++] = middle2[k++];
        }
    }
 
    while (i < n1) {
        arr[l++] = left[i++];
    }
 
    while (j < n2) {
        arr[l++] = middle1[j++];
    }
 
    while (k < n3) {
        arr[l++] = middle2[k++];
    }
}
 
void mergeSort3(int arr[], int n)
{
    if (n < 2) {
        return;
    }
 
    int i, j, k;
    int mid1 = n / 3;
    int mid2 = mid1 * 2;
    int left[mid1], middle1[mid2 - mid1], middle2[n - mid2];
 
    for (i = 0; i < mid1; i++) {
        left[i] = arr[i];
    }
    for (j = 0; j < mid2 - mid1; j++) {
        middle1[j] = arr[mid1 + j];
    }
    for (k = 0; k < n - mid2; k++) {
        middle2[k] = arr[mid2 + k];
    }
 
    mergeSort3(left, mid1);
    mergeSort3(middle1, mid2 - mid1);
    mergeSort3(middle2, n - mid2);
 
    merge3(arr, left, middle1, middle2, mid1, mid2 - mid1, n - mid2);
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

// function to perform heapify operation on sub-tree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;  // initialize largest as root
    int l = 2 * i + 1;  // left child
    int r = 2 * i + 2;  // right child
 
    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // if largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to perform heap sort
void heapSort(int arr[], int n) {
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // extract an element from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void countingSort(int arr[], int n, int max) {
    int count[max+1], output[n];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for(int i = 1; i <= max; i++) {
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; i--) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
int maxByDigits(int n) {
    int max_val = 1;
    while (n > 9) {
        n /= 10;
        max_val *= 10;
    }
    return max_val * 10 - 1;
}
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void countingSortForRadix(int arr[], int n, int exp) {
    int count[10] = {0};
    int output[n];

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    for (int i = n-1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10]-1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; exp<=maxByDigits(getMax(arr,n)); exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

void bucketSort(int arr[], int n) {
    int i, j;
    int min_val = arr[0], max_val = arr[0];

    // Find the minimum and maximum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] < min_val)
            min_val = arr[i];
        else if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Create a bucket for each element in the range of values
    int num_buckets = max_val - min_val + 1;
    int *buckets[num_buckets];
    for (i = 0; i < num_buckets; i++)
        buckets[i] = (int*) malloc(sizeof(int));

    // Add each element to the appropriate bucket
    for (i = 0; i < n; i++) {
        int index = arr[i] - min_val;
        buckets[index] = (int*) realloc(buckets[index], sizeof(int) + 1);
        buckets[index][0]++;
        buckets[index][buckets[index][0]] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < num_buckets; i++) {
        int bucket_size = buckets[i][0];
        if (bucket_size > 1) {
            for (j = 2; j <= bucket_size; j++) {
                int key = buckets[i][j];
                int k = j - 1;
                while (k >= 1 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
        }
    }

    // Copy the elements back into the original array
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        int bucket_size = buckets[i][0];
        for (j = 1; j <= bucket_size; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}


int main() {

    //using a debugger is recommended in order to see in greater depth how the algorithms work

    //I recommend using this site https://numbergenerator.org/numberlistrandomizer
    //in order to create lists(you have a lot of options)

    char* input_filename = "reversed3.txt"; //change the list which you want to test your code on
    char* output_filename="output.txt"; //the sorted lists output

    // Open the input file
    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'\n", input_filename);
        return 1;
    }

    // Read the list of integers from the input file
    int max_num = 1000000;  // Maximum value of an integer in the list
    int arr[max_num];
    int n = 0;
    char line[100];
    while (fgets(line, 100, input_file) != NULL) {
        arr[n++] = atoi(line);
    }

    // Close the input file
    fclose(input_file);

    //uncomment the line of the sorting algorithm you want to use

    // Sort the list using various sorting algorithms
    //bubbleSort(arr, n);
    //selectionSort(arr, n);
    //insertionSort(arr, n);
    //mergeSort(arr, 0, n-1);
    mergeSort3(arr, n-1);
    //quicksort(arr, 0, n-1);
    //heapSort(arr, n);
    //countingSort(arr, n, maxByDigits(getMax(arr,n)));
    //radixSort(arr, n);
    //bucketSort(arr, n);

    // Open the output file
    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file '%s'\n", output_filename);
        return 1;
    }

    // Write the sorted lists to the output file
    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%d\n", arr[i]);
    }

    // Close the output file
    fclose(output_file);

    return 0;
}