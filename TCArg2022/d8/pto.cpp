

typedef double tipo; //Se puede cambiar a ll si me dan todo en enteros.

struct pto      //¡Los vectores (geométricos) también son puntos!
{
    tipo x, y;
    pto operator+(const pto& o) const { return {x + o.x, y + o.y}; }
    pto operator-(const pto& o) const { return {x - o.x, y - o.y}; }
    tipo operator*(const pto& o) const { return x * o.x + y * o.y; } //Producto escalar
    tipo operator^(const pto& o) const { return x * o.y - y * o.x; } //Producto vectorial (no conmutativo, me cambia el signo)
    bool left(pto q, pto r){return ((q - *this) ^ (r - *this)) > 0;}    //p.left(q, r) = T si p está a la izquierda de la recta qr dirigida (no colineal).
    bool operator<(const pto& a) const{return x < a.x - EPS || (abs(x - a.x) < EPS && y < a.y - EPS);}
};

pto operator*(tipo k, const pto& p) { return {k * p.x, k * p.y}; } //Producto entre escalar y vector (EN ESE ORDEN)

ostream &operator <<(ostream &os, const pto& p) //Para el cout de puntos
{
    return os << "(" << p.x << "," << p.y << ")";
}

istream &operator >>(istream &is, pto &p) //Para el cin de puntos
{
    return is >> p.x >> p.y;
}



 
//___________________________
 
int main(){


    pto p1, d1, p2, d2;
    
    cin >> p1 >> d1 >> p2 >> d2;
    
    double alpha = double((p2 - p1) ^ d2) / double(d1 ^ d2);
    double beta = double((p1 - p2) ^ d1) / double(d2 ^ d1);
    
    cout << "Punto de intersección: " << endl;  //Obviamente, los 2 de abajo son el mismo punto.
    
    cout << fixed << setprecision(11) << p1+alpha*d1 << endl;  //Le puse 11, aunque se suele tomar que a==b si y solo si llabs(a-b)<1e-9
    cout << fixed << setprecision(11) << p2+beta*d2 << endl;
    
    
    
    
    return 0;
}