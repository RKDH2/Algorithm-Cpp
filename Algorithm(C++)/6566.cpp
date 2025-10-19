#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, vector<string>>& a, const pair<string, vector<string>>& b) {
    const vector<string>& valuea = a.second;
    const vector<string>& valueb = b.second;
    if (valuea.size() > valueb.size()) {
        return true;
    }
    else if (valuea.size() < valueb.size()) {
        return false;
    }
    else {
        if (valuea[0] < valueb[0]) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {
    vector<pair<string, vector<string>>> v;
    map<string, vector<string>> group;
    while (1) {
        string word, w;
        cin >> word;
        w = word;
        if (cin.eof()) break;
        sort(word.begin(), word.end());
        group[word].push_back(w);
    }
    for (auto iter = group.begin(); iter != group.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }
    for (auto iter = group.begin(); iter != group.end(); iter++) {
        v.push_back({ iter->first, iter->second });
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < min((int)v.size(), 5); i++) {
        vector<string>& value = v[i].second;
        cout << "Group of size " << value.size() << ": ";
        cout << value[0] << ' ';
        for (int j = 1; j < value.size(); j++) {
            if (value[j - 1] != value[j]) {
                cout << value[j] << ' ';
            }
        }
        cout << ".\n";
    }
}