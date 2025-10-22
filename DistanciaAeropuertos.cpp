// Harold Arian Corimanya Arias - 20242164J

/* Para una interpretacion de este problema, afirmaremos que la matriz representará un cuadro de comparacion de distancias para cada aeropuerto, 
 por consiguiente la diagonal principal sera llenada con ceros y esta matriz debe ser simétrica*/

#include <iostream>
#include <cstdlib> // para el uso de rand y srand
#include <ctime> // para time()
#include <iomanip> // para setw()

using namespace std;

double **GenerarDistancias(int n){
    srand(time(0));
    double **dist = new double*[n]; 

    for(int i=0;i<n;i++){
        dist[i] = new double[n];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j){
            dist[i][j] = 0.0;  // 0s en la diagonal principal
            }
            else{
            dist[i][j] = 100 + rand()%1401; // Valores aleatorios entre 100 y 1500 km

            dist[j][i] = dist[i][j]; // Matriz simétrica
            }
        }
    }
    
    return dist;
}



void PromedioDistancias(double **DistAero,int n) {
    double MenorPromedio = 2000; // Numero grande para comparar en el intervalo <1500
    int IndiceMenor = 0;

    for (int i=0;i<n;i++) {
        double SumaDistancias= 0;
        for (int j=0;j<n;j++) {
            if (i != j)
                SumaDistancias += DistAero[i][j];
        }
        double promedio = SumaDistancias / (n - 1); // Sin contar el mismo aeropuerto
        cout << "Promedio de distancias desde el aeropuerto "<<i + 1<<": "<<promedio<<" km"<<endl;

        if (promedio < MenorPromedio) {
            MenorPromedio = promedio;
            IndiceMenor = i;
        }
    }

    cout << "\nEl aeropuerto con la menor distancia promedio es el aeropuerto "<<IndiceMenor + 1<<" con un promedio de "<<MenorPromedio<< " km\n";
}

void MostrarDistancias(double **DistAero,int n){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(8)<<DistAero[i][j]; 
        }
        cout<<endl;
    }
}


void liberarMatriz(double **DistAero,int n){
    for(int i=0;i<n;i++){
        delete[] DistAero[i];
        DistAero[i] = nullptr;
    }
    delete[] DistAero;
    DistAero = nullptr;

}

int main()
{
    int n;

    cout<<"Indique el numero de aeropuertos: ";
    cin>>n;

    double **DistAero = GenerarDistancias(n);

    MostrarDistancias(DistAero,n);

    PromedioDistancias(DistAero,n);

    liberarMatriz(DistAero,n); // Se libera la memoria de la matriz

    return 0;
}