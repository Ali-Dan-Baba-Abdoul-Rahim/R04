# Nom de l'exécutable
TARGET = minishell

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Sources et objets
SRCS = main.c shell.c utils.c
OBJS = $(SRCS:.c=.o)

# Règle par défaut : compilation de l'exécutable
all: $(TARGET)

# Création de l'exécutable à partir des objets
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers source en fichiers objets
%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

# Nettoyage complet (en plus des objets, supprime fichiers temporaires si ajoutés)
fclean: clean

.PHONY: all clean fclean
