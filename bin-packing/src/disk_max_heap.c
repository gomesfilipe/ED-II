#include "../include/disk_max_heap.h"

struct heap {
    int size;
    int length;
    Disk** disks;
};

Heap* create_heap(FileArray* fileArray) {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->size = get_length_array(fileArray);
    heap->length = 0;
    heap->disks = (Disk**) malloc(sizeof(Disk*) * heap->size);
    return heap;
}

void free_heap(Heap* heap) {
    for(int i = 0; i < heap->length; i++) {
        free_disk(heap->disks[i]);
    }
    free(heap->disks);
    free(heap);
}

void print_heap(Heap* heap) {
    for(int i = 0; i < heap->length; i++) {
        print_disk(heap->disks[i]);
    }
    printf("\n");
}

static void swap(Disk** a, Disk** b) {
    Disk* aux = *a;
    *a = *b;
    *b = aux;
}

static int left_child_index(int parentIndex) {
    return 2 * parentIndex + 1;
}

static int right_child_index(int parentIndex) {
    return 2 * parentIndex + 2;
}

static int parent_index(int childIndex) {
    return (childIndex - 1) / 2;
}

void insert_disk_in_heap(Heap* heap, Disk* disk) {
    if(heap->length == heap->size) return;
    
    heap->disks[heap->length] = disk;

    int childIndex = heap->length;
    int parentIndex = parent_index(childIndex);
    Disk* parentDisk = heap->disks[parentIndex];

    while(get_freeSpace(disk) > get_freeSpace(parentDisk)) {
        swap(&heap->disks[childIndex], &heap->disks[parentIndex]);

        childIndex = parentIndex;
        parentIndex = parent_index(childIndex);
        parentDisk = heap->disks[parentIndex];
    }

    heap->length++;
}

static void max_heapify(Heap* heap, int i) {
    int largest = i;
    int left = left_child_index(i);
    int right = right_child_index(i);

    if(left < heap->length && get_freeSpace(heap->disks[left]) >  get_freeSpace(heap->disks[largest])) {
        largest = left;
    }

    if(right < heap->length && get_freeSpace(heap->disks[right]) >  get_freeSpace(heap->disks[largest])) {
        largest = right;
    }

    if(largest != i) {
        swap(&heap->disks[i], &heap->disks[largest]);
        max_heapify(heap, largest);
    }
}

Disk* remove_max_disk_in_heap(Heap* heap) {
    Disk* removed = heap->disks[0];
    heap->disks[0] = heap->disks[heap->length - 1];
    heap->length--;

    max_heapify(heap, 0);

    return removed;
}
