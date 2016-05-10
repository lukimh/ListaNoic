#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> ingredients;
vector<pair<int, string> >possibleRecipes;
int numBinders;

int main(){
	scanf("%d\n", &numBinders);
//	printf("%d\n", numBinders);
	for(int i = 0; i < numBinders; i++){
		string nameBinder;
		int numIng, numRecipes, budget;
		getline(cin, nameBinder, '\n');
		scanf("%d %d %d\n", &numIng, &numRecipes, &budget);

		int l = 0;
		while (nameBinder[l]) {
			char c=nameBinder[l];
			printf("%c", toupper(c));
			l++;
  		}
		printf("\n");

		//Ler ingredientes
		for(int j = 0; j < numIng; j++){
			string ingredientName;
			int valor;

			getline(cin, ingredientName, ' ');
			scanf("%d\n", &valor);

			//cout << ingredientName << ' ' << valor << endl;
			ingredients[ingredientName] = valor;
		}

		//Ler Receitas
		for(int j = 0; j < numRecipes; j++){
			int valortotal = 0;
			string recipeName;

			getline(cin, recipeName, '\n');
			scanf("%d\n", &numIng);

			//Ler ingredients nescessários para esta receita
			for(int k = 0; k < numIng; k++){
				string ingredientName;
				int qnt;

				cin >> ingredientName;
				scanf("%d\n", &qnt);

				//cout << ">> " << ingredientName << ' ' << qnt << endl;
				valortotal+=ingredients[ingredientName]*qnt;
			}

			if(valortotal <= budget)
				possibleRecipes.push_back(make_pair(valortotal, recipeName));
		}

		sort(possibleRecipes.begin(), possibleRecipes.end());

		if(possibleRecipes.size() == 0) printf("Too expensive!\n");
		else {
			vector<pair<int, string> >::iterator it;
			for(it = possibleRecipes.begin(); it != possibleRecipes.end(); it++){
				cout << (*it).second << endl;
			}
		}

		ingredients.clear();
		possibleRecipes.clear();
        printf("\n");
	}

}
