# 🎮 Projeto WAR Estruturado em C

## 📘 Descrição

Este projeto tem como objetivo aplicar conceitos fundamentais de **Estruturas de Dados**, **Ponteiros**, **Alocação Dinâmica de Memória** e **Modularização** na linguagem **C**, por meio da construção da base lógica do jogo **WAR**.

A proposta é simular as funcionalidades do clássico jogo de estratégia, implementando desde o **cadastro de territórios** até as **missões estratégicas**, utilizando boas práticas de programação estruturada.

---

## 🎯 Objetivos do Projeto

* Implementar **estruturas de dados** utilizando `struct` para representar territórios.
* Simular **ataques entre territórios** com ponteiros e alocação dinâmica.
* Criar o sistema de **missões estratégicas** e **condições de vitória**.
* Aplicar **modularização** com separação do código em funções e arquivos `.h`.
* Consolidar o uso de **passagem de parâmetros por valor e referência**.

---

## 🧩 Estrutura do Projeto

O desenvolvimento é dividido em **três níveis de desafio**:

### 🥉 Nível Novato

* Criar uma `struct Territorio` com:

  ```c
  struct Territorio {
      char nome[30];
      char cor[10];
      int tropas;
  };
  ```
* Permitir o **cadastro e exibição de 5 territórios**.
* Foco: **Vetores de structs**, **entrada de dados via terminal**, **exibição organizada**.

### 🥈 Nível Aventureiro

* Implementar a **lógica de ataque** entre territórios:

  * Uso de `malloc`, `calloc` e `free` para alocação dinâmica.
  * Função `void atacar(Territorio* atacante, Territorio* defensor)` que simula uma batalha com números aleatórios (`rand()`).
  * Atualização da cor e das tropas conforme o resultado.
* Foco: **Ponteiros, alocação dinâmica e modularização**.

### 🥇 Nível Mestre

* Implementar o sistema de **missões estratégicas** com sorteio automático:

  * Uso de **vetor de strings** para armazenar as missões.
  * Função `atribuirMissao()` para definir a missão de cada jogador.
  * Função `verificarMissao()` para checar condições de vitória.
* Foco: **Modularização**, **passagem por valor e referência** e **gerenciamento de memória**.

---

## 🧠 Conceitos Aplicados

* **Structs e Encapsulamento de Dados**
* **Vetores e Listas Lineares**
* **Ponteiros e Endereços de Memória**
* **Funções malloc(), calloc() e free()**
* **Passagem de Parâmetros por Valor e Referência**
* **Modularização e Arquivos .h**

---

## ⚙️ Tecnologias Utilizadas

* Linguagem: **C**
* Compilador: **GCC**
* Bibliotecas:

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  ```

---


