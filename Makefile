# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerbs <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 17:54:30 by jerbs             #+#    #+#              #
#    Updated: 2020/01/31 14:01:03 by jerbs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
FLAGS = -Wall -Werror -Wextra
SRC_PS = ./PUSH_SWAP/*.c
SRC_CK = ./CHECKER/*.c
O_PS = ps_ofiles
O_CK = ck_ofiles

.C = *.c
.O = *.o

all: $(CHECKER) $(PUSH_SWAP)

$(PUSH_SWAP):
	gcc -I./PUSH_SWAP $(FLAGS) -c $(SRC_PS)
	gcc -o $(PUSH_SWAP) $(.O)
	mkdir -p $(O_PS)
	@mv $(.O) $(O_PS)

$(CHECKER):
	gcc -I./CHECKER $(FLAGS) -c $(SRC_CK)
	gcc -o $(CHECKER) $(.O)
	mkdir -p $(O_CK)
	@mv $(.O) $(O_CK)

clean:
	rm -rf $(O_PS) 
	rm -rf $(O_CK) 

fclean:	clean
	rm -rf $(CHECKER)
	rm -rf $(PUSH_SWAP)

re:	fclean all

.PHONY: clean fclean re all
