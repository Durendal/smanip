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
