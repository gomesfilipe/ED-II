#include "../include/disk_bs_tree.h"

struct tree {
    Disk* disk;
    Tree* left;
    Tree* right;
};

Tree* create_tree(Disk* disk) {
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    tree->disk = disk;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

int is_empty_tree(Tree* tree) {
    return tree == NULL;
}

int is_leaf_node(Tree* tree) {
    return is_empty_tree(tree->left) && is_empty_tree(tree->right);
}

void free_tree(Tree* tree) {
    if(!is_empty_tree(tree)) {
        free_tree(tree->left);
        free_tree(tree->right);
        free_disk(tree->disk);
        free(tree);
    }
}

void print_tree(Tree* tree) {
    printf("<");
    if(tree != NULL){
        print_disk(tree->disk);
        print_tree(tree->left);
        print_tree(tree->right);
    }
    printf(">");
}

Tree* insert_disk_in_tree(Tree* tree, Disk* disk){
    if(tree != NULL){
        if(get_freeSpace(disk) <= get_freeSpace(tree->disk)){
            tree->left = insert_disk_in_tree(tree->left, disk);
        
        } else if(get_freeSpace(disk) > get_freeSpace(tree->disk)){
            tree->right = insert_disk_in_tree(tree->right, disk);
        }

    } else{ // Arrived in a leaf node.
        tree = create_tree(disk);
    }
    return tree;
}

static void swap(Disk** a, Disk** b) {
    Disk* aux = *a;
    *a = *b;
    *b = aux;
}

void search_min_disk_in_tree(Tree* tree, File* file, Disk** min) {
    if(is_empty_tree(tree)) return;

    if(there_is_space(tree->disk, file)) { // cabe no pai, ver se cabe no left
        *min = tree->disk;
        search_min_disk_in_tree(tree->left, file, min);
    
    } else { // não cabe no pai, ver se cabe no right
        search_min_disk_in_tree(tree->right, file, min);
    }
}

Tree* remove_min_disk_in_tree(Tree* tree, int key, Disk** removed) {
    Tree* aux;
    if(is_empty_tree(tree)) return NULL;
    // printf("disco: ");
    // print_disk(tree->disk);
    // printf("freespace = %d\nkey = [%d]\n", get_freeSpace(tree->disk), key);
    if(get_freeSpace(tree->disk) == key) { // encontrou, remover!
        // printf("chegou pai\n");
        *removed = tree->disk;

        if(is_leaf_node(tree)){ // Folha.
            free(tree);
            return NULL; // Atualizando ponteiro do nó pai. 
            
        } else if(tree->left != NULL ^ tree->right != NULL){ // Somente um filho (^ é xor).
            if(tree->left != NULL){ // left é o único filho.
                aux = tree->left;
                
            } else{ // right é o único filho.
                aux = tree->right;
            }
            free(tree);
            return aux; // Encadeando com nó pai.
        
        } else{ // Dois filhos.
            aux = tree->left;
            while(aux->right != NULL){ // Procurando sucessor.
                aux = aux->right;
            }
            swap(&tree->disk, &aux->disk);

            // printf("chegou aq\n");
            tree->left = remove_min_disk_in_tree(tree->left, key, removed);
        }
    
    } else if(key < get_freeSpace(tree->disk)) { // procura em left
        // printf("chegou left\n");
        tree->left = remove_min_disk_in_tree(tree->left, key, removed);
    
    } else { // procura em right
        // printf("chegou right\n");
        tree->right = remove_min_disk_in_tree(tree->right, key, removed);
    }

    return tree;
}

// Tree* remove_min_disk_in_tree(Tree* tree, File* file, Disk** removed) {
//     Tree* aux;
//     if(is_empty_tree(tree)) return NULL;
//     // printf("disco: ");
//     // print_disk(tree->disk);
//     if(has_space(tree->disk, file)) { // cabe no pai, ver se cabe no left
//         if(!is_empty_tree(tree->left) && has_space(tree->left->disk, file)) { // se left existe e tem espaço, chamar recursivamente
//             // printf("entrou left\n");
//             tree->left = remove_min_disk_in_tree(tree->left, file, removed);
        
//         } else { // o pai  tem o disco de menor espaço que o arquivo cabe, remover ele
//             *removed = tree->disk;
//             // printf("chegou no que vai remover\n");
//             //!
//             if(is_leaf_node(tree)){ // Folha.
//                 free(tree);
//                 return NULL; // Atualizando ponteiro do nó pai. 
            
//             } else if(tree->left != NULL ^ tree->right != NULL){ // Somente um filho (^ é xor).
//                 if(tree->left != NULL){ // left é o único filho.
//                     aux = tree->left;
                    
//                 } else{ // right é o único filho.
//                     aux = tree->right;
//                 }
//                 free(tree);
//                 return aux; // Encadeando com nó pai.
            
//             } else{ // Dois filhos.
//                 aux = tree->left;
//                 while(aux->right != NULL){ // Procurando sucessor.
//                     aux = aux->right;
//                 }
//                 swap(&tree->disk, &aux->disk);

//                 // printf("chegou aq\n");
//                 tree->left = remove_min_disk_in_tree(tree->left, file, removed);
//                 // aux = remove_min_disk_in_tree(aux, file, removed);
//             }
//             //!
//         }
    
//     } else { // não cabe no pai, ver se cabe no right
//         // printf("chegou aq\n");
//         if(!is_empty_tree(tree->right)) { // se right existe, chamar recursivamente, independente de ter espaço ou não
//             // printf("entrou right\n");
//             tree->right = remove_min_disk_in_tree(tree->right, file, removed);
//         }
//     }
//     return tree; // mantendo encadeamento da arvore caso não aconteça nada nesse nó
// }

// Tree* remove_tree_bin(Tree* tree, File* file, Disk* removed){
//     /**
//      * Caso 1: nó folha
//      * Caso 2: retirar nó que tem apenas uma filho.
//      * Caso 3: retirar nó que tem 2 filhos.
//      **/
//     Tree* aux;
//     if(tree != NULL){
//         if(chave < getCR(tree->aluno)){
//             tree->left = remove_tree_bin(tree->left, file, removed);

//         } else if(chave > getCR(tree->aluno)){
//             tree->right = remove_tree_bin(tree->right, file, removed);

//         } else{ // Encontrou o elemento. Verificar qual caso é.
//             if(tree->left == NULL && tree->right == NULL){ // Folha.
//                 free(tree);
//                 return NULL; // Atualizando ponteiro do nó pai. 
            
//             } else if(tree->left != NULL ^ tree->right != NULL){ // Somente um filho (^ é xor).
//                 if(tree->left != NULL){ // left é o único filho.
//                     aux = tree->left;
                    
//                 } else{ // right é o único filho.
//                     aux = tree->right;
//                 }
//                 free(tree);
//                 return aux; // Encadeando com nó pai.
            
//             } else{ // Dois filhos.
//                 aux = tree->left;
//                 while(aux->right != NULL){ // Procurando sucessor.
//                     aux = aux->right;
//                 }

//                 Aluno* alunoAux = aux->aluno;
//                 aux->aluno = tree->aluno;
//                 tree->aluno = alunoAux;
//                 tree->left = remove_tree_bin(tree->left, file, removed);
//             }
//         }
//         return tree;
//     } else{
//         return NULL;
//     }
// }