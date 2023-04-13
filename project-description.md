# 1 - Description

This was the final assignment of the Algorithms and Programming II,
it consists of the implementation of a system for managing students
from a given subject. Each student has the following info:

- Name (cannot have special characters)
- RGA (Integer)
- Grade of the first test
- Grade of the second test
- Grade of the assignment
- Grade of the optional test

All grades must be represented using floating point numbers (use the double type). The final grade is calculated according to the following formula:

$$ FG = 0.35 \* test1 + 0.35 \* test2 + 0.3 \* assignment $$

Do not forget the the grade of the optional test may replace the lowest grade of the other tests (test1 or test2), if it’s bigger than the test’s grade. The studend whose final grade is bigger or equal to 6.0 will have passed, otherwise, will have failed.

During the execution of the program, an ordered array of structs must be used (the order will be based on the names of the students, in case of 2 or more students with the same name, deal with the "tie" placing the student with the lowest RGA before the others).

Your application must show a menu with the following options:

1. **Register student**: inserts a new student in the list with the data given as input by the user. The user must provide data for all the fields of a student (if the optional test wasn’t taken, then the user must provide a 0).

2. **Search student**: asks for the user a string and lists the names, final grade and situation (passed or failed) of all students whose names match (completely or partially) with the given string. The list must show, in the end, the number of results found.

3. **Read file with students list**: asks for the user the name of a text file containing the students’ data. this file will contain the data of, at max, one student per line and, in each line, _all the data_ of the student must be given in the same order described in the student struct description. If the student did not take the optional test, the file must have the grade 0 in the appropriate place. At the end of reading the file, the user must be informed how many students were registered. _See section 3 for more information about the file formatting._

4. **Generate file with approved students’ data, alphabetically ordered**: writes a text file containing the names, RGAs and final grades of the students that passed, one student per line. The students within the generated file must be in alphabetical order (Obs. in case there are 2 or more students with the same name, deal with the "tie" by placing the student with the lowest RGA before the others). At the end of the file, there must be a line with the number of students that passed. The name of the file must be _passed.txt_. _See section 4 for more information about the file formatting._

5. **Generate file with failed students’ data**: writes a text file containing the names and final grade of the students that failed, one student per line. The students within the generated file must be in alphabetical order (Obs. in case there are 2 or more students with the same name, deal with the "tie" by placing the student with the lowest RGA before the others). At the end of the file, there must be a line with the number of students that failed. The name of the file must be _failed.txt_. _See section 4 for more information about the file formatting._

6. **Exit**: Closes the program. Before closing, save all data of the studens in a file called _actual.txt_, storing one student per line, with the data fields separated by space and in the order they were presented in section 1.

The sorting algorithm to be used must be one of the following:

- insertion sort
- selection sort

# 2 - Execution

The program must start by showing the options menu. The user may choose any of the options and, based on the user’s choice, the system must perform the desired function.

Both methods of registering students, individually or by input file, must provide data for all fields of the student struct.

# 3 - Input File Formatting

The input files for the options that require reading a file will have **one line for each student** to be registered. Each line will have every single field for a given student and is finished with a new line character (\n)

The fields that must be considered are _only_ those described in section 1 and in the _same order_.

# 4 - Output File Formatting

The output files for the options that require writing to a file must contain **one line for each student**. Each line will have data following the description of the options 4 and 5 of the menu. In the end there must be a line with the quantity of students following the format:

`Total: count`

In which _count_ is the number of passed or failed students, according to the chosen option.

At the end of each line there must be a new line character (\n)

# 5 - Especifications

- The assignment must be implemented using the C/C++ languages. You must create your application using two or more .cpp files (with the help of .h files). One of them must only have the main function while the other(s) will contain all of the other functions used by the program.
- The input files will be stored in the same folder as the source code.
- The output files must be created in the same folder as the source code.
