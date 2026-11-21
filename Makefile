CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LIBS = 

tareas: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o tareas $(LIBS)

run: tareas
	./tareas

clean:
	rm -f tareas
