EXEC=t
SOURCE=controller.c Drug.c DrugList.c repository.c tester.c userinterface.c utils.c

all: $(EXEC)

$(EXEC):
	gcc -o $(EXEC) DrugShop.c $(SOURCE) -Wall -Wextra -Werror -std=c99

clean:
	@rm -f $(EXEC)

re: clean all

