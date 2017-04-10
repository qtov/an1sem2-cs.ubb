NAME=t
SRC=Builder.cpp Controller/Controller.cpp Model/Activity.cpp Repository/Repository.cpp UI/UI.cpp

all: $(NAME)

$(NAME):
	g++ -o $(NAME) main.cpp $(SRC) -Iheaders/

clean:
	@rm -f $(NAME)

re: clean all
