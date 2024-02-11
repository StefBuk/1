#include <iostream>
#include <vector>

int kajmak(const std::vector<int> &a, int t)
{
    int max = 0, suma = 0;  //maksimalni element, suma

    int i = 0, j = 0;

    int n = a.size(); //velicina vektora

    while (j < n)
    {   //krece se kroz niz i sumira sve elemente
        suma += a[i];

        while(j <= i && suma >= t)
        {
          suma -= a[j];
          j++;
        }
      
		    if (suma > max)
        {
            max = suma;
        }
    }

    return suma;
}


int main ()
{


    return 0;
}
