CXX = g++
CXXFLAGS = -std=c++11 -pedantic
CXXLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: Hunch

Hunch: Code/Game.o
	$(CXX) $< -o $@ $(CXXLIBS)

Code/%.o: %.cpp
	$(CXX) $< -c -o $@

clean:
	rm Hunch Code/*.o

