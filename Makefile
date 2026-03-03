# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# All targets
all: matrixTest trajectory affine

# Build matrixTest
matrixTest: matrix.o matrix_test.o
	$(CXX) $(CXXFLAGS) -o matrixTest matrix.o matrix_test.o

# Build trajectory
trajectory: matrix.o trajectory.o
	$(CXX) $(CXXFLAGS) -o trajectory matrix.o trajectory.o

# Build affine
affine: matrix.o affine.o
	$(CXX) $(CXXFLAGS) -o affine matrix.o affine.o

# Compile object files
matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp

matrix_test.o: matrix_test.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix_test.cpp

trajectory.o: trajectory.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c trajectory.cpp

affine.o: affine.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c affine.cpp

# Clean
clean:
	rm -f *.o matrixTest trajectory affine
