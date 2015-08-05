NAME = rpg

SRC = main.cpp \
	Game.cpp \
	Sprite.cpp \
	Character.cpp \
	Tile.cpp \
	Map.cpp \
	funct.cpp \

SRC_DIR = Sources/

INC = Includes/

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLAGS = -Wall -Werror -Wextra

LIB = -lSDL2 -lSDL2_image

all: $(NAME)

$(NAME):
	@echo -n "Sources -> objets ..."
	@$(CC) $(FLAGS) -c $(addprefix $(SRC_DIR), $(SRC)) -I ./$(INC)
	@echo " \033[1;32mok\033[0m"
	@echo -n "Objets -> $(NAME) ..."
	@$(CC) $(OBJ) -o $(NAME) $(LIB) -I ./$(INC)
	@echo " \033[1;32mok\033[0m"
	@echo "Compilation terminée !"
	@mkdir Objets
	@mv $(OBJ) Objets

clean:
	@/bin/rm -rf Objets
	@echo "Les fichiers .o ont correctement étés supprimés !"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "L'exécutable a correctement été supprimé !"

re: fclean all

test: re
	@./$(NAME)
