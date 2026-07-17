CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp AppManager.cpp Page1.cpp Page2.cpp Shape.cpp ShapeFactory.cpp CircleShapeObj.cpp RectangleShapeObj.cpp TriangleShapeObj.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = pages2

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
