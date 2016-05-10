#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <ctype.h>

using namespace std;

struct project{
	string nome;
	set<string> est;
	
	bool operator>(project p) const{
		return (est.size() < p.est.size()) || ( (est.size() == p.est.size()) && (nome > p.nome) );
	}
	
	bool operator<(project p) const{
		return (est.size() > p.est.size()) || ( (est.size() == p.est.size()) && (nome < p.nome) );
	}
	
	bool operator==(project p) const{
		return (nome == p.nome) && (est.size() == p.est.size());
	}
	
	bool operator!=(project p) const{
		return !operator==(p);
	}
};

vector<project> projetos;
vector<project>::iterator proj_it;

set<string>::iterator str_it;

set<string> ban;
bool checkBan(string nome){	
	return !(ban.find(nome) == ban.end());
}

void remove(const string nome){
	for(proj_it = projetos.begin(); proj_it != projetos.end(); proj_it++){
		project* p = (project*)&(*proj_it);
		p->est.erase(nome);
	}
}

int main(){
	string line;
	getline(cin, line);
	while(line.compare("0")!=0){
		while(line.compare("1")!=0){
			project novo;
			set<project>::iterator p_novo;
			if(isalpha(line[0]) && isupper(line[0])){
				novo.nome = line;
			}
			
			getline(cin, line);
			while(isalpha(line[0]) && islower(line[0])){
				if(checkBan(line)) {
					getline(cin, line);
					continue;
				}
				bool already_in = false;
				bool banished = false;
				for(proj_it = projetos.begin(); proj_it != projetos.end(); proj_it++){
					if((*proj_it).est.find(line) != (*proj_it).est.end()){
						remove(line);
						if(!banished) {
							ban.insert(line);
							banished = true;
						}
						break;
					}
				}
				
				if(novo.est.find(line)==novo.est.end() && !banished) {
					novo.est.insert(line);
				}
				
				getline(cin, line);
			}
			projetos.push_back(novo);
		}
		
		sort(projetos.begin(), projetos.end());
		
		for(proj_it = projetos.begin(); proj_it != projetos.end(); proj_it++){
			printf("%s %lu\n", (*proj_it).nome.c_str(), (*proj_it).est.size());
		}
		ban.clear();
		projetos.clear();
		getline(cin, line);
	}
}

