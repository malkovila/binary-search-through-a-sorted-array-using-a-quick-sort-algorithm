#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int patrition(vector<int>& a, int start, int end) {
    srand(time(NULL));
    int num = start + rand() % (end - start + 1);
    int wall = a[num];
    swap(a[num], a[start]);
    int j = start;
    for (int i = start+1; i <= end; i++) {
        if (a[i] <= wall) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[start], a[j]);
    return j;
}

void quick_sort(vector<int>& a, int start, int end) {
    if (start >= end) return;
    int index = patrition(a, start, end);
    quick_sort(a, start, index - 1);
    quick_sort(a, index + 1, end);
}

int binary_search(vector<int> a, int el) {
    int start = 0;
    int end = a.size() - 1;
    while (start <= end) {
        int m = (start + end) / 2;
        if (a[m] == el) return m;
        else if (el < a[m]) end = m - 1;
        else start = m + 1;
    }
}

int main()
{
    srand(time(NULL));

    vector <pair<int, int>> a;
    vector <int> lst;
    for (int i = 0; i < 100; i++) {
        int num = 0 + rand() % (100000 - 0 + 1);
        lst.push_back(num);
    }
    
    clock_t start = clock();
    quick_sort(lst, 0, lst.size()-1);
    cout << binary_search(lst, 100000);
    clock_t end = clock();
    
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

    return 0;
}
