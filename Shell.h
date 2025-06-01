#ifndef SHELL_H
#define SHELL_H

// Inclusion des bibliothèques standards nécessaires
#include <stdio.h>      // pour printf, fprintf, perror
#include <stdlib.h>     // pour malloc, free, exit
#include <string.h>     // pour strtok, strdup, strcmp
#include <unistd.h>     // pour fork, execvp, chdir
#include <sys/types.h>  // pour pid_t
#include <sys/wait.h>   // pour wait
#include <fcntl.h>      // pour open et les flags de fichiers

#define HISTORY_SIZE 10 // Nombre maximum d'éléments dans l'historique

// Prototypes des fonctions utilisées
void execute_command(char *line);           // Fonction principale pour exécuter une commande
char **parse_line(char *line);              // Découpe une ligne de commande en arguments
void free_args(char **args);                // Libère les arguments alloués
void print_error(const char *msg);          // Affiche un message d'erreur

#endif // SHELL_H
