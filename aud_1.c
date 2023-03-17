#include<stdio.h>

typedef struct Transaction Transaction;
struct Transaction{
    int id;
    int platena_suma;
    int platena_provizija;
    int plateno_card;
};

int main(){
    int n, br_plateni_card = 0;
    Transaction T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &T.id, &T.platena_suma, &T.platena_provizija, &T.plateno_card);
        if(T.plateno_card){
            printf("%d %d\n", T.id, T.platena_provizija + T.platena_suma);
            br_plateni_card++;
        }
    }
    if(br_plateni_card == 0){
        printf("No credit card transaction");
    }
    return 0;
}