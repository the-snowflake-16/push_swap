NAME = push_swap

SRC_DIR = src
INCLUDE_DIR = include

FLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I $(INCLUDE_DIR)
COMPILE = $(CC) $(FLAGS) $(CPPFLAGS)

SOURCE = $(wildcard $(SRC_DIR)/*.c)
OBJECT = $(patsubst $(SRC_DIR)/*.c, *o, $(SOURCE))

all: create

create: $(OBJECT)
	$(COMPILE) $(OBJECT) -o $(NAME)

clean:
	rm -f $(NAME)
	rm -f *.o 

re: clean all

%.o: src/%.c 
	$(COMPILE) -c $< -o $@

.PHONY: create clean re