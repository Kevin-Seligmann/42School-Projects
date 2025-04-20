#!bin/sh

make -C ..

c++ -I../inc -Wall -Wextra -Werror -c client_test.cpp -o client_test.o

c++ -I../inc -Wall -Wextra -Werror -c server_test.cpp -o server_test.o

c++  client_test.o ../libftpp.a -o client

c++  server_test.o ../libftpp.a -o server
