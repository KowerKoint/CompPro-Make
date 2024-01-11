ifndef CXXFLAGS
	ifeq ($(shell uname),Linux)
		DEBUG_FLAGS = -g -fsanitize=address,undefined -D DEBUG
	else
		DEBUG_FLAGS = -g -ftrapv -D DEBUG -D _GLIBCXX_DEBUG
	endif
	ifdef RELEASE
		CXXFLAGS = -std=gnu++17 -Wall -Wextra -O2 -I ../library -I ../ac-library
	else
		CXXFLAGS = -std=gnu++17 -Wall -Wextra -O2 -I ../library -I ../ac-library $(DEBUG_FLAGS)
	endif
endif
download:
	poetry run oj d $(URL)
build: main
expand:
	poetry run oj-bundle main.cpp -I ../library -I ../ac-library > main_expanded.cpp
run: build
	./main
test: build
	poetry run oj t -c ./main -e 1e-6
submit: test expand
	poetry run oj s main_expanded.cpp -y
force-submit: expand
	poetry run oj s main_expanded.cpp -y
clean:
	$(RM) -r main_expanded.cpp main_expanded test/
