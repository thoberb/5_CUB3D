# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 10:01:14 by bberthod          #+#    #+#              #
#    Updated: 2024/01/15 17:20:31 by bberthod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAR		:= \e[0K

SRED		:= \033[0;31m
SGREEN		:= \033[0;32m
SYELLOW		:= \033[0;33m
SCYAN		:= \033[0;36m
SPURPLE		:= \033[0;35m
SOFF		:= \033[0m

RED			:= '\033[0;31m'
GREEN		:= '\033[0;32m'
YELLOW		:= '\033[0;33m'
CYAN		:= '\033[0;36m'
PURPLE		:= '\033[0;35m'
OFF			:= '\033[0m'

NAME			:= cub3D
INC_DIR			:= includes/
SRCS_DIR		:= srcs/cub_3d/
LIB_DIR			:= ./lib/
OBJS_DIR		:= ./objs/
SRCS_LIBFT_DIR	:= srcs/libft/

MLX_PATH		:= minilibx-linux/
MLX				:= $(MLX_PATH)/libmlx.a

SRCS_LIBFT		:= char/ft_isalnum.c char/ft_isalpha.c char/ft_isascii.c char/ft_isdigit.c \
				char/ft_isprint.c char/ft_tolower.c char/ft_toupper.c char/ft_all_isdigit.c \
				conversion/ft_atoi.c conversion/ft_atoi_long.c conversion/ft_itoa.c \
				malloc/ft_calloc.c malloc/ft_split.c malloc/ft_strdup.c malloc/ft_strjoin.c malloc/ft_strjoin_all.c malloc/ft_strmapi.c \
				malloc/ft_strtrim.c malloc/ft_substr.c mem/ft_bzero.c mem/ft_memchr.c mem/ft_memcmp.c \
				mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c \
				print/ft_putchar_fd.c print/ft_putendl_fd.c print/ft_putnbr_fd.c print/ft_putstr_fd.c \
				string/ft_strchr.c string/ft_striteri.c string/ft_strlcat.c string/ft_strlcpy.c \
				string/ft_strlen.c string/ft_strcmp.c string/ft_strncmp.c string/ft_strnstr.c string/ft_strrchr.c \
				liste_chaine/ft_lstnew.c gnl/get_next_line.c gnl/get_next_line_utils.c\
				liste_chaine/ft_lstadd_front.c liste_chaine/ft_lstsize.c liste_chaine/ft_lstlast.c \
				liste_chaine/ft_lstadd_back.c liste_chaine/ft_lstdelone.c liste_chaine/ft_lstclear.c \
				liste_chaine/ft_lstiter.c liste_chaine/ft_lstmap.c liste_chaine/ft_lstprint_type.c \
				liste_chaine/ft_lstjoin.c math/ft_min.c string/ft_print_strs.c
SRCS_LIBFT		:= ${addprefix ${SRCS_LIBFT_DIR},${SRCS_LIBFT}}

OBJS_LIBFT		:= ${SRCS_LIBFT:.c=.o}
OBJS_LIBFT		:= $(addprefix $(OBJS_DIR),$(OBJS_LIBFT))

SRCS			+= main.c init_data.c parse_map.c free_exit.c parse_fd_lines.c create_rgb.c \
				check_map.c check_player.c load_images.c init_game.c set_hooks.c move_view_player.c \
				draw_map.c h_intersection.c v_intersection.c distance_utils.c render_3d.c render_3d_utils.c

SRCS			:= ${addprefix ${SRCS_DIR},${SRCS}}

OBJS			:= $(SRCS:.c=.o)
OBJS			:= $(addprefix $(OBJS_DIR),$(OBJS))

DEPS			:= ${OBJS:.o=.d} ${OBJS_LIBFT:.o=.d}

AR				:= ar rcs
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -MMD -g3
RM				:= rm -rf
MKDIR			:= mkdir -p

all		: ${NAME} ${NAME_BONUS}

bonus	: ${NAME_BONUS}

${NAME}	: ${OBJS_LIBFT} ${OBJS} $(MLX)
		@${MKDIR} ${LIB_DIR}
		@${AR} ${LIB_DIR}libft.a ${OBJS_LIBFT}
		@${CC} ${CFLAGS} ${OBJS} $(MLX) -I $(INC_DIR) -o ${NAME} -L/usr/include -lXext -lX11 -lm ${LIB_DIR}libft.a
		@printf "\r${CLEAR}${SCYAN}${NAME}${SOFF} ${SGREEN}compiled${SOFF}\n"

$(MLX) :
		make -C $(MLX_PATH)

clean	:
		@${RM} ${OBJS_DIR} ${LIB_DIR}
		@printf "${SYELLOW}All objs and libs ${SRED}deleted ${SOFF}\n"

fclean	: clean
		@${RM} ${NAME} ${NAME_BONUS}
		@printf "${SYELLOW}${NAME}${SRED} deleted${SOFF}\n"

re		: fclean all

.PHONY	: all clean fclean re

$(OBJS_DIR)%.o	: %.c
				@${MKDIR} $(@D)
				@${CC} ${CFLAGS} -c $< -I $(INC_DIR) -o $@

-include $(DEPS)
