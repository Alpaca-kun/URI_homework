#include<bits/stdc++.h>

using namespace std;

struct solution {
    int total;
    int weight;
    int amount;
};

vector<vector<solution>> memo;

// Retorna a quantidade maxima de brinquedos quando tem p pacotes em uma capacidade c 
solution maximumToys(int p, int c, vector<int> &weight, vector<int> &qt) {
    if (memo[p][c].total >= 0) {
        return memo[p][c];
    }

    // Para um pacote, verifica se o peso e menor que a capacidade
    if (p == 0) {
        // Caso sim, retorno a quantidade de brinquedos desse pacote
        if (weight[0] <= c) {
            return {qt[0], weight[0], 1};
        }
        
        // Caso nao, nao retorn nada
        return {0, 0, 0};
    }

    // Focar no p-esimo pacote
    // Nao vai incluir o p-esimo pacote
    solution withoutpthPackage = maximumToys(p - 1, c, weight, qt);
    
    // Vai incluir o p-esimo pacote
    solution withpthPackage = {0, 0, 1};
    if (weight[p] <= c) {
        withpthPackage = maximumToys(p - 1, c - weight[p], weight, qt);
        withpthPackage.total += qt[p];
        withpthPackage.weight += weight[p];
        withpthPackage.amount += 1;
    }

    // Caso o peso do pacote p ultrapasse a capacidade
    // vai chamar a mesma recursao que o do withoutpthPackage

    int compare = max(withoutpthPackage.total, withpthPackage.total);
    if (compare == withoutpthPackage.total) {
        memo[p][c] = withoutpthPackage;
        return withoutpthPackage;
    }
    else {
        memo[p][c] = withpthPackage;
        return withpthPackage;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int pac;
        cin >> pac;

        vector<int> qt(pac), peso(pac);
        for (int j = 0; j < pac; j++) {
            cin >> qt[j] >> peso[j];
        }

        memo.assign(pac, vector<solution>(50 + 1, solution{-1, -1, -1}));

        // Maximizar o numero de brinquedos que cabem no saco
        solution s = maximumToys(pac - 1, 50, peso, qt);
        cout << s.total << " brinquedos" << endl;
        cout << "Peso: " << s.weight << " kg" << endl;
        cout << "sobra(m) " << pac - s.amount << " pacote(s)" << endl;
        cout << endl;
    }
}