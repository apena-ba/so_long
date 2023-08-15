NAME = so_long

NAME_BONUS = so_long_bonus

SRC = src/*.c

SRC_BONUS = src_bonus/*.c

OBJ = obj/*.o

OBJ_BONUS = obj_bonus/*.o

CFLAGS = -Wall -Wextra -Werror -g

INC = -I includes/ -I libft/includes -I MLX42/include/MLX42

LIBFT = libft/libft.a

MLX = MLX42/libmlx42.a

all: ${NAME}

${NAME}: ${LIBFT} ${MLX} ${OBJ}
	@gcc ${CFLAGS} -lglfw -L /Users/apena-ba/.brew/opt/glfw/lib -o ${NAME} ${MLX} ${LIBFT} ${OBJ}
	@echo "\n🎮 Juego listo ✅\n"

${NAME_BONUS}: ${LIBFT} ${MLX} ${OBJ_BONUS}
	@gcc ${CFLAGS} -lglfw -L /Users/apena-ba/.brew/opt/glfw/lib -o ${NAME_BONUS} ${MLX} ${LIBFT} ${OBJ_BONUS}
	@echo "\n🎮 Juego bonus listo ✅\n"

${LIBFT}: libft/src/*.c
	@make -C libft/ --silent
	@echo "\n📕 Libft compilada ✅\n"

${OBJ}: ${SRC} 
	@gcc ${INC} ${CFLAGS} -c ${SRC}
	@rm -rf obj
	@mkdir obj
	@mv *.o obj
	@echo "\n🔨 Objetos creados ✅\n"

${OBJ_BONUS}: ${SRC_BONUS} 
	@gcc ${INC} ${CFLAGS} -c ${SRC_BONUS}
	@rm -rf obj_bonus
	@mkdir obj_bonus
	@mv *.o obj_bonus
	@echo "\n🔨 Objetos bonus creados ✅\n"

${MLX}: MLX42/src/*.c
	@make -C MLX42/ --silent
	@echo "\n📊 MLX compilada ✅\n"

clean:
	@make -C libft/ clean --silent
	@rm -rf obj
	@rm -rf obj_bonus
	@echo "\n🧨 Objetos destruidos ✅\n"

fclean: clean
	@make -C libft/ fclean --silent
	@rm -f ${NAME}
	@rm -f ${NAME_BONUS}
	@echo "\n💥 Archivos binarios destruidos ✅\n"

s:
	@rm -f *.o
	@echo "\n🧹 Basura limpia ✅\n"

sclean: s fclean

re: fclean all

sre: sclean all bonus

bonus: ${NAME_BONUS}

.PHONY: all clean fclean sclean re sre
