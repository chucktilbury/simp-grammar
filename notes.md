
These are random notes to help me keep track of things.

* Compound references sometimes reference a data object and sometimes they are expected to reference a type. A type cannot contain array or function references. The parser should check the format of the reference and then simply store it. Actually looking it up happens after the entire file is read. 

**Importing files**
* Scenario 1: The same parser is used to scan imports. When a new file is opened, then a local flag is incremented. When the imported file is finished, then the flag is decremented. While the flag is not zero, only the symbol table is updated so that names can be checked. 
* Scenario 2: Read the whole imported file and emit it with the rest of the code. The advantage to doing that is that the link phase will be simplified. There will only be the one main input file to be parsed because everything else is imported. 

Scenario 1 will be faster, since there is less to compile. That could be very significant, given the speed that Bison runs at. 
Scenario 2 will be simpler because there is no need to write a separate driver to perfom the compile and link of the emitted code. Also, there is no need to manage more than one mode in the parser.