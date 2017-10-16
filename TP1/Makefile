SRC = $(shell find . -name "*.cpp")
BIN = $(SRC:.cpp=.out)

.PHONY: all clean

all: $(BIN)
	@echo "run with:./MyProg -c/-d myText.txt myKey"

%.out: %.cpp
	g++ -std=c++11 -Wall -Wextra -Wno-literal-suffix -O2 -o $@ $< 

clean:
	rm $(BIN)
