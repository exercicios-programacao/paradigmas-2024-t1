paradigmas-2024-t1
==================

Preparação para a execução do trabalho
--------------------------------------

Para iniciar este trabalho, faça um _fork_ do repositório 
[https://github.com/exercicios-programacao/paradigmas-2024-t1](https://github.com/exercicio-programacao/paradigmas-2024-t1)
para o seu usuário do Github.

Todo o código implementado deve estar dentro do diretório `src`. Siga as 
instruções contidas no arquivo [`INSTRUCOES.md`](INSTRUCOES.md), que contém
os objetivos e etapas para a realização do trabalho.

O arquivo [src/lista.h](src/lista.h) contém detalhes sobre as funções a
serem implementadas e sugestões para a execução do trabalho.


Dependências
------------

Você precisará dos seguintes softwares instalados:
* `make`
* `Compilador C`
* `Catch2`
* `valgrind`


Desenvolvimento
---------------

Para compilar o projeto utilize o comando `make` (ou `make -k`).

Durante o desenvolvimento do trabalho, você pode executar os testes, 
localmente, utilizando os comandos `make test` ou `make memtest`.

Para o desenvolvimento das tarefas extras, execute os testes localmente
com o comando `make test_extra`.

Para compilar um teste específico, utilize `make features/<nome_do_teste>`,
por exemplo, `make featules/ListInfo`. Para executar o teste, utiilze o
comando `featuers/<nome_do_test> --success`.

Voçê pode alterar o arquivo `src/main.c` para executar um teste rápido
ou depurar um problema de implementação. Para compilar o programa de
teste utilize o comando `make main` e um executável `main` será criado
na raiz do projeto.

Para ver detalhes da análise de memória utlize o comando
`features/util/memtest.sh -v features/<nome_do_teste>`


Entrega
-------

Para entregar o trabalho, faça commit do código, envie para o seu _fork_ no 
Github, e abra um _pull request_ contra o
[repositório original](https://github.com/exercicios-programacao/paradigmas-2024-t1).

O título do _pull request_ deve conter o nome do aluno que o está criando. 
Na mensagem deve constar o nome completo do autor do _pull request_, e de 
todos os alunos que realizaram o trabalho, no caso de trabalhos em grupo. 
Qualquer informação necessária para a entrega do trabalho deve estar 
presente no corpo dessa mensagem.

Você deve garantir que os testes executaram corretamente, pois é a partir
deles que será realizada a avaliação.


Discussões Online!
-----------------

Dúvidas e disccussões sobre o trabalho podem ser realizadas utilizando as
[discussões do Github](https://github.com/exercicio-programacao/paradigmas-2024-t1/discussions).
