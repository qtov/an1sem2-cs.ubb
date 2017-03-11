FLAGS=-Wall -Werror -Wextra -std=c11
NAME=main.c
EXEC=test
CLASSES=ui/menu.c controller/controller.c validator.c repository/repository.c

all: $(EXEC)

$(EXEC):
	gcc -o $(EXEC) $(NAME) $(CLASSES) $(FLAGS) -Iheaders/

clean:
	@rm -f $(EXEC)

re: clean all
