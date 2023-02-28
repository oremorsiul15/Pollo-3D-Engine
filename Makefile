CFLAGS = -std=c++17 -I. -I/Users/luisromero/VulkanSDK/1.3.239.0/macOS/include
LDFLAGS = -L/Users/luisromero/VulkanSDK/1.3.239.0/macOS/lib `pkg-config --static --libs glfw3` -lvulkan

build: *.cpp *.hpp
	g++ $(CFLAGS) -o velvet *.cpp $(LDFLAGS)

run: build test

.PHONY: test clean

test:
	./velvet

clean:
	rm -f velvet

compile:
	./compile.sh