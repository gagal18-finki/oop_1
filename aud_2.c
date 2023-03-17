#include<stdio.h>
typedef struct Tocka Tocka;
typedef struct Krug Krug;
struct Tocka{
    int x;
    int y;
};
struct Krug{
    Tocka Centar;
    int Radius;
};
float plostina(int r){
    return r*r*3.14;
}

int main(){
    int n, max_r = 0;
    scanf("%d", &n);
    Krug MaxKrug;
    Krug Krugovi[100];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &Krugovi[i].Centar.x, &Krugovi[i].Centar.y,&Krugovi[i].Radius);
    }
    for (int i = 0; i < n; i++) {
        if((&Krugovi[i])->Radius > max_r){
            MaxKrug = Krugovi[i];
            max_r = (&Krugovi[i])->Radius;
        }
    }
    printf("Largest circle has area of: %.2f with centre: (%d,%d)", plostina(MaxKrug.Radius), MaxKrug.Centar.x, MaxKrug.Centar.y);

}