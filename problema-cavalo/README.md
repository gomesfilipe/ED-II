# Passeio do cavalo no tabuleiro de xadrez

Nestes arquivos escrevi um código que resolve este problema, que tem o seguinte enunciado:
```
Dado um tabuleiro com n × n posições, o cavalo movimenta-se segundo as regras do xadrez. A partir de uma posição 
inicial (x0, y0), o problema consiste em encontrar, se existir, um passeio do cavalo com (n² − 1) movimentos, 
tal que todos os pontos do tabuleiro são visitados uma única vez.
```
O paradigma para resolver este desafio foi o de tentativa e erro. O programa faz uma busca em profundidade
analisando todas as possibilidades de caminhos do cavalo, até encontrar uma solução correta. 

Como o cavalo possui 8 opções de movimentos, cada nó árvore de subtarefas pode possuir até 8 filhos. Então,  dependendo do tamanho do tabuleiro o algoritmo pode demorar um pouco para finalizar, pois ele possui complexidade de tempo exponencial.

O problema propõe um tabuleiro com n x n posições,  forçando necessariamente ser um quadrado. Contudo, minha solução também funciona para tabuleiros retangulares.

## Compilação

Para compilar os arquivos, coloque todos os arquivos numa mesma pasta e digite o seguinte comando no terminal:

```bash
> gcc *.c -o main
```

Será gerado um arquivo executável nomeado *main*.

## Input

Os dados de entrada devem ser passados na linha de comando, da seguinte maneira:

```bash
> ./main (QTD_LINHAS_TABULEIRO) (QTD_COLUNAS_TABULEIRO) (LINHA_INICIAL_CAVALO) (COLUNA_INICIAL_CAVALO)
```

Exemplo com Tabuleiro 8x8 e cavalo iniciando na posição (0;0): 

```bash
> ./main  8 8 0 0
```

## Output

Caso haja solução, a matriz marcando a ordem das visitas do cavalo no tabuleiro será impressa na tela.
Caso contrário, a mensagem *"No solution."* será mostrada para o usuário.

## Exemplos de soluções

### Tabuleiro 5x4 com cavalo iniciando na posição (0;0)
```
01 06 13 18
12 17 10 05
07 02 19 14
16 11 04 09
03 08 15 20
```


### Tabuleiro 8x8 com cavalo iniciando na posição (0;0)
```
01 30 07 32 15 34 51 38
08 21 14 23 52 37 54 35
29 02 31 06 33 16 39 50
20 09 22 13 24 53 36 55
03 28 05 60 17 56 49 40
10 19 12 25 42 61 46 57
27 04 63 18 59 44 41 48
64 11 26 43 62 47 58 45
```

### Tabuleiro 4x4 com cavalo iniciando na posição (2;3)
```
No solution.
```
