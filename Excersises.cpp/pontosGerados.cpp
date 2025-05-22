#include <bits/stdc++.h>

typedef struct { int x; int y; } Point;
Point O = {INT_MAX, INT_MAX}; // Melhor representação do ponto no infinito

// Função para verificar se um ponto está na curva
int is_on_curve(Point p, int a, int b, int p_mod) {
    if (p.x == O.x && p.y == O.y) return 1;
    int lhs = (p.y * p.y) % p_mod;
    int rhs = (p.x * p.x * p.x + a * p.x + b) % p_mod;
    return lhs == rhs;
}

// Função para calcular o inverso modular
int inv_mod(int a, int p) {
    a = a % p;
    if (a < 0) a += p;
    for (int x = 1; x < p; x++) {
        if ((a * x) % p == 1) {
            return x;
        }
    }
    return -1; // Não existe inverso
}

// Função para somar dois pontos na curva elíptica
Point point_add(Point P, Point Q, int a, int p_mod) {
    if (P.x == O.x) return Q;
    if (Q.x == O.x) return P;
    
    // Caso P == -Q (soma resulta em O)
    if (P.x == Q.x && (P.y + Q.y) % p_mod == 0) return O;
    
    int m;
    if (P.x == Q.x && P.y == Q.y) {
        // Duplicação de ponto
        int denom = inv_mod(2 * P.y, p_mod);
        if (denom == -1) return O;
        m = (3 * P.x * P.x + a) * denom % p_mod;
    } else {
        // Pontos distintos
        int denom = inv_mod(Q.x - P.x, p_mod);
        if (denom == -1) return O;
        m = (Q.y - P.y) * denom % p_mod;
    }
    
    if (m < 0) m += p_mod;
    
    Point R;
    R.x = (m * m - P.x - Q.x) % p_mod;
    R.y = (m * (P.x - R.x) - P.y) % p_mod;
    
    if (R.x < 0) R.x += p_mod;
    if (R.y < 0) R.y += p_mod;
    
    return R;
}

int main() {
    int a = 2, b = 2, p = 17; // Curva: y² = x³ + 2x + 2 mod 17
    Point G = {5, 1};          // Ponto gerador
    
    if (!is_on_curve(G, a, b, p)) {
        printf("G não está na curva!\n");
        return 1;
    }
    
    printf("multiplos de G=(%d,%d) na curva y² = x³ + %dx + %d mod %d\n\n", 
           G.x, G.y, a, b, p);
    
    Point current = O;
    for (int k = 1; k <= 20; k++) {
        current = point_add(current, G, a, p);
        printf("%2dG = ", k);
        if (current.x == O.x) {
            printf("O\n");
            break;
        } else {
            printf("(%2d, %2d)\n", current.x, current.y);
            
            // Verificação adicional
            if (!is_on_curve(current, a, b, p)) {
                printf("O ponto não está na curva!\n");
                break;
            }
        }
    }
    
    return 0;
}