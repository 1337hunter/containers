clang++ -std=c++98 -g -fsanitize=address -Wall -Wextra -Werror main.cpp list_test.cpp vector_test.cpp stack_test.cpp \
	map_test.cpp queue_test.cpp -o stltest
./stltest
diff -u sd ft
