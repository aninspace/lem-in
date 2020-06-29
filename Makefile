# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 13:14:23 by fmelda            #+#    #+#              #
#    Updated: 2020/05/27 13:43:05 by anastasiase      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		lem-in

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		sources
HDR_DIR	=		includes
OBJ_DIR	=		objs

# ------------  LIBFT  ------------------------------------------------------- #
LFT		=		libft.a
LFT_DIR	=		libft
LHS_DIR	=		$(LFT_DIR)

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS	=		main.c \
				read_map.c \
				tools.c \
				check_duplicate.c \
				match.c \
				parse.c \
				algo_deixtra.c \
				change_graph_weight.c \
				find_way.c \
				link_name_with_dashes.c \
				check_duplicate_room_in_path.c \
				tools2.c \
				swap_path.c \
				find_step_of_ants.c \
				init_variables.c \
				init_struct.c \
				extra_init.c \
				parse_room.c \
				free.c \
				free2.c \
				parse_link.c \
				check_valid_path.c \
				tools_for_step.c \
				extra_init2.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		gcc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
IFLGS	=		-I $(HDR_DIR) -I $(LHS_DIR)
LFLGS	=		-L $(LFT_DIR) -lft
DFLGS	=		-MMD -MP
DEBUG	=		-g

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME)

$(LFT_DIR)/$(LFT):
	@echo "\x1b[1m\nBuilding $(LIBFT) library...\x1b[0m"
	$(MAKE) -C $(LFT_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLGS) -g -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(OBJS)
	@echo "\x1b[1m\nBuilding $(NAME)...\x1b[0m"
	$(CC) $(CFLGS) -g -o $(NAME) $(OBJS) $(LFLGS)

clean:
	@echo "\x1b[1m\nCleaning...\x1b[0m"
	$(MAKE) -C $(LFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
