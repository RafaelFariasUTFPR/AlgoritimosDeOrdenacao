# AlgoritimosDeOrdenacao
![algoritimos](https://user-images.githubusercontent.com/107453198/196068516-fefa1db4-c484-41c3-9f7f-473f5c1034ab.jpg)

## O que é?

Este projeto é uma visualização gráfica de alguns algoritimos de ordenação.

## Tecnologias

Esta aplicação foi escrita na linguagem C++, e fez uso da biblioteca gráfica [SFML](https://www.sfml-dev.org/) e da biblioteca de interface gráfica [ImGui](https://github.com/ocornut/imgui).

Existem duas formas de processamento
* Visual: 
  * O processamento ocorre em um thread separado, permitindo que o usuário veja de maneira gráfica a execução do algoritimo;
  * Pode-se controlar o **PPS** (passos por segundo), este permite alterar a velocidade de execução do algoritimo.

* Não visual:
  * Um *benchmark* real da performance do algoritimo;
  * A execução é realizada no thread principal.

## Como instalar?

Instale toda a pasta ```bin``` [aqui](https://github.com/RafaelFariasUTFPR/AlgoritimosDeOrdenacao/tree/master/bin), este contem os arquivos binários, dlls e outros recursos, após isso basta executar o arquivo ```AlgoritimosDeOrdenacao.exe```.
