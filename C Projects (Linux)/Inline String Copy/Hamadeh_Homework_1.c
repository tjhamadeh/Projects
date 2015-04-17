// Homework 1

#include  <stdio.h>

static inline char *strcpy(char *dest, const char *src, int s_idx, int e_idx)
{
    char *t_dst, *t_src;
    t_dst = dest;
    t_src = src;
    t_src += s_idx;
    
    for(int i = 0; i <= (e_idx - s_idx); i++) {
          *t_dst = *t_src;
          t_src++;
          t_dst++;
    }
    
    t_dst++;
    *t_dst = '\0';

    printf("strcpy(): \t%s\n", dest);
    return dest;
}

static inline char *asm_strcpy(char *dest, const char *src, int s_idx, int e_idx) {
    int rsrc, rdst;
    
    __asm__ 
        __volatile__ 
            ("movl $0, %%ecx;"
            "1: lodsb;"
            "cmpl %4, %%ecx;"
            "je 2f;"
            "addl $1, %%ecx;"
            "jmp 1b;"
            "2: stosb;"
            "addl $1, %%ecx;"
            "3: lodsb;"
            "stosb;"
            "cmpl %5, %%ecx;"
            "je 4f;"
            "addl $1, %%ecx;"
            "jmp 3b;"
            "4: nop;"
            :"=&S" (rsrc), "=&D"(rdst)
            :"0" (src), "1" (dest), "r" (s_idx), "r" (e_idx)
            :"eax", "ecx");
    
    printf("asm_strcpy(): \t%s\n", dest);
    
    return dest;
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    char *d  = (char *)malloc(sizeof(char)*8);
    int s_idx = 1;
    int e_idx = 4;
    printf("\ns_idx = %d, e_idx = %d\n", s_idx, e_idx);
    printf("string s: \t%s\n", s);
    char *d1 = strcpy(d, s, s_idx, e_idx);
    char *d2 = asm_strcpy(d, s, s_idx, e_idx);
    printf("\n");

    return 0;
}
