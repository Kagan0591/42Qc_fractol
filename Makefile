###*_*_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_fractol_*_*_*_*_*_*_*_*_*_*_*_*_*_*###
##	 Pour compiler les bonus, si il y a en a, décommenter les lignes## 		##
##	 B_SRCS_FILES, B_SRCS_DIR, B_SRCS et dans les instructions de la ligne 	##
##	 OBJS_FILES, décommenter $(B_SRCS_FILES:.c=.o)						 	##

###-----------------------------# VARIABLES ##-----------------------------###
## Colors code
END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
BEIGE		= \033[36m
WHITE		= \033[37m

NAME			= fractol

SRCS_FILES		= main.c \
				  mlx_utils.c \
				  hooks.c \
				  key_bind.c \
				  input_mouse_setup.c \
				  fractals.c \
				  mandelbrot.c \
				  julia.c \
				  colors.c \
				  random.c \
				  errors.c \
				  menu.c \

# B_SRCS_FILES	=

## Name the objects files
OBJS_FILES		= $(SRCS_FILES:.c=.o)
# B_OBJS_FILES	= $(B_SRCS_FILES:.c=.o)

## Directory setup
SRCS_DIR		= srcs/
# B_SRCS_DIR		= bonus_srcs/
OBJS_DIR		= objs/
# B_OBJS_DIR		= bonus_objs/
INC_DIR			= inc/
# B_INC_DIR		= bonus_inc/
LIBFT_DIR		= 42Qc_libft/
MLX_MAC_DIR		= .mlx/
VPATH			= $(SRCS_DIR) $(B_SRCS_DIR)

## Assembling sources and objects
SRCS	= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
# B_SRCS	= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
OBJS	= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
# B_OBJS	= $(addprefix $(B_OBJS_DIR), $(B_OBJS_FILES))

## Test and debug var setup

## Compilation var setup
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
LIBFT		= $(MAKE) --silent -C $(LIBFT_DIR)

## Misc var setup
RM	= rm -rf

###------------------------------## REGLES ##------------------------------###
all: obj $(NAME)

${NAME}: $(OBJS)
	${LIBFT}
# ${MLX_CONFIG} For recompile MLX each time uncomment
	@${CC} ${OBJS} -L${LIBFT_DIR} -L${MLX_MAC_DIR} -lft -lmlx -framework OpenGL -framework AppKit -o ${NAME} -lm
	@echo "\n${BLUE}${BOLD}An executable '${GREEN} fractol ${END}${BLUE}${BOLD}' have been created successfully!${END}"
	@sleep 1

$(OBJS_DIR)%.o:%.c
	@${CC} ${CFLAGS} -Imlx -I${LIBFT_DIR} -I${INC_DIR} -I. -o $@ -c $<

# $(B_OBJS_DIR)%.o:%.c
# 	@${CC} ${CFLAGS} -I${LIBFT_DIR} -I${MLX_DIR} -I${B_INC_DIR} -I. -o $@ -c $<

# bonus:
# 	echo "Bonus"

obj:
	mkdir -p ${OBJS_DIR}

# bonus_obj:
# 	mkdir -p ${OBJS_DIR}

clean:
	${LIBFT} clean
	rm -rf ${OBJS}
	rm -rf ${OBJS_DIR}

fclean: clean
	${LIBFT} fclean
	${RM} ${NAME}
	${RM} ${NAME}.DYSM

re: fclean all

phony: all bonus clean fclean re
