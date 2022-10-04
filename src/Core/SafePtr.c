#include "SafePtr.h"

#if defined(__MINGW32__)
void* reallocarray(void *__ptr, size_t __nmemb, size_t __size) {
    return realloc(__ptr, __nmemb * __size);
}
#endif

_sptr_t* _sptr_get_meta(void* ptr) {
    _sptr_t* _sptr = (_sptr_t*)((char*)ptr - sizeof(_sptr_meta_t));
    if (_sptr->_meta._chek == ptr) {
        return _sptr;
    } else {
        return NULL;
    }
}
void* _sptr_make(void* data, size_t size) {
    _sptr_t* sptr = (_sptr_t*)malloc(sizeof(_sptr_meta_t) + size);
    void* ptr = ((char*)sptr) + sizeof(_sptr_meta_t);
    memcpy(ptr, data, size);
    sptr->_meta._chek = ptr;
    sptr->_meta._pfre = NULL;
    sptr->_meta._pfsz = 0;
    printf(COL_GRN "make: " COL_NRM "%p" COL_GRN " : " COL_NRM "%p\n", sptr, ptr);
    return ptr;
}
void _sptr_free(void* ptr) {
    _sptr_t* _sptr = _sptr_get_meta(*(void**)ptr);
    if (!_sptr) {
        printf(COL_RED "erro: " COL_NRM "%p" COL_RED " : " COL_NRM "Non safe ptr\n", *(void**)ptr);
        return;
    }
    if (_sptr->_meta._refr > 0) {
        _sptr->_meta._refr--;
        printf(COL_YEL "refr: " COL_NRM "%p" COL_YEL " : " COL_NRM "%p\n", _sptr, *(void**)ptr);
        return;
    }
    printf(COL_RED "free: " COL_NRM "%p" COL_RED " : " COL_NRM "%p\n", _sptr, *(void**)ptr);
    for (int i = 0; i < _sptr->_meta._pfsz; i++) {
        printf(COL_RED "free: " COL_NRM "%p\n", _sptr->_meta._pfre[i]);
        free(_sptr->_meta._pfre[i]);
    }
    if (_sptr->_meta._pfre)
        free(_sptr->_meta._pfre);
    _sptr->_meta._chek = NULL;
    free((void*)_sptr);
    _sptr = NULL;
}
void* _sptr_return(void* ptr) {
    _sptr_t* _sptr = _sptr_get_meta(ptr);
    if (!_sptr) {
        printf(COL_RED "NON SAFE PTR    : " COL_NRM "%p\n", *(void**)ptr);
        return NULL;
    }
    _sptr->_meta._refr++;
    return ptr;
}

void* _sptr_add(void* child, void* ptr, size_t size) {
    _sptr_t* _sptr = _sptr_get_meta(ptr);
    if (_sptr->_meta._pfre == NULL) {
        _sptr->_meta._pfre = calloc(++_sptr->_meta._pfsz, sizeof(void*));
    } else {
        _sptr->_meta._pfre = reallocarray(_sptr->_meta._pfre, ++_sptr->_meta._pfsz, sizeof(void*));
    }
    void* _tmp = malloc(size);
    memcpy(_tmp, child, size);
    _sptr->_meta._pfre[_sptr->_meta._pfsz - 1] = _tmp;
    return child;
}
