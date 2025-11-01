all: build, run

build: 
	g++ -std=c++20 driver.cpp -o driver

run:
	./driver
