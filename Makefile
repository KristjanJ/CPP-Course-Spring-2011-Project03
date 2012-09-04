# To compile, run 'make' in the same directory as this file

############################
# Settings for the library #
############################

# Needed at least for math.ut.ee server
CXX = g++

# Compiler flags (-Wall shows all warnings when compiling, always use this!)
# -Idir specifies, that there are includes in the 'dir' directory
LIB_CPPFLAGS = -Wall -Iinclude

# List of objects for the library
LIBOBJS = obj/vector.o obj/line.o obj/sphere.o obj/polygon.o
LIBOBJS2 = obj/issquare.o obj/randomnumbergenerator.o obj/sumelements.o

# Name of the library
LIBRARY = lib/libgeometry.a
LIBRARY2 = lib/libmyfunctors.a

################################
# Settings for the testing app #
################################

# Compiler flags for the pp
APP_CPPFLAGS = -Wall -Iinclude

# Linker flags (order the compiler to link with our library)
LFLAGS = -Llib -lgeometry -lmyfunctors

# The object for the testing app
TESTOBJS = obj/geometrytest.o
TESTOBJS2 = obj/fulltest.o

# The name of the testing app
TESTAPP = bin/geometrytest
TESTAPP2 = bin/fulltest

# This is the first target. It will be built when you run 'make' or 'make all'
all: $(LIBRARY) $(LIBRARY2)

# Create the library by using 'ar'
$(LIBRARY) : $(LIBOBJS)
	ar cr $(LIBRARY) $(LIBOBJS)

$(LIBRARY2) : $(LIBOBJS2)
	ar cr $(LIBRARY2) $(LIBOBJS2)

# Compile each source file of the librar
obj/vector.o: src/vector.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/vector.cpp -o obj/vector.o

obj/line.o: src/line.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/line.cpp -o obj/line.o

obj/sphere.o: src/sphere.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/sphere.cpp -o obj/sphere.o

obj/polygon.o: src/polygon.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/polygon.cpp -o obj/polygon.o

obj/issquare.o: src/issquare.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/issquare.cpp -o obj/issquare.o

obj/randomnumbergenerator.o: src/randomnumbergenerator.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/randomnumbergenerator.cpp -o obj/randomnumbergenerator.o

obj/sumelements.o: src/sumelements.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/sumelements.cpp -o obj/sumelements.o

# Rule for linking the test app with our library
$(TESTAPP): $(TESTOBJS)
	$(CXX) $(TESTOBJS) -o $(TESTAPP) $(LFLAGS)
$(TESTAPP2): $(TESTOBJS2)
	$(CXX) $(TESTOBJS2) -o $(TESTAPP2) $(LFLAGS) 

# Compile each source file of the library
obj/geometrytest.o: tests/geometrytest.cpp
	$(CXX) $(APP_CPPFLAGS) -c tests/geometrytest.cpp -o obj/geometrytest.o
obj/fulltest.o: tests/fulltest.cpp
	$(CXX) $(APP_CPPFLAGS) -c tests/fulltest.cpp -o obj/fulltest.o 

test: all $(TESTAPP) $(TESTAPP2)

doc:
	doxygen

clean:
	rm -f $(LIBOBJS)
	rm -f $(LIBOBJS2)
	rm -f $(TESTOBJS)
	rm -f $(TESTOBJS2)
	rm -f $(LIBRARY)
	rm -f $(LIBRARY2)
	rm -f $(TESTAPP)
	rm -f $(TESTAPP2)
	rm -rf docs/html
