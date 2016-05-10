/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GloudComputing.cpp
 * Author: lucas
 *
 * Created on 9 de Maio de 2016, 16:02
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

struct cliente {
    set<int> servidores;

    void insere(int servidor) {
        servidores.insert(servidor);
    }

    int numConeccoes() {
        return servidores.size();
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    int n, m;
    while (scanf("%d %d\n", &n, &m) == 2 && n!=0 && m!=0) {
        map<string, set<int> > servicos;
        cliente clientes[200];
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d ", &k);
            for (int j = 0; j < k; j++) {
                string servico;
                cin >> servico;
                servicos[servico].insert(i);
            }
        }

        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d ", &x);
            for (int j = 0; j < x; j++) {
                string servico;
                cin >> servico;
                clientes[i].servidores.insert(servicos[servico].begin(), (servicos[servico].end()) );
            }
        }

        int num = 0;
        for (int k = 0; k < m; k++) {
            num += clientes[k].numConeccoes();
        }
        printf("%d\n", num);
    }
    return 0;
}

