#include <iostream>
#include <cstring>

using namespace std;

#define MAX_L 1000000

char P[MAX_L+1];
int f[MAX_L];

void prefix(){
    int n = strlen(P), k = 0;
    f[0] = 0;
    
    for(int i = 1;i<n;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}

int main(){
    int K;
    while (true)
    {
        cin >> K;
        if(K == -1) break;
        
        cin >> P;
        prefix();

        // for (size_t i = 0; i < strlen(P); i++)
        //     cout << f[i] << " ";
        // cout << endl;
        
        int L = strlen(P), ans = 0;
        
        if(K>=L) ans = (K-f[L-1])/(L-f[L-1]);
        
        cout << ans << endl;
    }
    
    return 0;
}
