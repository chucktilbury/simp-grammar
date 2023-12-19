# simp-grammar
This is the Bison grammar for the Simple language. It's intended to be a template for the hand-written parser.

The Simple programming language is a synthesis of both C and Python. I include what I feel are the best features of both to produce a minimal programming language that is geared toward application developemnt. The actual compiler will output ANSI C that can be compiled and linked with any modern C compiler. The idea is that the Simple compiler will not create incorrect C code. It will catch all errors in the user's input before its output. The C code that is generated is to be as efficient and clean as practical, such that it could be read by a human being.

## Features
The Simple feature set is a intersection of the C and Python feature sets. The below is intended to provide a flavor of what is intended, rathere than a detailed description. In general, any feature or construct that is found in both C and Python is supported by Simple.
### Classes
A class in Simple is basically a C struct that allows methods to be defined in it. Single inheritance is supported by simply combining the parent class into the child and bringing the symbols of the parent into the scope of the child.
### Exceptions
Exceptions are supported using the non-local GOTO feature on C. They work similarly to Python and generate a stack dump when an unhandled exception is encountered.
### Garbage Collection
GC is handled using the Bohem GC library in the runtime code of the generated program.
### No Pointers
If nothing is a pointer then everything is a pointer. They are just abstraced away into the generated C code.
### Formatted Strings
All strings are formatted in Simple. There is no such thing as a "string pointer", but strings can be iterated like a List. See List below. Also, strings in Simple are a class. They have built-in methods that can be called on them and the string type can be inherited to augment its functionality. A string can span multiple lines. The line endings are added to the string. Strings defined using double-quotes can have escape characters in it. Strings defined using single quotes are absolutely literal. All strings undergo substitution when they are accessed. Parameters are substituted where the {} symbol appears in the string.
### Lists and Hashs are supported directly
A list is an ordered array that can contain any type. It is indexed using a count data type. (see below) A Hash is an unordered data structure that is accessed using a (formatted) string as its index. These are native data types that are treated as inheritable classes with methods that are called on them.
### Numbers
A Number is Simple is a double precision float. There is no notion of an integer. 
### Count
A Count is used to index an array. It is equivalent to an unsigned int in C.
### Keywords
Keywords in Simple are not case-sensitive. User-defined symbols are always case-sensitive. All text must be defined in UTF-8.
### Inline blocks
Literal C code can be imbedded into any function defined by Simple. This is mainly to allow an easy way to access external libraries.
### Importing
External libraries can be imported into the current module. Only the symbols are brought in so that they can be linked to this module. Undefined symbols are caught by the Simple compiler, not the underlying compiler.
### Iterators
An iterator is a special function that allows a value to be returned from an iteratable data type. 
