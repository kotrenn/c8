YACC="bison"

FLAGS = -O0 -g -Wall -Wextra
#FLAGS = -O3 -Wall -Wextra

int_src := $(wildcard interpret/*.cpp)
int_obj := $(int_src:interpret/%.cpp=interpret/%.o)

c8: main.cpp lex.yy.c c8.tab.c $(int_obj)
#	g++ -g -o c8 main.cpp interpret/*.cpp -Wall
	g++ -o c8 main.cpp $(int_obj) -Wall $(FLAGS)
#	g++ -o c8 main.cpp -Wall

$(int_obj): interpret/%.o: interpret/%.cpp
	g++ $(FLAGS) -c -o $@ $<

#lex.yy.c: c8.l c8.tab.h c8.y
lex.yy.c: c8.l c8.y
	flex c8.l

c8.tab.c: c8.y
	bison c8.y --verbose

