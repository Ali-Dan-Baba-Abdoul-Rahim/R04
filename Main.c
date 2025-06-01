#include "shell.h" // Inclusion des définitions et prototypes

int main() {
    char *line = NULL; // Pointeur vers la ligne de commande entrée
    size_t len = 0;    // Taille du tampon utilisé par getline()

    char *history[HISTORY_SIZE] = {NULL}; // Tableau circulaire pour l'historique
    int history_index = 0;                // Index courant pour l'historique

    while (1) { // Boucle infinie du shell
        printf("$ "); // Affiche le prompt

        if (getline(&line, &len, stdin) == -1) { // Lecture de la ligne utilisateur
            perror("getline"); // Erreur si lecture échoue
            break;
        }

        line[strcspn(line, "\n")] = 0; // Supprime le saut de ligne

        if (strlen(line) > 0) {
            if (history[history_index]) free(history[history_index]); // Nettoyage de l'ancienne commande
            history[history_index] = strdup(line); // Copie dans l'historique
            history_index = (history_index + 1) % HISTORY_SIZE; // Avance circulairement
        }

        if (strcmp(line, "exit") == 0)
            break; // Quitte le shell

        if (strcmp(line, "history") == 0) {
            for (int i = 0; i < HISTORY_SIZE; i++) {
                if (history[i]) printf("%d: %s\n", i + 1, history[i]);
            }
            continue; // Saute l'exécution de commande
        }

        char *cmd1 = strtok(line, "&&"); // Extraction de la première commande
        char *cmd2 = strtok(NULL, "&&"); // Deuxième commande, si présente

        if (cmd1) {
            int status;
            execute_command(cmd1); // Exécute la première commande
            wait(&status); // Attend sa fin

            if (cmd2 && WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                execute_command(cmd2); // Si succès, exécute la seconde
                wait(NULL);
            }
        }
    }

    free(line); // Libère la ligne allouée
    for (int i = 0; i < HISTORY_SIZE; i++) {
        free(history[i]); // Libère chaque élément de l'historique
    }

    return 0;
}
