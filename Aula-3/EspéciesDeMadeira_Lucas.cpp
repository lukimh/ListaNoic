#include <map>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int numCases;
	scanf("%d\n\n", &numCases);
	for(int i = 0; i < numCases; i++){
		if(i!=0) printf("\n");
		map<string,int> mapa;
		char nome[31];
		int TotalEspecies = 0;
		while(!cin.fail() && !cin.bad() && !cin.eof()){
			cin.getline(nome, 31, '\n');
			if(strlen(nome)==0) break;
			if(mapa.find(nome) != mapa.end()){
				mapa[nome]+=1;
			} else {
				mapa[nome]=1;
			}
		}
		map<string, int>::iterator it;

		for(it = mapa.begin(); it != mapa.end(); it++){
			TotalEspecies += (*it).second;
		}

		for(it = mapa.begin(); it != mapa.end(); it++){
			printf("%s %.4f\n", (*it).first.c_str(), ((*it).second * 100.0)/(float)TotalEspecies);
		}
		mapa.clear();
		
	}
}
