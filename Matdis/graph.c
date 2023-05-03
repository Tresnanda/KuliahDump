#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int hm[20];
int deg[20];
int cek_terhubung(int n);
int warna[20];
int matrix[20][20];
int euler[20][20];
int semi[20][20];
int vis[20];
int ver_terhubung(int vertex1, int vertex2){
    return matrix[vertex1][vertex2] == 1;
    }
void terhubung(int v, int n){
    hm[v] = 1;
    for(int i=1; i<=n; i++){
        if(matrix[v][i] == 1 && hm[i] == 0){
            terhubung(i, n);
        }
    }
}

/**void jalan_euler(int v, int n){
    printf("%d, ", v);
    for(int i=1; i<=n; i++){
        if(euler[v][i] == 1){
            euler[v][i] = euler[i][v] = 0;
            jalan_euler(i, n);
            
        }
    }
}
/**void jalan_euler(int v, int n){
    //printf("%d, ", v);
    for(int i=1; i<=n; i++){
        for(int k=i+1; k<=n; k++){
            if()
        }
    }
}**/

void euler2(int n, int start) {
    int stack[20];
    int top = 0;
    int visited[20];
    int count = 0;
    stack[top] = start;
    while (top >= 0) {
        int v = stack[top];
        int found = 0;
        for (int i = 1; i <= n; i++) {
            if (euler[v][i]) {
                stack[++top] = i;
                euler[v][i] = euler[i][v] = 0;
                found = 1;
                break;
            }
        }
        if (!found) {
            visited[count++] = v;
            top--;
        }
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", visited[i]);
    }
}

void jalan_ha(int a){
    int queue[a], head = 0, tail=0;
    int ha[20];
    for(int i=1; i<=a; i++){
        ha[i] = 0;
    }
    
    queue[tail] = 1;
    tail++;
    while(head!=tail){
        int v = queue[head];
        head++;
        ha[v] = 1;
        for(int i=1; i<=a; i++){
            if(matrix[v][i] == 1 && ha[i] == 0){
                queue[tail] = i;
                tail++;
                break;
            }
        }
    }

    if(matrix[queue[a-1]][queue[0]] == 1){
        for(int i=1; i<=a; i++){
        if(ha[i] == 0){
            printf("Graf bukan hamilton2! \n");
            return;
        }
      }
    printf("Graf adalah hamilton! \n");
    printf("Jalan hamilton: \n");
    for(int i=0; i<a; i++){
        printf("%d ", queue[i]);
      }
      printf("%d ", queue[0]);
    }
    else{
        for(int i=1; i<=a; i++){
        if(ha[i] == 0){
            printf("Graf bukan hamilton2! \n");
            return;
        }
      }
      printf("Graf adalah semi-hamilton! \n");
      printf("Jalan hamilton: \n");
      for(int i=0; i<a; i++){
        printf("%d ", queue[i]);
      }
        
    }
      
}

int cek_terhubung(int n){
    terhubung(1, n);
    for(int i=1; i<=n; i++){
        if(hm[i] == 0){
            return 0;
        }
    }
    return 1;
}

void urut(int n, int diurut[]) {
    for (int i = 0; i < n; i++) {  //membuat array baru yang berisi vertex-vertex pada graf
        diurut[i] = i+1;
    }
    for (int i = 0; i < n; i++) { //mengurut dari yang terbesar
        for (int j = i+1; j < n; j++) {
            if (deg[diurut[i]] < deg[diurut[j]]) {
                int temp = diurut[i];
                diurut[i] = diurut[j];
                diurut[j] = temp;
            }
        }
    }
}

void pewarnaan(int n) {
    int jml_warna = 0;
    int warnatemp[20];
    int terurut[20];
    for (int i = 1; i <= n; i++) {
        warna[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        warnatemp[i] = -1;
    }
    urut(n, terurut);
    for (int i = 0; i < n; i++) {
        int vertex = terurut[i];
        if (warna[vertex] == -1) {
            jml_warna++;
            warna[vertex] = jml_warna;
            for (int j = i + 1; j < n; j++) {
                int vertex2 = terurut[j];
                if (warna[vertex2] == -1 && matrix[vertex][vertex2] == 0) {
                    warnatemp[vertex2] = jml_warna;
                    for(int k=0; k<n; k++){
                        int vertex3 = terurut[k];
                        if(matrix[vertex2][vertex3] == 1){
                            if(jml_warna == warna[vertex3]){
                                //jml_warna++;
                            warnatemp[vertex2]++;
                            warna[vertex2] = warnatemp[vertex2];
                            //warna[vertex2] = jml_warna;

                     }
                    else{
                        warna[vertex2] = warnatemp[vertex2];
                    }
                        }
                    }
                }
            }
        }
    }
    printf("Jumlah warna yang digunakan: %d\n", jml_warna);
    printf("Pewarnaan tiap vertex: \n");
    for (int i = 1; i <= n; i++) {
        printf("Vertex %d: Warna %d\n", i, warna[i]);
    }
}

void cek_euler(int n){
    int odd = 0;
    if(cek_terhubung(n) == 0){
        printf("Graf bukanlah graf euler1!\n");
        return;
    }
    for(int i=1; i<=n; i++){
        if(deg[i]%2 == 1){
            odd++;
        }
    }
    if(odd == 2){
        printf("Graf adalah semi-euler!\n");
        //printf("Jalan euler's path: \n");
        //semi_euler(n, 1);
        printf("\n");
        return;
    }
    else if(odd != 0){
        printf("Graf bukanlah graf euler2!\n");
        return;
    }
    printf("Jalan yang dilalui pengecekan Euler's Cycle: \n");
    euler2(n, 1);
    //jalan_euler(1, n);
    printf("\n");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(euler[i][j] == 1){
                printf("Graf bukanlah graf euler3!\n");
                return;
            }
        }
    }
    printf("Graf adalah graf euler!\n");
}

int main()
{
    char c;
    int baris;
    int edge;
    printf("Jumlah vertex pada graf: ");
    scanf("%d", &baris);
    printf("Jumlah edge pada graf: ");
    scanf("%d", &edge);
    //int matrix[baris+1][baris+1];

    for (int i = 1; i <= baris; i++) { ////membuat semua edge memiliki nilai 0 secara default
        for (int j = 1; j <= baris; j++) {
            matrix[i][j] = 0;
            
        }
    }
    printf("Dua buah vertex yang saling terhubung: \n");
    for(int i=1; i<=edge; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
        euler[a][b] = 1;
        euler[b][a] = 1;
        semi[a][b] = 1;
        semi[b][a] = 1;
    }

    printf("\n");
    for(int i = 1; i <= baris; i++) {
        for(int j = 1; j <= baris; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
     printf("Derajat dari setiap vertex adalah: \n");
    for (int i = 1; i <= baris; i++)
    {
        for (int j = 1; j <= baris; j++)
        {
            deg[i] += matrix[i][j];
        }
        printf("Derajat vertex %d adalah %d\n", i, deg[i]);
    }
    printf("\n");
    if(cek_terhubung(baris) == 1){
        printf("Terhubung");
    }
    else{
        printf("Tidak Terhubung");
    }
    printf("\n");
    pewarnaan(baris);
    printf("\n");
    cek_euler(baris);
    /**for(int i = 1; i <= baris; i++) {
        for(int j = 1; j <= baris; j++) {
            printf("%d ", euler[i][j]);
        }
        printf("\n");
    }**/
    jalan_ha(baris);
    return 0;
}