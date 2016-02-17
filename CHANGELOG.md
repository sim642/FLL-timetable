### Unreleased
Removed:
* Python version

### v1.4.0 - 2016-01-25
Added:
* Parent Block support in C++
* Constraint to force blocks to be after other blocks for Team

Fixed:
* CodeBlocks project file being out of date

### v1.3.1 - 2016-01-22
Changed:
* MultiGenerator cancels all other threads if generation was successful

Fixed:
* Segmentation fault with indivisible number of teams

### v1.3.0 - 2016-01-22
Added:
* C++ classes for per Block output

Changed:
* Made outputters abstract
* Threads to be identifiable by index, not ID

### v1.2.0 - 2016-01-22
Added:
* Ability to configure random probing discard rate

Changed:
* State to be properly copied
* MultiGenerator to actually run multiple threads for generation

### v1.1.1 - 2016-01-22
Added:
* State structure
* MultiGenerator to run multiple generators

Changed:
* Made generators abstract

### v1.1.0 - 2016-01-22
Added:
* Faster timetable generation using partial random probing
* Automatic generation retry until successful
* Time taken measurement

### v1.0.0 - 2016-01-22
Added:
* C++ classes for CSV input and output
* C++ port of Python code

### v0.3.0 - 2016-01-21
Added:
* Parent Block support for consecutive Blocks
* More flexible per Block output file naming

### v0.2.0 - 2016-01-21
Added:
* Output to CSV per Team and Block
* Time conflict checking

### v0.1.0 - 2016-01-21
Added:
* Team, Block and Row structures
* Teams and Blocks input from CSV
* Primitive timetable generation without constraints
