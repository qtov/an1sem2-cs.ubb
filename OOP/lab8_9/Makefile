NAME=t
SRC=Builder.cpp Validator.cpp Controller/Controller.cpp Model/Activity.cpp Repository/Repository.cpp UI/UI.cpp Repository/File_Repository.cpp

all: $(NAME)

$(NAME):
	g++ -o $(NAME) main.cpp $(SRC) -Iheaders/

clean:
	@rm -f $(NAME)

re: clean all

cov:
	g++ -o $(NAME) main.cpp $(SRC) --coverage -Iheaders/
	
