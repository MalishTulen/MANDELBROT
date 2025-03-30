# ���������� � �����
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# ��� ������������ �����
TARGET = sfml_app

# �������� �����
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# ������� ������
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp picun.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
