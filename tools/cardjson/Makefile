CXX ?= g++
#TODO: remove -Wno-unused-function
CXXFLAGS := -std=c++17 -O2 -Wall -Werror -Wno-unused-function

SRCS := cardjson.cpp

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: cardjson$(EXE)

cardjson$(EXE): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

clean:
	$(RM) cardjson cardjson.exe
