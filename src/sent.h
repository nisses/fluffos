struct sentence {
    char *verb;
    struct object *ob;
    char *function;
    struct sentence *next;
    int flags;
};

#define V_SHORT		1
#define V_NOSPACE	2
#define V_PREVERB	4
#define V_REPLACE	8
#define V_GLOBAL	16

struct sentence *alloc_sentence();

void remove_sent PROT((struct object *, struct object *)),
    free_sentence PROT((struct sentence *));
