#include <iostream>
#include <vector>

using namespace std;

vector<int> combination;

void gerador(vector<int> &a, int item) {
    // vai escolher ou nao um item
    if (item == a.size()) {
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i] << " ";
        }
        cout << endl;

        return;
    }

    combination.push_back(a[item]);
    gerador(a, item + 1);
    combination.pop_back();
    gerador(a, item + 1);
}

int main() {
    vector<int> arr = {0, 10, 3, 4, 8};

    // {0, 10} , {0}, {3, 4, 8}

    gerador(arr, 0);
}