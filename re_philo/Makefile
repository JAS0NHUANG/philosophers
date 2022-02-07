# **************************************************************************** #
#       COMANDS                                                                #
# **************************************************************************** #
CC			=	gcc
RM			=	rm
AR			=	ar rcs

# **************************************************************************** #
#       TITLE                                                                  #
# **************************************************************************** #
NAME		=	philo

# **************************************************************************** #
#       FLAGS                                                                  #
# **************************************************************************** #
CFLAGS		=	-Wall -Wextra -Werror
PTHREAD		=	-pthread
FSAN		=	-fsanitize=address
DEBUG		=	-g3
FNO_STACK	=	-fno-stack-protector
RF			=	-rf

# **************************************************************************** #
#       SOURCES                                                                #
# **************************************************************************** #
SRCS_DIR	=	srcs

INCS_DIR	=	incs

SRCS		=	philo.c \
				ft_get_info.c \
				ft_print_error.c \
				utils/ft_free_and_exit.c \
				utils/ft_isdigit.c \
				utils/ft_atoi.c \
				utils/ft_get_time_in_ms.c \

INCS		=	philo.h	\

# **************************************************************************** #
#       RULES                                                                  #
# **************************************************************************** #
OBJS		=	$(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

%.o			:	%.c
				$(CC) $(CFLAGS) $(PTHREAD) -I $(INCS_DIR) -c $< -o $@

$(NAME)		:	$(OBJS)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(CFLAGS) $(PTHREAD)

all			:	$(NAME)

philo_check	:	$(OBJS)
				$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(FSAN) $(PTHREAD) $(FNO_STACK)

clean		:
				$(RM) $(RF) $(OBJS)

fclean		:	clean
				$(RM) $(RF) $(NAME) philo_check

re			:	fclean all

# **************************************************************************** #
#       PHONY                                                                  #
# **************************************************************************** #
.PHONY		:	all clean fclean re
