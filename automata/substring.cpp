#include <iostream>
using namespace std;


void crear_matriz(string texto, int size, int matrix[]){ 

    matrix[0] = 0;  
    int len = 0; 
    int i = 1; 
    while (i<size and len<size){ 
        if (texto[i] == texto[len]) { 
            len++; 
            matrix[i] = len; 
            i++; 
        }else{ 

            if (len != 0) { 
                len = matrix[len - 1]; 
  

            }else{ 
                matrix[i] = 0; 
                i++; 
            } 
        } 
    }
    
} 





void morris(string cadena_grad, string cadena_peque) 
{ 
    int size_grand = cadena_grad.length(); 

    int size_peque = cadena_peque.length(); 
    int matriz[size_peque];
    crear_matriz(cadena_peque,size_peque,matriz);
    /*  for(int i=0;i<size_peque;i++){
        cout<<matriz[i]<<endl;
      }
*/
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < size_grand) { 
        if (cadena_peque[j] == cadena_grad[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == size_peque) { 
            printf("Found pattern at index %d ", i - j); 
            j = matriz[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < size_grand && cadena_peque[j] != cadena_grad[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = matriz[j - 1]; 
            else
                i = i + 1; 
        } 
    }
} 

int main(){
	string texto_1 = "gaperrogatogato"; 
    string texto_2 = "gatogato"; 
    morris(texto_1, texto_2); 
	return 0;
}