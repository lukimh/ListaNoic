/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PontosDeFeno.cpp
 * Author: lucas
 *
 * Created on 9 de Maio de 2016, 15:42
 */

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
 * 
 */

map <string,int> haydic;

int main(int argc, char** argv) {
    int m, n;

    while (scanf("%d %d\n", &m, &n) == 2) {
        for (int i = 0; i < m; i++) {
            string s;
            int value;
            getline(cin, s, ' ');
            scanf("%d\n", &value);
            haydic[s] = value;
            //cout << s << ' ' << haydic[s] << endl;
        }

        int salary = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            while (s != ".") {
                //cout << s << " <<<<<\n";
                salary += haydic[s];
                cin >> s;
            }
            printf("%d\n", salary);
            salary = 0;
        }


    }
    return 0;
}

