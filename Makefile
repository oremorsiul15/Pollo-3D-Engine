CFLAGS = -std=c++17 -I. -I/Users/luisromero/VulkanSDK/1.3.239.0/macOS/include
LDFLAGS = -L/Users/luisromero/VulkanSDK/1.3.239.0/macOS/lib `pkg-config --static --libs glfw3` -lvulkan

build: *.cpp *.hpp
	g++ $(CFLAGS) -o Pollo_3D *.cpp $(LDFLAGS)

run: build test

.PHONY: test clean

test:
	./Pollo_3D

clean:
	rm -f Pollo_3D

compile:
	./compile.sh