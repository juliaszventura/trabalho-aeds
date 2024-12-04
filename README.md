# Trabalho AEDS-1 - Companhia Aérea Voo Seguro

## Projeto
A Voo Seguro é uma companhia aérea operante em todo o Brasil, cujo maior objetivo é garantir a satisfação de seus passageiros e promover sua fidelização, contando com uma equipe
de tripulação composta por pilotos, copilotos e comissários. Entretanto, mesmo hoje em dia, o controle de voos, reservas e tripulação da Companhia ainda é realizado em planilhas e cadernos, o que tem desencadeado diversos problemas, como reservas duplicadas e falta de controle sobre a disponibilidade de voos e assentos. Tendo em vista estas ocorrências, este projeto é um sistema simples de gerenciamento de voos em C. 

## Bibliotecas Utilizadas
- _stdio.h_: Biblioteca padrão da linguagem c, fornece funções que executam a entrada e saída de dados no sistema, como o scanf e printf, e manipulação de dados em arquivo.
- _stdlib.h_: Fornece funções empregadas para o controle de fluxo e término do software, manipulação de números e strings e gerenciamento de memória. 
- _string.h_: Biblioteca utilizada para a manipulação de strings (conjuntos de caracteres).
- _assert.h_: Biblioteca que permite a verificação de condições durante a execução de um programa. Usada para a manipulação dos casos de teste implementados para o sistema, auxiliando na validação dos testes. 

## Estruturas de Dados
- **typedef struct Passageiros**: Utilizada para armazenamento dos dados dos passageiros da companhia Voo Seguro: código, nome, endereço, telefone, e se participa do Programa Fidelidade da Companhia, indicando o número de pontos.
- **typedef struct Tripulação**: Utilizada para o armazenamento dos dados dos tripulantes da companhia Voo Seguro: código do tripulante, nome, telefone e cargo(piloto, copiloto ou comissário).
- **typedef struct Voo**: Armazena as informações dos voos da companhia: código do voo, data e hora, origem, destino, código do avião, tarifa do voo e código do piloto, copiloto e comissários do voo.
- **typedef struct Assento**: Armazena os dados dos assentos dos voos: código do voo em que o assento está, número do assento e status (livre ou ocupado).
- **typedef struct Reserva**: Armazena as informações referentes à uma reserva: número do assento reservado, código do voo em que o assento se encontra e código do passageiro que realizou a reserva.


##Funções Utilizadas: 
- ** void CadastrarPassageiro(Passageiro passageiros[], int *qtdPassageiros, 

