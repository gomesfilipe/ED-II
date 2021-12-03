# Algoritmos de Ordenação

Nestes arquivos implementei diversos algoritmos de ordenação para fins de estudo. Neste documento serão explicados de modo bem sucinto o princípio que cada método de ordenação segue.

## Bubble Sort
Seu funcionamento se baseia em percorrer o vetor várias vezes, sempre analisando elementos adjacentes. Caso o elemento da posição i seja maior que o da posição (i + 1), eles são trocados de posição. Isso garante que a cada varrida no vetor o maior elemento vá para a última posição, assim organizando os elementos.

![gifs/bubble_sort.gif](gifs/bubble_sort.gif)

## Selection Sort
Assim como o Bubble Sort, o Selection Sort também percorre o vetor várias vezes. A cada varrida, o algoritmo procura o menor elemento para movê-lo para o início da lista.

![gifs/selection_sort.gif](gifs/selection_sort.gif)

## Insertion Sort

O Insertion Sort toma como base um elemento pivô numa determinada posição i. À esquerda dele, os elementos estarão ordenados, e a direita não. O pivô, então, é colocado na sua devida posição nesse subvetor ordenado e a posição (i + 1) se tornará pivô. O processo começa com i = 1 e termina no final da lista.

![gifs/insertion_sort.gif](gifs/insertion_sort.gif)

## Shell Sort

## Quick Sort

O Quick Sort escolhe um elemento pivô arbitrário do vetor. Em seguida, o percorre organizando de modo que os elementos menores que o pivô estejam a sua esquerda e os elementos maiores ou iguais que o pivô estejam a sua direita. Dai o algoritmo é chamado recursivamente para cada uma das partes, até que cada subvetor tenha tamanho 1, e enfim, esteja ordenado.

![gifs/quick_sort.gif](gifs/quick_sort.gif)

# Complexidade

Algoritmo | Melhor Caso | Pior Caso | Caso Médio
--- | --- | --- | ---
Bubble Sort | O(n) | O(n²) | O(n²)
Selection Sort | O(n²)| O(n²) | O(n²)
Insertion Sort | O(n) | O(n²) | O(n²)
Shell Sort | | |
Quick Sort | O(n * lgn)| O(n²) | O(n * lgn)
