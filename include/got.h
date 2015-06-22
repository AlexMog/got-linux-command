#ifndef GOT_H_
# define GOT_H_

# define VERSION "0.1.0"

typedef struct s_quote {
  char *author;
  char *quote;
} t_quote;

typedef struct s_options {
  char* character;
} t_options;

int get_random(int, int);
int set_options(t_options*, int, char**);
void show_version_info(void);
t_quote* get_normal_quote(int*, int*);
t_quote* get_character_quote(t_options*, int *size, int *selected);

#endif /* !GOT_H_ */
