#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1e+6 + 10;
const int MAXN = 1e+2 + 10;
const int INF = 1e+9 + 7;
const int MOD = 1e+9 + 7;

int dp[MAXN][MAXX];
int vec[MAXN];

int n, x;

/* Conversão DP top-down => DP bottom up
//1º passo - construir casos bases <=> base da recursão
//2º passo - definir ordem para calcular estados <=> ordem que vai percorrer a matriz
//(dica: se estiver difícil, desenha uma tabela, e faz setinha pra representar as dependências do que tem que estar calculado antes)
//3º passo - copia e cola as transições do top-down pro bottom-up
//4º passo - troca chamada recursiva pelo acesso do estado na tabela
//5º passo - guardar a resposta calculada
//
//Vantagens:
//Amigável à otimizações (transparente, tem a visão do todo)
//Sem overhead de trocad de context de funções (geralmente mais rápido)
//Consome menos memória (não usa a stack)
//
//Desvatagens:
//Calcula todos os estados (mas na prática ainda é mais rápido que top down na maioria dos problemas)
//Menos intuitivo (dica: não tentar entender soluções a partir de DP bottom-up)
//
*/

int solve(int sum, int i){
    if(i == n){
        return sum == 0;
    }
    if(dp[sum][i] != -1){
        return dp[sum][i];
    }

    dp[sum][i] = 0;
    
    if(sum - vec[i] >= 0){
        dp[sum][i] = solve(sum - vec[i], i) % MOD;
    }
    dp[sum][i] += solve(sum, i+1) % MOD;

    return dp[sum][i];
}


void solve_mesmo(int x){
    dp[n][0] = 1;
    for(int sum = 1; sum<=x; sum++) dp[n][sum] = 0;
    
    for(int sum = 0; sum <= x; sum++){
        for(int i = n-1; i>=0; i--){     
            if(sum - vec[i] >= 0){
                dp[i][sum] = dp[i][sum - vec[i]];
            }
            dp[i][sum] += dp[i+1][sum];
            dp[i][sum] %= MOD;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>x;

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    
    
    int ans = 0;
    solve_mesmo(x);
    ans = dp[0][x];
    cout<<ans<<"\n";


    return 0;
}
