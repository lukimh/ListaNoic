/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdio>
#include <map>
#include <iostream>
#include <string>



using namespace std;

int main() {
    int numCasos;
    scanf("%d", &numCasos);
    while (numCasos--) {
        int m, n;
        map<string, string> tradutor;
        scanf("%d %d\n", &m, &n);

        for (int i = 0; i < m; i++) {
            string jap;
            string port;
            getline(cin, jap, '\n');
            getline(cin, port, '\n');

            tradutor[jap] = port;
        }

        for (int i = 0; i < n; i++) {
            string line;
            string word = "";
            getline(cin, line, '\n');
            //cout << "\"" << line << "\" << linha caramba\n";
            string::iterator it;
            for (it = line.begin(); it != line.end(); it++) {
                if (*it == ' ') {
                    if (tradutor.find(word) == tradutor.end()) {
                        cout << word << *it;
                    } else {
                        cout << tradutor[word] << *it;
                    }
                    word.clear();
                } else {
                    word.append(1, *it);
                }
            }
            if (tradutor.find(word) == tradutor.end()) {
                cout << word << '\n';
            } else {
                cout << tradutor[word] << '\n';
            }
            word.clear();
        }
        printf("\n");
    }
}

