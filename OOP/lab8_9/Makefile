CC=gcc
CXX=g++

EXEC=t
SRCS=main.cpp Builder.cpp Validator.cpp Controller/Controller.cpp Model/Activity.cpp Repository/Repository.cpp UI/UI.cpp Repository/File_Repository.cpp
HEADERS=-Iheaders/

all: $(EXEC)

$(EXEC): main.o Builder.o Validator.o Controller.o Activity.o Repository.o UI.o File_Repository.o
	$(CXX) -o $(EXEC) $(SRCS) $(HEADERS) -coverage

main.o: main.cpp
	$(CXX) -c main.cpp $(HEADERS)

Builder.o: Builder.cpp headers/Builder.h
	$(CXX) -c Builder.cpp $(HEADERS)

Validator.o: Validator.cpp headers/Validator.h
	$(CXX) -c Validator.cpp $(HEADERS)

Controller.o: Controller/Controller.cpp headers/Controller.h
	$(CXX) -c Controller/Controller.cpp $(HEADERS)

Repository.o: Repository/Repository.cpp headers/Repository.h
	$(CXX) -c Repository/Repository.cpp $(HEADERS)

UI.o: UI/UI.cpp headers/UI.h
	$(CXX) -c UI/UI.cpp $(HEADERS)

File_Repository.o: Repository/File_Repository.cpp headers/File_Repository.h
	$(CXX) -c Repository/File_Repository.cpp $(HEADERS)

Activity.o: Model/Activity.cpp headers/Activity.h
	$(CXX) -c Model/Activity.cpp $(HEADERS)

clean:
	rm -f *.o

fclean:
	rm -f $(EXEC)
