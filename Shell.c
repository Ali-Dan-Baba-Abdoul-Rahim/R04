#include "shell.h" // Inclusion du header

void execute_command(char *line) {
    char *output_file = strchr(line, '>'); // Recherche une redirection '>'
    int fd = -1; // Descripteur de fichier

    if (output_file) { // Si redirection
        *output_file = '\0'; // Coupe la ligne à la position de '>'
        output_file++; // Passe au nom du fichier
        while (*output_file == ' ') output_file++; // Ignore les espaces
        output_file[strcspn(output_file, " ")] = 0; // Coupe après le nom

        fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644); // Ouvre/crée le fichier
        if (fd == -1) {
            perror("open");
            return;
        }
    }

    char **args = parse_line(line); // Tokenisation de la commande

    if (args[0] == NULL) {
        free_args(args);
        return;
    }

    if (strcmp(args[0], "cd") == 0) { // Commande interne : cd
        if (args[1] == NULL || chdir(args[1]) != 0)
            perror("cd");
        free_args(args);
        return;
    }

    pid_t pid = fork(); // Création du processus fils

    if (pid == 0) { // Enfant
        if (fd != -1) {
            dup2(fd, STDOUT_FILENO); // Redirige la sortie
            close(fd);
        }
        execvp(args[0], args); // Lance la commande
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork"); // Erreur de fork
    } else {
        if (fd != -1) close(fd); // Ferme le fichier si ouvert
    }

    free_args(args); // Nettoyage
}
