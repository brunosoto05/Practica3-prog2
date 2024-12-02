#include <iostream>
using namespace std;

struct Punto {
    int x; 
    int y; 
};
string determinarCuadrante(const Punto& punto) {
    if (punto.x > 0 && punto.y > 0) return "Cuadrante 1";
    else if (punto.x < 0 && punto.y > 0) return "Cuadrante 2";
    else if (punto.x < 0 && punto.y < 0) return "Cuadrante 3";
    else if (punto.x > 0 && punto.y < 0) return "Cuadrante 4";
    else if (punto.x == 0 && punto.y != 0) return "Eje Y";
    else if (punto.y == 0 && punto.x != 0) return "Eje X";
    else return "Origen";
}
void ecuacionRecta(const Punto& p1, const Punto& p2) {
    if (p1.x == p2.x) {
        cout << "Los puntos pertenecen a una línea vertical: x = " << p1.x << endl;
    } else if (p1.y == p2.y) {
        cout << "Los puntos pertenecen a una línea horizontal: y = " << p1.y << endl;
    } else {
        double m = static_cast<double>(p2.y - p1.y) / (p2.x - p1.x);
        double b = p1.y - m * p1.x; 
        cout << "Los puntos pertenecen a la recta: y = " << m << "x + " << b << endl;
    }
}

int main() {
    int n; 
    cout << "Ingrese el número de coordenadas: ";
    cin >> n;

    Punto puntos[10]; 

    for (int i = 0; i < n; i++) {
        cout << "Ingrese la coordenada " << i + 1 << " (x y): ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    for (int i = 0; i < n; i++) {
        cout << "La coordenada (" << puntos[i].x << ", " << puntos[i].y 
             << ") está en el " << determinarCuadrante(puntos[i]) << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Comparando (" << puntos[i].x << ", " << puntos[i].y 
                 << ") y (" << puntos[j].x << ", " << puntos[j].y << "): ";
            ecuacionRecta(puntos[i], puntos[j]);
        }
    }

    return 0;
}
