#include<bits/stdc++.h>

using namespace std;

int first = 0;
int binarySearch(int n, int s, int *vector) {
    int find = 0;
    int last = s - 1;
    int middle;

    while (first <= last) {
        middle = (first + last) / 2;

        if (n <= vector[middle]) {
            last = middle - 1;
        }         
        else {
            find = 1;
            first++;
            break;
        }
    }

    return find;
}

int main() {
    int S;
    cin >> S;

    int Qi[S], Ni[S];
    for (int i = 0; i < S; i++)
        cin >> Qi[i];
    for (int i = 0; i < S; i++)
        cin >> Ni[i];

    sort(Qi, Qi + S);
    sort(Ni, Ni + S);

    int win = 0;
    int totalWin = 0;
    for (int i = 0; i < S; i++) {
        win = binarySearch(Ni[i], S, Qi);
        if (win > 0)
            totalWin++;
    }


    cout << totalWin << endl;
}