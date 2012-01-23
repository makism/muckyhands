g++ main.cpp muckyhands.cpp httpserver.cpp \
	-o muckyhands -O0 -fno-inline -g3 -Wall \
	-I/opt/cpp-netlib-0.9.2 \
	-I/opt/boost_1_48_0/include \
	-L/opt/boost_1_48_0/lib \
	-L/opt/cpp-netlib-0.9.2/libs/network/src \
	-lboost_system -pthread \
	-lcppnetlib-uri-parsers \
	-lcppnetlib-server-parsers \
	-lboost_program_options 
