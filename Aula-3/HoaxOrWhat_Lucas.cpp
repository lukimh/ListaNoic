/*
 * File:   HoaxOrWhat.cpp
 * Author: 2015105498
 *
 * Created on 4 de Maio de 2016, 18:12
 */

#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

map<int,int> bills;

/*
 *
 */
int main(int argc, char** argv) {
    int days;

    while (scanf("%d", &days) == 1 && days != 0) {
        int total = 0;
        for (int j = 0; j < days; j++) {
            int numBills;
            scanf("%d", &numBills);
            for (int i = 0; i < numBills; i++) {
                int bill;
                scanf("%d", &bill);
                bills[bill]++;
            }

            map<int,int>::iterator menor = bills.begin();
            map<int,int>::iterator maior = bills.end();

            maior--;

            total+= (*maior).first - (*menor).first;

            if((*menor).second > 1) (*menor).second--;
            else {
                bills.erase((*menor).first);
            }

            if((*maior).second > 1) (*maior).second--;
            else {
                bills.erase((*maior).first);
            }
        }
        bills.clear();
        printf("%d\n", total);
    }
    printf("\n");
    return 0;
}

