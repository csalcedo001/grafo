bin/main: $(patsubst lib/%.cpp, build/%.o, $(wildcard lib/*))
	g++ -std=c++17 src/main.cpp -I include -o $@ $^

build/%.o: lib/%.cpp include/%.h
	g++ -std=c++17 -c $< -I include -o $@

clean:
	rm build/*
	rm bin/*
