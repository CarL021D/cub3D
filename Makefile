
NAME = cub3d

SRCS	= 		main.c				\
				gameInit.c			\
				keyHandler.c		\
				playerDirection.c	\
				playerRotation.c	\
				rayCast.c			\
				rayCastUtils1.c		\
				rayCastUtils2.c		\
				

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CFLAGS	= -Wall -Werror -Wextra -g

CC		= gcc

RM		= rm -f

INCS    = inc

MLX = ./mlx_linux/libmlx.a

all:	${NAME}

.c.o:
		@$(CC) ${CFLAGS} -I$(INCS) -c $< -o $@

${NAME}:	${OBJS} ${MLX}
		@${CC} ${CFLAGS} ${OBJS} ${MLX}  -lX11 -lXext -o cub3d
		@printf "%s\e[0;32m cub3d : Compiling object file into executable\n\e[0m" "-"

${MLX}:
		@make -C mlx_linux --no-print-directory

clean:
		@${RM} ${OBJS}
		@printf "%s\e[0;31m cub3d : Delete all object files\n\e[0m" "-"

fclean:
		@${RM} ${OBJS}
		@printf "%s\e[0;31m cub3d : Delete all object files\n\e[0m" "-"
		@${RM} ${NAME}
		@printf "%s\e[0;31m cub3d : Delete executable\n\e[0m" "-"
		@make clean -C mlx_linux --no-print-directory


re: fclean ${NAME}

.PHONY: all clean fclean re bonus