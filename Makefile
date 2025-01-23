NAME = push_swap

SRC_DIR = src
INCLUDE_DIR = include

FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I $(INCLUDE_DIR)
COMPILE = $(CC) $(FLAGS) $(CPPFLAGS)

SOURCE = $(wildcard $(SRC_DIR)/*.c)
OBJECT = $(patsubst $(SRC_DIR)/*.c, $(SRC_DIR)/*o, $(SOURCE))

all: create

create: $(OBJECT)
	$(COMPILE) $(OBJECT) -o $(NAME)

clean:
	rm -f $(SRC_DIR)/$(NAME)
	rm -f $(SRC_DIR)/*.o 

re: clean all

%.o: src/%.c 
	$(COMPILE) -c $< -o $@

.PHONY: create clean re