#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//constante para definir o tamanho do vetor de struct
#define TAMANHO 20 //mude aqui para alterar a quantidade dos produtos

//criando o tipo de dado PRODUTO que contém os atributos nome, id, estado do produto, custo de manutenção e eficiência
typedef struct
{
  char nome[50];
  int id;
  char estadoProduto;
  float custoManutencao;
  int eficiencia;
} PRODUTO[TAMANHO];

//declaração das funçõoes
void IrParaProximaFuncionalidade();
void CadastrarProdutos(PRODUTO *p);
void PesquisarProduto(PRODUTO *p);
void OrdenarProdutos(PRODUTO *p);
void ExibirProdutos(PRODUTO p);

//função principal
int main(void)
{
  PRODUTO produto; //declaração da variável "produto" do tipo produto.

  printf("\tHOSPITAL PROD VERSÃO 2.0\n");
  //chamada das funções
  CadastrarProdutos(&produto);

  IrParaProximaFuncionalidade();

  PesquisarProduto(&produto);

  IrParaProximaFuncionalidade();

  OrdenarProdutos(&produto);

  ExibirProdutos(produto);

  return 0;
}

//A função IrParaProximaFuncionalidade" basicamente é uma estrutura de repetição onde se o mesmo digitar 1, dará prosseguimento à próxima funcionalidade do programa.
void IrParaProximaFuncionalidade()
{
  int escolha = -100;
  while (escolha != 1)
  {
    printf("Digite 1 para ir para próxima funcionalidade: ");
    scanf("%d", &escolha);
  }
}
//A função "CadastrarProdutos" agora é uma função que recebe como parâmetro um ponteiro p do tipo PRODUTO.
//Desse modo, ocorre uma passagem de parâmetro por referência, permitindo alterar os valores da variável fora da função "CadastrarProdutos".
//Finalmente, seu objetivo é preencher a struct com os dados inseridos pelo usuário.
void CadastrarProdutos(PRODUTO *p)
{
  int i;
  printf("--------------CADASTRAR--------------\n");

  for (i = 0; i < TAMANHO; i++)
  {
    //o ponteiro p está apontando para o elemento cada elemento na posição i que está contido na struct, acessando-o e definindo o valor digitado pelo usuário.
    printf("Produto %d\n", i + 1);
    printf("Insira o nome do produto: ");
    scanf("%s", (*p)[i].nome);
    printf("Insira o id do produto: ");
    scanf("%d", &(*p)[i].id);
    printf("Insira o estado do produto [n(novo) e a(antigo)]: ");
    scanf(" %c", &(*p)[i].estadoProduto);
    printf("Insira o custo de manutenção do produto: ");
    scanf("%f", &(*p)[i].custoManutencao);
    printf("Insira o valor da eficiência: ");
    scanf("%d", &(*p)[i].eficiencia);
    printf("\n-------------------------------------\n");
  }
}
//Apesar de ser um local diferente, a lógica do uso dos ponteiros é a mesma da função anterior.
//Na função "PesquisarProduto" o usuário poderá efetuar uma busca baseada no atributo id. Caso o valor inserido pelo mesmo não estiver cadastrado, exibirá uma mensagem de erro. Recebe como referência o ponteiro p.
void PesquisarProduto(PRODUTO *p)
{
  printf("--------------PESQUISAR--------------\n");
  int quantidadeEncontrada = 0; //variável para registrar a quantidade de ID'S encontrados no vetor, baseado no input do usuário.
  while (quantidadeEncontrada == 0)
  {
    int inputUsuario; //variável inteira que armazenará o ID informado pelo usuário
    int j;            //variável contadora

    //Solicitando a entrada do usuário
    printf("Digite o id que deseja encontrar: ");
    scanf("%d", &inputUsuario);

    //estrutura de repetição para percorrer o vetor de struct
    for (j = 0; j < TAMANHO; j++)
    {
      //se o ID digitado pelo usuário for igual a um ID registrado no vetor, o programa exibirá todos os atributos referentes a esse ID.
      if (inputUsuario == (*p)[j].id)
      {
        quantidadeEncontrada++;
        printf("\nPRODUTO ENCONTRADO!\n");
        printf("------------------------------\n");
        printf("Detalhes do produto:\n");
        printf("Nome: %s\n", (*p)[j].nome);
        printf("ID: %d\n", (*p)[j].id);
        printf("Estado: %c\n", (*p)[j].estadoProduto);
        printf("Preco de Manutencao: R$%.2f\n", (*p)[j].custoManutencao);
        printf("Eficiencia: %d%%\n", (*p)[j].eficiencia);
        printf("------------------------------\n");
      }
    }
    if (quantidadeEncontrada == 0)
    {
      printf("Nao foi encontrado nenhum produto registrado com esse ID.\n");
    }
  }
}
//Função OrdernarProdutos: Recebe como parâmetro um ponteiro de struct e ordena os produtos baseados no atributo ID. Além de ordenar os ID's registrados, altera as posições dos atributos (nome, estado do produto, custo de manutenção e eficiência) para exibi-los de forma ordenada por completo na função ExibirProdutos.
void OrdenarProdutos(PRODUTO *p)
{
  //algoritmo bubble sort para ordenar os produtos por ordem crescente do atributo id!
  int i, j;

  char auxNome[50];
  int auxId;
  char auxEstado;
  float auxCustoManutencao;
  int auxEficiencia;

  //inicio do algoritmo bubble sort
  for (i = 1; i < TAMANHO; i++)
  {
    for (j = 0; j < TAMANHO - i; j++)
    {
      if ((*p)[j].id > (*p)[j + 1].id)
      {
        //cada ponteiro nessa função está apontando para um atributo na struct referenciada na função principal, podendo assim, alterar o valor da variável "produto" fora da função OrdenarProduto.
        //trocando nome
        strcpy(auxNome, (*p)[j].nome);
        strcpy((*p)[j].nome, (*p)[j + 1].nome);
        strcpy((*p)[j + 1].nome, auxNome);
        //trocando id
        auxId = (*p)[j].id;
        (*p)[j].id = (*p)[j + 1].id;
        (*p)[j + 1].id = auxId;
        //trocando estado do produto
        auxEstado = (*p)[j].estadoProduto;
        (*p)[j].estadoProduto = (*p)[j + 1].estadoProduto;
        (*p)[j + 1].estadoProduto = auxEstado;
        //trocando custo de manutenção
        auxCustoManutencao = (*p)[j].custoManutencao;
        (*p)[j].custoManutencao = (*p)[j + 1].custoManutencao;
        (*p)[j + 1].custoManutencao = auxCustoManutencao;
        //trocando eficiencia em porcentagem
        auxEficiencia = (*p)[j].eficiencia;
        (*p)[j].eficiencia = (*p)[j + 1].eficiencia;
        (*p)[j + 1].eficiencia = auxEficiencia;
      }
    }
  }
  printf("ORDENAÇÃO REALIZADA COM SUCESSO!\n");
}
//Função exibir produtos: Imprime os atributos da Struct ordenados por id na tela.
void ExibirProdutos(PRODUTO p)
{
  int j;
  printf("--------------PRODUTOS ORDENADOS POR ID--------------\n");
  for (j = 0; j < TAMANHO; j++)
  {
    printf("------------------------------\n");
    printf("Nome: %s\n", p[j].nome);
    printf("ID: %d\n", p[j].id);
    printf("Estado do produto: %c\n", p[j].estadoProduto);
    printf("Custo de manutenção: %.2f\n", p[j].custoManutencao);
    printf("Eficiência: %d\n", p[j].eficiencia);
  }
}
