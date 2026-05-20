#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) 
           return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DSU dsu(n);

    // map email → first account index
    map<string, int> emailToAcc;

    // Step 1: Union accounts
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            string email = accounts[i][j];

            if (emailToAcc.find(email) == emailToAcc.end()) {
                emailToAcc[email] = i;
            } else {
                dsu.unite(i, emailToAcc[email]);
            }
        }
    }

    // Step 2: collect emails under root account
    vector<set<string>> merged(n);

    for (auto &p : emailToAcc) {
        string email = p.first;
        int accIndex = dsu.find(p.second);

        merged[accIndex].insert(email);
    }

    // Step 3: build answer
    vector<vector<string>> result;

    for (int i = 0; i < n; i++) {
        if (merged[i].empty()) continue;

        vector<string> temp;
        temp.push_back(accounts[i][0]); // name

        for (auto &email : merged[i])
            temp.push_back(email);

        result.push_back(temp);
    }

    return result;
}

int main() {

    int n;

    cout << "Enter number of accounts: ";

    cin >> n;

    vector<vector<string>> accounts;

    for(int i = 0; i < n; i++) {

        string name;

        int emailCount;

        cout << "\nEnter name: ";

        cin >> name;

        cout << "Enter number of emails: ";

        cin >> emailCount;

        vector<string> acc;

        acc.push_back(name);

        cout << "Enter emails:\n";

        for(int j = 0; j < emailCount; j++) {

            string email;

            cin >> email;

            acc.push_back(email);
        }

        accounts.push_back(acc);
    }

    vector<vector<string>> ans = accountsMerge(accounts);

    cout << "\nMerged Accounts:\n\n";

    for(auto &acc : ans) {

        for(auto &x : acc) {

            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}