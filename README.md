# Trabalho AEDS-1 - Companhia Aérea Voo Seguro

## Projeto
A Voo Seguro é uma companhia aérea operante em todo o Brasil, cujo maior objetivo é garantir a satisfação de seus passageiros e promover sua fidelização, contando com uma equipe
de tripulação composta por pilotos, copilotos e comissários. Este projeto é um sistema desenvolvido em linguagem C a fim de auxiliar a companhia Voo Seguro no gerenciamento, possibilitando o cadastro de passageiros, tripulação e voos da companhia e controle de reservas de assentos e Sistema de Fidelidade da empresa. 


## Bibliotecas Utilizadas
- _stdio.h_: Biblioteca padrão da linguagem c, fornece funções que executam a entrada e saída de dados no sistema, como o scanf e printf, e manipulação de dados em arquivo.
- _stdlib.h_: Fornece funções empregadas para o controle de fluxo e término do software, manipulação de números e strings e gerenciamento de memória. 
- _string.h_: Biblioteca utilizada para a manipulação de strings (conjuntos de caracteres).
- _assert.h_: Biblioteca que permite a verificação de condições durante a execução de um programa. Usada para a manipulação dos casos de teste implementados para o sistema, auxiliando na validação dos testes. 


## Estruturas de Dados
- **typedef struct Passageiros**: Utilizada para armazenamento dos dados dos passageiros da companhia Voo Seguro: código, nome, endereço, telefone, e se participa do Programa Fidelidade da Companhia, indicando o número de pontos.
- **typedef struct Tripulação**: Utilizada para o armazenamento dos dados dos tripulantes da companhia: código do tripulante, nome, telefone e cargo (piloto, copiloto ou comissário).
- **typedef struct Voo**: Armazena as informações dos voos da companhia: código do voo, data e hora, origem, destino, código do avião, tarifa do voo e código do piloto, copiloto e comissários do voo.
- **typedef struct Assento**: Armazena os dados dos assentos dos voos: código do voo em que o assento está, número do assento e status (livre ou ocupado).
- **typedef struct Reserva**: Armazena as informações referentes à uma reserva: número do assento reservado, código do voo em que o assento se encontra e código do passageiro que realizou a reserva.


## Funções Utilizadas: 
- **void CadastrarPassageiro(Passageiro passageiros[], int * qtdPassageiros,)** : Empregada para inclusão de um novo passageiro dentro de um sistema de gerenciamento. Recebe como parâmatros um vetor 'passageiros' do tipo Passageiro e um ponteiro int que indica a quantidade de passageiros cadastrados no sistema (*qtdPassageiros). Cria uma estrutura 'novoPassageiro' do tipo Passageiro, e atribui um código identificador único a ele. Em seguida, solicita ao usuário que digite o nome, endereço e telefone do passageiro que deseja cadastrar, e  armazena os dados recebidos dentro do 'novoPassageiro' recém criado. Por fim, solicita que o usuário indique se o passageiro cadastrado faz parte do Programa Fidelidade da companhia (teclando 1 caso participe, e 2 caso não participe), e armazena esta informação em 'novoPassageiro'. Após a coleta e armazenamento dos dados, armazena 'novoPassageiro' dentro do vetor passageiros na posição indicada por qtdPassageiros, e incrementa o valor desse contador. Por fim, fornece uma mensagem ao usuário indicando que o cadastro do passageiro foi concluido com sucesso e o código do passageiro cadastrado.
  
  
- **void cadastrarTripulacao (Tripulacao tripulantes [], int * qtdTripulantes)** : Empregada para incluir um novo membro ao sistema de gerenciamento da tripulação da companhia aérea. Recebe como parâmetros um vetor tripulantes do tipo Tripulação e um ponteiro int que sinaliza o valor de tripulantes cadastrados (**qtdTripulantes**). Cria uma estrutura 'novoTripulante' do tipo Tripulante, e atribui um código identificador único a ela. Solicita que o usuário insira o nome, telefone e selecione o cargo do tripulante que deseja cadastrar(piloto, copiloto ou comissário), de acordo com as opções númericas fornecidas (1, 2 e 3). Verifica se o valor digitado corresponde a um destes três valores numéricos: em caso negativo, gera uma mensagem ao usuário informando que o cargo digitado por ele é inválido, e a operação de cadastro não é finalizada, retornando ao menu inicial. Em caso positivo, o 'novoTripulante' é adicionado ao vetor tripulantes, o contador qtdTripulantes é incrementado e exibe-se uma mensagem ao usuário sinalizando que o cadastro foi concluido e o código do tripulante recém cadastrado.

- **void cadastrarVoo (Voo voos[], int * qtdVoos, Tripulacao tripulantes[], int qtdTripulantes)** : Empregada para cadastro de um novo voo ao sistema de gerenciamento. Recebe como parâmetros um vetor voos do tipo Voo, um ponteiro do tipo int que indica a quantidade de voos cadastrados no sistema (qtdTripulantes), um vetor tripulantes do tipo Tripulacao e um ponteiro int que indica a quantidade de tripulantes cadastrados no sistema (qtdTripulantes). Cria uma estrutura 'novoVoo' do tipo Voo, e atribui um código identificador único a ela. Solicita que o usuário insira a data, hora, origem, destino, código do avião, tarifa do voo, o código do piloto, copiloto e do comissário e o status do voo (1 para ativo e 0 para inativo.). Testa se os códigos de piloto, copiloto e comissario fornecidos correspondem a algum código armazenado no vetor Tripulantes, e em caso negativo, fornece ao usuário uma mensagem de erro e não finaliza o cadastro do voo, retornando ao menu inicial. Em caso positivo, armazena o novoVoo no vetor voos e incrementa o contador qtdVoos, exibindo ao usuário uma mensagem de cadastro concluido com sucesso e indicando o código do novo voo cadastrado.

- **void cadastrarAssento(Assento assentos[], int * qtdAssentos, Voo voos[], int qtdVoos)** : Empregada no cadastro de um novo assento em um voo. Recebe como parâmetros um vetor de assentos, um ponteiro para a quantidade de assentos cadastrados, um vetor de voos e a quantidade de voos cadastrados.Solicita ao usuário o código do voo e inicializa o status do assento como 0 (vazio).
Em seguida, a função verifica se o código do voo informado corresponde a algum voo presente no vetor de voos. Caso o voo não seja encontrado, é exibida uma mensagem de erro e o cadastro do assento é interrompido, com a quantidade de assentos sendo ajustada para -1, indicando que ocorreu um erro. Se o voo for encontrado, a função cria um novo assento, atribuindo-lhe o número baseado na quantidade de assentos já cadastrados. O novo assento é então adicionado ao vetor de assentos e a quantidade de assentos qtdAssentos é incrementada.
Por fim, a função exibe uma mensagem de sucesso, informando o número do novo assento cadastrado ao usuário.

## ARQUIVOS TXT

* Os arquivos txt possuem a seguinte lógica em sua escrita:
* Passageiros: Id, Nome, Endereço, Telefone.
* Tripulantes: Id, Nome, Telefone, Cargo.
* Voos: Id, Data do voo, Hora do voo, Origem, Destino, Código do avião, Tarifa, Código do piloto, Código do copiloto, Códido do comissário, Status do voo.
* Assentos: Código do assento, Código do voo, Status do assento.


## Menu

    --------------------------
    Companhia Aérea Voo Seguro
    --------------------------
    1 - Cadastrar Passageiro
    2 - Cadastrar Tripulante
    3 - Cadastrar Voo
    4 - Cadastrar Assento
    5 - Pesquisar Passageiro
    6 - Pesquisar Tripulante
    7 - Fazer Reserva
    8 - Dar baixa em Reserva
    9 - Listar Voos do Passageiro
    0 - Salvar e Sair

* Possivel escolher e navegar pelas diferentes interfaces e funções da aplicação.


## Métodos Ágeis 

* **Scrum**: Utilizamos o framework Scrum para organizar o projeto em ciclos de aproximadamente 1 dia. Planejávamos cada ciclo (sprint), definindo seu backlog correspondente. Realizávamos daily (meetings) com duração média de 5 a 8 minutos. Ao término de cada sprint, avaliávamos o que havia sido concluído e analisávamos nosso método de trabalho para identificar oportunidades de melhoria no processo.
* **Kanban**: Utilizamos o github Projects para fazer o acompanhamento visual do projeto através do framework Kanban, onde organizamos os requisitos, o backlog do produto, backlog da sprint e separamos as tarefas da sprint no quadro *To-do, In Progress, Done*.


## Evolução das sprints

Acompanhamento da organização das sprints feita apartir do github Projects.

**Backlog Geral** <br/>
Apresentação do backlog geral, divisão das funções e divisão das tarefas para cada integrante do grupo e em cada sprint.
<br/>
<img src="sprints/Backlog.png" alt="Backlog geral"/>
**Sprint 1**
<img src="sprints/Sprint 1.png" alt="Sprint 1"/>
**Sprint 2**
<img src="sprints/Sprint 2.png" alt="Sprint 2"/>
**Sprint 3**
<img src="sprints/Sprint 3.png" alt="Sprint 3"/>
**Sprint 4**
<img src="sprints/Sprint 4.png" alt="Sprint 4"/>

## Relatório de testes

Representação dos relatórios de testes em tabelas, onde é possível ver as entradas, classes válidas, classes inválidas e os resultados esperados.

<div style="text-align: center; size: small">
    <img src="tables/cadastro p.png" alt="Teste Passageiro"/>
    <img src="tables/cadastro t.png" alt="Teste Tripulacao"/>
    <img src="tables/cadastro voo.png" alt="Teste Voo"/>
    <img src="tables/cadastro a.png" alt="Teste Assento"/>
    <img src="tables/reserva 1.png" alt="Teste Reserva"/>
    <img src="tables/reserva 2.png" alt="Teste Reserva 2"/>
    <img src="tables/menu.png" alt="Teste Menu"/>
</div>


