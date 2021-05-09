#include <cstring>
#include <iostream>
#include <vector>
#include <memory> // shared_ptr
using namespace std;

void quick_sort(int arr[], int left_index, int right_index) {
    if (left_index >= right_index) {
        return;
    }

    int pivot = arr[left_index];
    int left = left_index;
    int right = right_index;
    while (left < right) {
        while (arr[right] >= pivot && left < right) {
            right--;
        }
        while (arr[left] <= pivot && left < right) {
            left++;
        }
        // 此时, left和right指向等待互换的两个值
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    arr[left_index] = arr[left];
    arr[left] = pivot;

    quick_sort(arr, left_index, left - 1);
    quick_sort(arr, right + 1, right_index);
}

void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void select_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[min_pos] > arr[j]) {
                min_pos = j;
            }
        }
        if (i != min_pos) {
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
}

void insert_sort(int arr[], int len) {
    int i, j;
    for (i = 1; i < len; i++) {
        int temp = arr[i];
        for (j = i - 1; j >= 0; j--) {
            if (temp < arr[j]) { // 大的值依次后挪腾出位置
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        // arr[j] <= temp 则找到插入位置为j+1, 取等保证稳定
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int start, int mid, int end) {
    int m = mid - start + 1;
    int n = end - mid;
    int left[m];
    int right[n];

    int i, j;
    // 先把arr中的左右两有序区间分别复制进left和right数组中
    for (i = 0; i < m; i++) {
        left[i] = arr[i + start];
    }
    for (j = 0; j < n; j++) {
        right[j] = arr[j + mid + 1];
    }

    // 再从两个有序数组中依次取值, 填回arr
    i = 0; j = 0;
    int k = start;
    while (i < m && j < n) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    // 此时可能某个数组还没取完(也可能都取完了)
    while (i < m) {
        arr[k++] = left[i++];
    }
    while (j < n) {
        arr[k++] = right[j++];
    }
}
void merge_sort(int arr[], int start, int end) {
    // 递归停止条件是区间被细分成长度为1时
    if (start == end) {
        return;
    }
    // 先递归地对左右区间归并排序, 使二者分别有序, 再合并为一个整体
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void count_sort(int arr[], int len) {
    int min_val = arr[0], max_val = arr[0];
    for (int i = 1; i < len; i++) {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    int count[max_val - min_val + 1] = {0}; // 记得置0, 否则后面++的时候会出错
    for (int i = 0; i < len; i++) {
        count[arr[i]]++;
    }

    int pos = 0;
    for (int val = 0; val < max_val - min_val; val++) {
        // 数字val重复了k次
        for (int k = 0; k < count[val]; k++) {
            arr[pos++] = val;
        }
    }
}


int main(int argc, char const *argv[]) {
    int arr[] = {3, 2, 1, 5, 4, 7, -2, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    // quick_sort(arr, 0, len - 1);
    // bubble_sort(arr, len);
    // select_sort(arr, len);
    // insert_sort(arr, len);
    // merge_sort(arr, 0, len - 1);
    count_sort(arr, len);

    for (int num : arr) {
        cout << num << " ";
    }
}