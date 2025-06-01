# MiniShell — Projet 4 - Semaine 4
Une version simplifiée d'un shell Unix/Linux, codée en C.

# 🧾 Définition
Un mini shell est une version simplifiée d'un interpréteur de commandes Unix/Linux. Il permet de saisir et d'exécuter des commandes comme ls, cd, ou echo, en simulant le fonctionnement d'un véritable shell (comme bash ou zsh), mais avec une complexité réduite adaptée à un projet pédagogique en langage C.

# 🎯 Présentation du projet
Ce projet consiste à développer un shell minimal en C, capable de comprendre et d'exécuter des commandes de base, avec quelques fonctionnalités supplémentaires comme :
- Un historique des commandes
- La redirection de la sortie standard >
- L'exécution conditionnelle avec &&
> L'objectif est de mettre en œuvre des concepts fondamentaux de la programmation système : gestion de processus, entrées/sorties, manipulation de chaînes, et modularisation.

# 📌 Objectifs pédagogiques
- Manipuler les pointeurs et les chaînes de caractères en C
- Travailler avec les processus (fork, exec, wait)
- Gérer les redirections de fichiers (>)
- Implémenter un historique de commandes
- Modulariser le code (fonctions, commentaires, structure logique)

# 📁 Structure du projet :
- main.c : boucle principale du shell, gestion de l’historique, lecture des commandes
- shell.c : exécution des commandes, gestion de la redirection, commandes internes
- utils.c : fonctions utilitaires pour parser les commandes et gérer la mémoire
- shell.h : définitions et prototypes des fonctions

# ⚙️ Fonctionnalités
✅ Fonctionnalités implémentées :
- Saisie de commandes (avec getline)
- Exécution de commandes Unix via execvp
- Commande exit pour quitter
- Commande cd pour changer de répertoire
- Commande history pour afficher les 10 dernières commandes
- Redirection de sortie > (ex : ls > fichiers.txt)
- Chaînage conditionnel avec && (ex : mkdir test && cd test)

# 🚀 Utilisation
- Compilation (avec GCC) :
gcc main.c shell.c utils.c -o minishell
- Exécution :
./minishell

# 👥 Auteurs
Projet réalisé dans le cadre de l'apprentissage du langage C.
> Ce mini shell est un projet éducatif visant à mieux comprendre le fonctionnement interne des systèmes Unix/Linux. 🚧
