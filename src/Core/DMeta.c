#include "DMeta.h"

DMetaMask DMetaMask_create(size_t size) {
    DMetaMask mask;
    mask._size = ceil((double)size / 8.0);
    mask._mask = (uint8_t*)calloc(floor((double)size / 8.0), sizeof(uint8_t));
    return mask;
}
DMetaMask DMetaMask_recreate(void* ptr, size_t size) {
    DMetaMask mask;
    mask._size = ceil((double)size / 8.0);
    mask._mask = ptr;
    return mask;
}
void DMetaMask_free(DMetaMask mask) {
    free(mask._mask);
}
bool DMetaMask_set_single(DMetaMask mask, size_t position, bool value) {
    if (position > mask._size * 8) return false;
    mask._mask[(uint32_t)floor((double)position / 8.0)] |= (1 << position);
    return true;
}
bool DMetaMask_set_multiple(DMetaMask mask, bool* arr, size_t size) {
    if (size > mask._size * 8) return false;
    for (int i = 0; i < size; i++) {
        if (arr[i]) {
            uint32_t idx = (uint32_t)floor((double)i / 8.0);
            mask._mask[idx] |= (1 << (i % 8));
        }
    }
    return true;
}
bool DMetaMask_get_single(DMetaMask mask, size_t position) {
    if (position > mask._size * 8) return false;
    return mask._mask[(uint32_t)floor((double)position / 8.0)] & (1 << position);
}
bool* DMetaMask_get_mutiple(DMetaMask mask, uint8_t* ptr) {
    bool* arr = (bool*)calloc(mask._size * 8, sizeof(bool));
    for (int i = 0; i < mask._size * 8; i++) {
            uint32_t idx = (uint32_t)floor((double)i / 8.0);
        if ((uint32_t)(ptr == NULL ? mask._mask[idx] : *ptr) & (uint32_t)(1 << i)) {
            arr[i] = true;
        } else {
            arr[i] = false;
        }
    }

    return arr;
}
void* DMetaMask_get_pointer(DMetaMask mask) {
    return mask._mask;
}
void DMetaMask_print(DMetaMask mask) {
    for (int i = 0; i < mask._size * 8; i++) {
        if(DMetaMask_get_single(mask, i)) printf("1"); else printf("0");
    }
    printf("\n");
}
