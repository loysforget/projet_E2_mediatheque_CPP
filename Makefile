
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

main: $(OBJS)
	g++ -Wall -std=c++11 -o main $(OBJS) -lm

%.o: %.cpp
	g++ -Wall -std=c++11 -c $< -o $@

clean:rm $(OBJS)

