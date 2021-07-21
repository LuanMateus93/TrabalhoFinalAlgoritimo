#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
  float pontoX, pontoY;
}Ponto;

Ponto geraPonto(){
    Ponto p;                          //Converter pra double pra ter uma precisão maior
    p.pontoX= (double)rand()/RAND_MAX;//pega o maior valor possível a ser gerado pelo rand
    p.pontoY= (double)rand()/RAND_MAX;//divisão rand/randMax gerar um valor entre 0 e 1
    return p;
}

float CalculaPosicao(Ponto localizacaoPonto){
  float d= sqrt(pow(localizacaoPonto.pontoX-0.5,2)+pow(localizacaoPonto.pontoY-0.5,2));
  if (d < 0.5){
    return 1;
  }
  return 0;
}

int main() {
  
  float NumeroPontosQuadrado= 1070000;
  float NumeroPontosCirculo= 0;
  float pi;

  int acumulador=1;

  while (acumulador <= NumeroPontosQuadrado){
    Ponto p=geraPonto();
    NumeroPontosCirculo+=CalculaPosicao(p);
    
    acumulador ++;
  }
  
  pi=4*(NumeroPontosCirculo/NumeroPontosQuadrado);
  printf("%1.4f", pi);
    
  return 0;
} 