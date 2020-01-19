Use "g++ main.cpp functions.cpp memory/nvwa/bool_array.cpp memory/nvwa/file_line_reader.cpp memory/nvwa/mmap_reader_base.cpp memory/nvwa/debug_new.cpp memory/nvwa/static_mem_pool.cpp memory/nvwa/mem_pool_base.cpp -o cars" to compile.

Fundamentals of Computer Programming
(18) Cars (max grade: 4.0)

1. The objective of the project is to practise the implementation and application of
dynamic data structures (eg lists, trees etc) and memory management. Using of
dynamic data structures is a sine qua non condition.
2. Application of STL containers (eg vector, list etc) does not fulfil the condition
stated in p. 1.
3. Dynamically allocated arrays do not fulfil the condition stated in p. 1.
4. The std::string type can only be used for strings (eg file names). It is not allowed
to keep sequences of data (eg numbers) as strings.
5. A data structure has to accepted by a laboratory instructor before implementation.
6. Source code has to be split into header (*.h) and source (*.cpp) files.
7. All functions have to be commented in the doxygen style.
8. Any permutation of command line switches has to be handled.

A town hall keeps a list of cars and their owners. Each car has a record:

--- car ---
brand: skoda
model: citigo
year of construction: 2010
engine capacity: 1300
engine number: 45VG342EW34
VIN number: 324987TR854FR321
first registration: 2010-05-03

vehicle registration plates:
2010-05-03 SG12345
2012-11-03 ZS434U
2014-12-05 NOL3421

owners:
2010-05-03 Zbigniew Szpak
2010-12-12 Anna Romaryn
2012-10-04 Teodor Puma
2014-11-15 Elzbieta Fiuk, Grzegorz Fiuk

The program elaborates a report for each owner with all cars possessed now and in the past with car
details and possession period.
This is a command line program with switches:
-i input file
-o output file