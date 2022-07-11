#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct endereco {
  char logradouro[50];
  char numero[50];
  char condominio[50];
  char cep[50];
  char bairro[50];
} Endereco;

typedef struct quantidades {
  int blocos;
  int andares;
  int aptos_andar;
} Quantidades;


void apresentacao(){
  printf("\n====== CADCOM - CADASTRO DE ENDEREÇOS DE CONDOMÍNIOS ======\n\nDigite os dados do condomínio, conforme o exemplo a seguir: \n\n>> Logradouro: Avenida Vieira da Silva\n>> Número (caso não tenha, digite SN): 1002\n>> Nome do condomínio: Residencial Jardins\n>> CEP: 65000-000\n>> Bairro: Barramar\n>> Quantidade de blocos: 12\n>> Número de andares por bloco (incluindo o térreo): 14\n>> Quantidade de apartamentos por andar: 2\n\n==========================================================\n==========================================================\n\n");
}


Endereco *novo(){

  Endereco *endereco;
  endereco = malloc(sizeof(Endereco));

  printf("================= DADOS DO ENDEREÇO ================= \n\n");

  printf(">> Logradouro: ");
  fgets(endereco->logradouro, 50, stdin);
  printf(">> Número (caso não tenha, digite SN): ");
  fgets(endereco->numero, 50, stdin);
  printf(">> Nome do condomínio: ");
  fgets(endereco->condominio, 50, stdin);
  printf(">> CEP: ");
  fgets(endereco->cep, 50, stdin);
  printf(">> Bairro: ");
  fgets(endereco->bairro, 50, stdin);

  return endereco;
}


Quantidades *q (){
  
  Quantidades *quantidade;
  quantidade = malloc(sizeof(Quantidades));

  printf("\n==================== QUANTIDADES ==================== \n\n");
  printf(">> Quantidade de blocos: ");
  scanf("%d", &quantidade->blocos);
  printf(">> Número de andares por bloco (incluindo o térreo): ");
  scanf("%d", &quantidade->andares);
  printf(">> Quantidade de apartamentos por andar: ");
  scanf("%d", &quantidade->aptos_andar);

  return quantidade;
  
}


void imprimir(Endereco *endereco, Quantidades *quantidade) {
  int total, opcao, cont=1;
  total = quantidade->blocos*quantidade->andares*quantidade->aptos_andar;


  printf("\n\nForam gerados %d endereços.\n", total);
  printf("Digite 1 para vizualizar todos os endereços ");
  scanf("%d", &opcao);
  if (opcao == 1){
    for (int i = 1; i <= quantidade->blocos; i++) {
    printf("\nENDEREÇOS DO BLOCO %d=============================================\n\n", i);
      for (int j = 0; j < quantidade->andares; j++) {
        for (int k = 1; k <= quantidade->aptos_andar; k++) {
          printf("Endereço %d\n", cont);
          printf("%snº %sbloco %d, apartamento %d\nCondomínio %s%sCEP: %s\n",  endereco->logradouro, endereco->numero, i, j * 100 + k, endereco->condominio, endereco->bairro, endereco->cep);
          cont++;
        }
      }
    }
  }
}


int main(void) {
  
  apresentacao();
  int opcao;
  printf("Iniciar cadastro\n\n");
  Endereco *enderecos;
  Quantidades *quantidade;
  enderecos = novo();
  quantidade = q();
  imprimir(enderecos, quantidade);
  
  return 0;
}