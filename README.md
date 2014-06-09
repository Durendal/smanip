smanip
======

Basic String Manipulation functions written in C

Functions:

    strtolower(string, length)
      will iterate through string, length times and run each char through tolower()
    strtoupper(string, length)
      will iterate through string, length times and run each char through toupper()
    strpos(haystack, needle)
      searches haystack for an instance of needle, and returns the position that the sequence begins at(or -1 if it fails to find an instance)
    substr(string, start, length, string_length)
      returns a substring of string, length characters long, beginning at position start. String_length is included to ensure that the length of data returned cannot exceed the actual string length.
    str_replace(string, substring, replace)
    
    
smanip.h attempts to provide some simpler to use string manipulation functions, attempting to be as similar as possible to functions familiar to PHP developers. By building base functions such as substr and strpos Im hoping to be able to replicate Mike Schrenks LIB_parse.php from his book 'web bots, spiders, and screenscrapers' (nostarch press). Once the library is completed it will be sent to him for approval. 
