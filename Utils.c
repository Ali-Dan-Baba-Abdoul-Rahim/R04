#include "shell.h" // Inclusion du header

char **parse_line(char *line) {
    int bufsize = 64, i = 0;
    char **tokens = malloc(bufsize * sizeof(char*)); // Allocation pour les arguments
    char *token = strtok(line, " "); // Découpe par espace

    if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (token != NULL) {
        tokens[i++] = token;
        if (i >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*)); // Réallocation si besoin
            if (!tokens) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens; // Retourne le tableau de pointeurs
}

void free_args(char **args) {
    free(args); // Libère uniquement le tableau, pas les chaînes (elles pointent sur `line`)
}

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg); // Affiche une erreur
}
