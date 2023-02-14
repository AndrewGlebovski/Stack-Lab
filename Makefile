# Путь к компилятору
COMPILER=g++


all: dynamic-stack.exe linked-stack.exe


# Сборка стека основанного на динамическом массиве
dynamic-stack.exe: dynamic-stack.cpp
	$(COMPILER) $^ -o dynamic-stack.exe


# Сборка стека основанного на связном списке
linked-stack.exe: linked-stack.cpp
	$(COMPILER) $^ -o linked-stack.exe
