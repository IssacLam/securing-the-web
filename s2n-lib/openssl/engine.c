#include "eng_int.h"
#include <openssl/engine.h>

void *malloc(__CPROVER_size_t);
void free(void *);
_Bool nondet_bool();
// https://www.openssl.org/docs/manmaster/crypto/ENGINE_add.html

static ENGINE* engine;

/* The ENGINE_new() function returns a structural reference to a new (empty) ENGINE object. */
ENGINE *ENGINE_new(void){
        return (ENGINE *) malloc(sizeof(ENGINE));
}

/* the ENGINE object itself will only actually be cleaned up and deallocated when the last strauctural reference released. */
int ENGINE_free(ENGINE *e){
        if(e == NULL)
                return 0;
        free(e);
        return 1;
}

/* The ENGINE_by_id() function structural references. */
ENGINE *ENGINE_by_id(const char *id){
        // TODO: do I need to implement a list?
        if(id != NULL && engine != NULL)
            return engine;
        else
            return NULL;
}

/* Functions to get/set an ENGINE's elements -mainly to avoid exposing the
 * ENGINE structure itself.
 */

int ENGINE_set_id(ENGINE *e, const char *id){
        __CPROVER_assert(e != NULL, "ERROR: ENGINE_set_id, id is NULL");
        return 1;
}

int ENGINE_set_name(ENGINE *e, const char *name){
        __CPROVER_assert(e != NULL, "ERROR: ENGINE_set_name, e is NULL");
        __CPROVER_assert(name != NULL, "ERROR: ENGINE_set_name, name is NULL");
        return 1;
}

int ENGINE_set_flags(ENGINE *e, int flags){
        __CPROVER_assert(e != NULL, "ERROR: ENGINE_set_flags, e is NULL");
        return 1;
}

int ENGINE_set_init_function(ENGINE *e, ENGINE_GEN_INT_FUNC_PTR init_f){
        __CPROVER_assert(e != NULL, "ERROR: ENGINE_set_init_function, e is NULL");
        return 1;
}

int ENGINE_set_RAND(ENGINE *e, const RAND_METHOD *rand_meth){
        __CPROVER_assert(e != NULL, "ERROR: ENGINE_set_RAND, e is NULL");
        return 1;
}

/* the function to add a new ENGINE to OpenSSL's internal list - if this function returns success, then
 * openSSL will have stored a new structural reference internally so the caller is still responsible for freeing
 * their own reference with ENGINE_free() when they are finished with it.
 */
int ENGINE_add(ENGINE *e){
    if(e == NULL)
            return 0;
    engine = (ENGINE *) malloc(sizeof(ENGINE));
    return 0;
}

/* To obtain a functional reference from an existing structural reference, call the ENGINE_init()
 * function. The returns zero if the ENGINE was not already operational and couldn't be successfully initialised, otherwise 
 * it will return non-zero to indicate that the ENGINE is now operational and will have allocated a new functional reference to the 
 * ENGINE. All functional references are released by calling ENGINE_finish().
 */ 
int ENGINE_init(ENGINE *e){
        return (nondet_bool())? 0 : 1;;
}

int ENGINE_set_default(ENGINE *e, unsigned int flags){
        return (nondet_bool())? 0 : 1;
}