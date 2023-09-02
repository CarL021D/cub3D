
NAME = cub3d

SRCS	= 		srcs/main.c							\
				srcs/rendering/gameInit.c			\
				srcs/rendering/keyHandler.c			\
				srcs/rendering/playerDirection.c	\
				srcs/rendering/playerRotation.c		\
				srcs/rendering/playerPosInit.c		\
				srcs/rendering/rayCast.c			\
				srcs/rendering/rayCastUtils1.c		\
				srcs/rendering/rayCastUtils2.c		\
				

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CFLAGS	= -Wall -Werror -Wextra -g

CC		= gcc

RM		= rm -f

INCS    = inc

MLX = ./mlx/libmlx.a

all:	${NAME}

.c.o:
		@$(CC) ${CFLAGS} -I$(INCS) -c $< -o $@

${NAME}:	${OBJS} ${MLX}
		@${CC} ${CFLAGS} ${OBJS} ${MLX}  -lX11 -lXext -lm -o cub3d
		@printf "%s\e[0;32m cub3d : Compiling object file into executable\n\e[0m" "-"

${MLX}:
		@make -C mlx --no-print-directory

clean:
		@${RM} ${OBJS}
		@printf "%s\e[0;31m cub3d : Delete all object files\n\e[0m" "-"

fclean:
		@${RM} ${OBJS}
		@printf "%s\e[0;31m cub3d : Delete all object files\n\e[0m" "-"
		@${RM} ${NAME}
		@printf "%s\e[0;31m cub3d : Delete executable\n\e[0m" "-"
		@make clean -C mlx --no-print-directory


re: fclean ${NAME}

.PHONY: all clean fclean re bonus