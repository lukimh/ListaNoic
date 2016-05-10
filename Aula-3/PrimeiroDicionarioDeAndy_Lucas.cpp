/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lucas
 *
 * Created on 9 de Maio de 2016, 14:30
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <set>


using namespace std;

string letter = "";


set<string> heap;

bool EhLetra(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return true;
    return false;
};

string getPalavra(string s){
    unsigned int ini = s.find_first_of(letter);
    unsigned int fim = s.find_last_of(letter);
    for(int i = ini; i <= fim; i++){
        if(!EhLetra(s[i])) return "";
        s[i] = tolower(s[i]);
    }
    
    return s.substr(ini, fim-ini+1);
};

int main(){
    string s = "";
    char c;
    
    c = fgetc(stdin);
    while(!feof(stdin)){
        while(!feof(stdin) && !isalpha(c)) c = fgetc(stdin);
        while(!feof(stdin) && isalpha(c)) {
            s+= tolower(c);
            c = fgetc(stdin);
        }
        if(!s.empty()) {
            heap.insert(s);
            s = "";
        }
    }
    
    set<string>::iterator it = heap.begin();
    do{
        cout << *it << endl;
    }while(++it != heap.end());
}

