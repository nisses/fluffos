/*
 * Some structure forward declarations are needed.
 */
struct program;
struct function;
struct svalue;
struct sockaddr;

#ifdef BUFSIZ
#    define PROT_STDIO(x) PROT(x)
#else /* BUFSIZ */
#    define PROT_STDIO(x) ()
#endif /* BUFSIZ */

#ifdef __STDC__
#    define PROT(x) x
#else /* __STDC__ */
#    define PROT(x) ()
#endif /* __STDC */

#ifndef INLINE
#if defined(__GNUC__) && !defined(lint)
#define INLINE inline
#else
#define INLINE
#endif
#endif

#ifdef NeXT
#include <libc.h>
#else
#ifndef MSDOS
#if defined(sun) && defined(__STDC__)
#ifdef BUFSIZ
int fprintf(FILE *, char *, ...);
int fputs(char *, FILE *);
int fputc(char, FILE *);
int fwrite(char *, int, int, FILE *);
int fread(char *, int, int, FILE *);
#endif
int printf(char *, ...);
int sscanf(char *, char *, ...);
void perror(char *);
#endif

int read PROT((int, char *, int));
#ifndef _AIX
char *malloc PROT((unsigned));
char *realloc PROT((char *, unsigned));
#endif
#if !defined(sgi) && !defined(hpux) && !defined(_AIX)
int mkdir PROT((char *, int));
#endif
int fclose PROT_STDIO((FILE *));
int pclose PROT_STDIO((FILE *));
#ifndef _AIX
int atoi PROT((char *));
#endif
#if !defined(sgi) && !defined(hpux)
void srandom PROT((int));
#endif
int chdir PROT((char *));
int gethostname PROT((char *, int));
void abort PROT((void));
int fflush PROT_STDIO((FILE *));
int rmdir PROT((char *));
int unlink PROT((char *));
int fclose PROT_STDIO((FILE *));
#if !defined(sgi) && !defined(hpux) && !defined(_AIX) && !defined(M_UNIX)
int system PROT((char *));
#endif
#ifndef _AIX
void qsort PROT((char *, int, int, int (*)()));
#endif
int fseek PROT_STDIO((FILE *, long, int));
int _flsbuf();
int fork PROT((void));
int wait PROT((int *));
int execl PROT((char *, char *, ...));
int pipe PROT((int *));
int dup2 PROT((int, int));
int vfork PROT((void));
#ifndef _AIX
void free PROT((char *));
#endif
unsigned int alarm PROT((unsigned int));
int ioctl PROT((int, ...));
int close PROT((int));
int write PROT((int, char *, int));
int _filbuf();
char *crypt PROT((char *, char *));
#ifdef sun
char *_crypt PROT((char *, char *));
#endif

#ifdef DRAND48
double drand48 PROT((void));
void srand48 PROT((long));
#endif
#ifdef RANDOM
long random PROT((void));
#endif

#ifndef _AIX
long strtol PROT((char *, char **, int));
#endif
int link PROT((char *, char *));
int unlink PROT((char *));
#endif MSDOS

#endif NeXT

struct object;
void init_rc PROT((int));
char *get_error_file PROT((char *));
void save_error PROT((char *, char *, int));
int write_file PROT((char *, char *));
int file_size PROT((char *));
char *check_file_name PROT((char *, int));
void remove_all_players PROT((void));
void load_wiz_file PROT((void));
void wizlist PROT((char *));
void backend PROT((void));
char *xalloc PROT((int));
void init_string_space PROT((void));
void error();
void fatal();
void add_message();
void trace_log();
void debug_message();
void debug_message_value PROT((struct svalue *)),
	print_local_commands(),
	new_call_out PROT((struct object *, char *, int, struct svalue *)),
	add_action PROT((char *, char *, int)),
	list_files PROT((char *)),
	enable_commands PROT((int)),
	load_ob_from_swap PROT((struct object *));
int tail PROT((char *));
struct object *get_interactive_object PROT((int));
void enter_object_hash PROT((struct object *));
void remove_object_hash PROT((struct object *));
struct object *lookup_object_hash PROT((char *));
int show_otable_status PROT((int verbose));
void dumpstat PROT((void));
struct mapping;
void free_mapping PROT((struct mapping *));
struct svalue *find_in_mapping PROT((struct mapping *, struct svalue *));
struct svalue *find_for_insert PROT((struct mapping *, struct svalue *));
struct mapping *load_mapping_from_aggregate PROT((struct svalue *, int));
struct mapping *add_mapping PROT((struct mapping *, struct mapping *));
struct mapping *map_mapping 
   PROT((struct mapping *, char *, struct object *, struct svalue *));
struct mapping *compose_mapping PROT((struct mapping *, struct mapping *));
struct vector;
struct vector *mapping_indices PROT((struct mapping *));
void free_vector PROT((struct vector *));
char *query_load_av PROT((void));
void update_compile_av PROT((int));
struct vector *map_array PROT((
			       struct vector *arr,
			       char *func,
			       struct object *ob,
			       struct svalue *extra
			       ));
struct vector *make_unique PROT((struct vector *arr,char *func,
    struct svalue *skipnum));

char *describe_items PROT((struct svalue *arr,char *func,int live));
struct vector *commands PROT((struct object *));
struct vector *find_wizard PROT((char *));
struct vector *wizards();
struct vector *filter PROT((struct vector *arr,char *func,
			    struct object *ob, struct svalue *)); 
int match_string PROT((char *, char *));
int set_heart_beat PROT((struct object *, int));
struct object *get_empty_object PROT((int));
struct svalue;
INLINE void assign_svalue PROT((struct svalue *, struct svalue *));
INLINE void assign_svalue_no_free PROT((struct svalue *to, struct svalue *from));
void free_svalue PROT((struct svalue *));
char *make_shared_string PROT((char *));
char *ref_string PROT((char *));
void free_string PROT((char *));
int add_string_status PROT((int verbose));
void notify_no_command PROT((void));
void clear_notify PROT((void));
void throw_error PROT((void));
void set_living_name PROT((struct object *,char *));
void remove_living_name PROT((struct object *));
struct object *find_living_object PROT((char *, int));
int lookup_predef PROT((char *));
void yyerror PROT((char *));
int hashstr PROT((char *, int, int));
int lookup_predef PROT((char *));
char *dump_trace PROT((int));
int parse_command PROT((char *, struct object *));
struct svalue *apply PROT((char *, struct object *, int));
INLINE void push_string PROT((char *, int));
INLINE void push_number PROT((int));
INLINE void push_object PROT((struct object *));
struct object *clone_object PROT((char *));
void init_num_args PROT((void));
int restore_object PROT((struct object *, char *));
struct object *first_inventory PROT((struct svalue *));
struct vector *slice_array PROT((struct vector *,int,int));
int query_idle PROT((struct object *));
char *implode_string PROT((struct vector *, char *));
struct object *query_snoop PROT((struct object *));
struct vector *all_inventory PROT((struct object *));
struct vector *deep_inventory PROT((struct object *, int));
struct object *environment PROT((struct svalue *));
struct vector *add_array PROT((struct vector *, struct vector *));
char *get_f_name PROT((int));
#if !defined(_AIX) && !defined(NeXT)
void startshutdowngame PROT((void));
#else
void startshutdowngame PROT((int));
#endif
void set_notify_fail_message PROT((char *));
int swap PROT((struct object *));
int transfer_object PROT((struct object *, struct object *));
struct vector *users PROT((void));
void do_write PROT((struct svalue *));
void log_file PROT((char *, char *));
int remove_call_out PROT((struct object *, char *));
char *create_wizard PROT((char *, char *));
void destruct_object PROT((struct svalue *));
void set_snoop PROT((struct object *, struct object *));
int new_set_snoop PROT((struct object *, struct object *));
void add_verb PROT((char *, int));
void ed_start PROT((char *, char *, struct object *));
void say PROT((struct svalue *, struct vector *));
void tell_room PROT((struct object *, struct svalue *, struct vector *));
void shout_string PROT((char *));
int command_for_object PROT((char *, struct object *));
int remove_file PROT((char *));
int print_file PROT((char *, int, int));
int print_call_out_usage PROT((int verbose));
int input_to PROT((char *, int));
int parse PROT((char *, struct svalue *, char *, struct svalue *, int));
struct object *object_present PROT((struct svalue *, struct object *));
void add_light PROT((struct object *, int));
int indent_program PROT((char *));
void call_function PROT((struct program *, struct function *));
void store_line_number_info PROT((void));
INLINE void push_constant_string PROT((char *));
void push_svalue PROT((struct svalue *));
struct variable *find_status PROT((char *, int));
void free_prog PROT((struct program *, int));
void stat_living_objects PROT((void));
int heart_beat_status PROT((int verbose));
void opcdump PROT((void));
void slow_shut_down PROT((int));
struct vector *allocate_array PROT((int));
void yyerror PROT((char *));
void reset_machine PROT((int));
void clear_state PROT((void));
void preload_objects PROT((int));
int random_number PROT((int));
void reset_object PROT((struct object *, int));
int replace_interactive PROT((struct object *ob, struct object *obf, char *));
char *get_wiz_name PROT((char *));
char *get_log_file PROT((char *));
int get_current_time PROT((void));
char *time_string PROT((int));
char *process_string PROT((char *));
void update_ref_counts_for_players PROT((void));
void count_ref_from_call_outs PROT((void));
void check_a_lot_ref_counts PROT((struct program *));
int shadow_catch_message PROT((struct object *ob, char *str));
struct vector *get_all_call_outs PROT((void));
char *read_file PROT((char *file, int, int));
char *read_bytes PROT((char *file, int, int));
int write_bytes PROT((char *file, int, char *str));
struct wiz_list *add_name PROT((char *str));
char *check_valid_path PROT((char *, struct object *, char *, int));
int get_line_number_if_any PROT((void));
void logon PROT((struct object *ob));
struct svalue *apply_master_ob PROT((char *fun, int num_arg));
void assert_master_ob_loaded();
struct vector *explode_string PROT((char *str, char *del));
char *string_copy PROT((char *));
int find_call_out PROT((struct object *ob, char *fun));
void remove_object_from_stack PROT((struct object *ob));
#if !defined(sgi) && !defined(NeXT) && !defined(hpux)
int getpeername PROT((int, struct sockaddr *, int *));
void  shutdown PROT((int, int));
#endif
void compile_file PROT((void));
void unlink_swap_file();
char *function_exists PROT((char *, struct object *));
void set_inc_list PROT((char *list));
int legal_path PROT((char *path));
struct vector *get_dir PROT((char *path, int));
#if !defined(ultrix) && !defined(M_UNIX) && !defined(sgi) && !defined(hpux) && !defined(_AIX) && !defined(NeXT)
extern int rename PROT((char *, char *));
#endif
void set_simul_efun PROT((char *));
void set_global_include PROT((char *));
struct function *find_simul_efun PROT((char *));
char *query_simul_efun_file_name PROT((void));
struct vector *match_regexp PROT((struct vector *v, char *pattern));

#ifdef MUDWHO
int rwhocli_setup PROT((char *server, char *serverpw, char *myname,
			char *comment));
int rwhocli_shutdown PROT((void));
int rwhocli_pingalive PROT((void));
int rwhocli_userlogin PROT((char *uid, char *name, int tim));
int rwhocli_userlogout PROT((char *uid));
#endif /* MUDWHO */

int remove_action PROT((char *,char *));

void get_version PROT((char *));

INLINE long get_config_int PROT((int num));
INLINE char * get_config_str PROT((int num));
void set_defaults PROT((char * filename));
INLINE struct mapping *allocate_mapping PROT((int));

int check_in PROT((char *fn, char *msg, int major, int minor));
int check_out PROT((char *fn, int major, int minor));
char *rlog PROT((char *));

int copy_file PROT((char *from, char *to));
int get_char PROT((char *fun, int flag));

char *string_print_formatted PROT((char *format_str, int argc, struct svalue *argv));
struct vector *children PROT((char *obj));
void message PROT((char *,char *, struct vector *, struct vector *));

#ifdef SYSMALLOC
void *sysmalloc PROT((int));
void *sysrealloc PROT((void *,int));
void *syscalloc PROT((int,int));
void sysfree PROT((void *));
#endif
