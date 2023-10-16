### Introduction

Endomorph is a command-line utility, written in C, that converts hexadecimal data from little-endian to big-endian and vice-versa.

### Installation

```bash
$ git clone https://github.com/r0075h3ll/Endomorph && cd Endomorph
$ make
```

### Usage

> Endomorph, currently, can process input files with a pair of hex digits delimited by whitespaces.

```
endomorph -f input.txt -o output.txt

Options:
-i: specify input file
-o: specify output file
```


Example of `input.txt:`
```
ab cd 9e 7b
11 2d 8a 4e
3e 9b 7f 1c
``` 


What output to expect:

```
7b 9e cd ab 
4e 8a 2d 11 
1c 7f 9b 3e
```

### Future

Here's a non-exhaustive list of features that you can expect or contribute to:
- [ ] Process non-whitespaced or solid stream of bytes
- [ ] A byte delimiter option
- [ ] Process data from I/O stream 


Ultimately, all the implemented functions will be accommodated into a static C library.

### Contribution

You can contribute to the project in following ways:
- Open and/or fix issue(s)
- Create pull request(s)
- Hit me up on <a href="https://x.com/r0075h3ll" target="_blank">x.com</a> with a new idea
