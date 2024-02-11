#include <iostream>
#include <vector>
#include <algorithm>

int razlika(std::vector<int> a, int r)
{
    std::sort(a.begin(), a.end());  //2 pokazivaca
    //1 1 4 4 5 7

    int i = 0, j = 1;   //2 pokazivaca
    int n = a.size();   //niz
    int broj = 0;       //broj razlika koje daju istu velicinu

    while (j < n) {
        if(a[j] - a[i] == r) {        //drugi minus prvi = razlika
            int i_tmp = i;
            while (i < n && a[i] == a[i_tmp]) {
              std::cout << "ITMP-" << i_tmp << "\n";
                i_tmp++;
            }
            int broj_i = i_tmp - i;
            std::cout << broj_i << "A \n";

            int j_tmp = j;                      //izjednace se, JTMP = 3
            while (j < n && a[j] == a[j_tmp])   //U PRVOJ ITERACIJI ON PORASTE ZA 1
            {
              //posto je niz sortiran, on trazi uzastopne iste vrednosti
              std::cout << "JTMP-" << j_tmp << "\n";
                j_tmp++;                        //svaki duplikat on ga poveca za jos 1
            }
            int broj_j = j_tmp - j;   //ima 1 isti kao J, sto je zapravo 2 ista, duplikati
            std::cout << broj_j << "B \n";

            broj += broj_i * broj_j;
            std::cout << "PROIZVOD: " << broj << "\n";

            i = i_tmp;
            j = j_tmp;
            std::cout << "\n\n";
        }
        else if (a[j] - a[i] > r) {
            i++;
        }
        else {
            j++;
        }
    }

    return broj;
}

int main ()
{
    // std::vector<int> a = {15745,18095,15745,16234,13395}; //visine
    std::vector<int> a = {7,1,1,4,5,4};

    // int r = 2350;
    int r = 3;

    std::cout << "Ukupno: " << razlika(a, r) << "\n";


    return 0;
}
