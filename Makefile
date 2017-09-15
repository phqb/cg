SDIR = src
ODIR = obj
CC = g++
LIBS = -lm
OPTS = -Wall

_DEPS = circle.cpp compare.cpp halfplane.cpp line_2.cpp point_2.cpp convex_polygon.cpp ray_2.cpp segment_2.cpp vector_2.cpp union.cpp triangle.cpp
DEPS = $(patsubst %,$(SDIR)/%,$(_DEPS))

_TEST_DEPS = utils.cpp
TEST_DEPS = $(patsubst %,$(SDIR)/%,$(_TEST_DEPS))

HELLO_OBJ = main.o
TEST_OBJ = run_test.o

HELLO_OBJ_WIN = main.exe
TEST_OBJ_WIN = run_test.exe

hello:
	$(CC) -o $(ODIR)/$(HELLO_OBJ) src/main.cpp $(DEPS) $(LIBS) $(OPTS)

test:
	$(CC) -o test/$(TEST_OBJ) test/run_test.cpp $(DEPS) $(TEST_DEPS) $(LIBS) $(OPTS)

run_test: test
	@./test/$(TEST_OBJ)

hello_win:
	$(CC) -o $(ODIR)/$(HELLO_OBJ_WIN) src/main.cpp $(DEPS) $(LIBS) $(OPTS)

test_win:
	$(CC) -o test/$(TEST_OBJ_WIN) test/run_test.cpp $(DEPS) $(TEST_DEPS) $(LIBS) $(OPTS)

run_test_win: test
	@./test/$(TEST_OBJ_WIN)