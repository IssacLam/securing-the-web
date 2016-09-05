int depth=nondet_int();
__CPROVER_assume(depth>0 && depth<10);
for(int i=0; i<depth; i++) { 
    /* do something */ 
}