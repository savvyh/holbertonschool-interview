# UTF-8 Validation

## Description

Write a method that determines if a given data set represents a valid UTF-8 encoding.

## Requirements

## Resources

**Read or watch**:

*   [UTF-8](/rltoken/cvaC6w9wAdmRtVQM-lzAsQ "UTF-8")
*   [Characters, Symbols, and the Unicode Miracle](/rltoken/9C_CG2C5b0possXXcEt0uA "Characters, Symbols, and the Unicode Miracle")

## Requirements

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
*   All your files should end with a new line
*   The first line of all your files should be exactly `#!/usr/bin/python3`
*   A `README.md` file, at the root of the folder of the project, is mandatory
*   Your code should use the `PEP 8` style (version 1.7.x)
*   All your files must be executable

## Tasks

### 1.

Write a method that determines if a given data set represents a valid UTF-8 encoding.

*   Prototype: `def validUTF8(data)`
*   Return: `True` if data is a valid UTF-8 encoding, else return `False`
*   A character in UTF-8 can be 1 to 4 bytes long
*   The data set can contain multiple characters
*   The data will be represented by a list of integers
*   Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer
```
carrie@ubuntu:~/utf8\_validation$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = \_\_import\_\_('0-validate\_utf8').validUTF8

data = \[65\]
print(validUTF8(data))

data = \[80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33\]
print(validUTF8(data))

data = \[229, 65, 127, 256\]
print(validUTF8(data))

carrie@ubuntu:~/utf8\_validation$

carrie@ubuntu:~/utf8\_validation$ ./0-main.py
True
True
False
carrie@ubuntu:~/utf8\_validation$
```