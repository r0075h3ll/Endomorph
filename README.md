### Introduction

Endomorph is a command-line utility, written in C, that can sort byte streams from little-endian to big-endian and vice-versa.

### Installation

![Supported OS](https://img.shields.io/badge/OS-Linux-blue?style=for-the-badge)

```bash
$ git clone https://github.com/r0075h3ll/Endomorph && cd Endomorph
$ make
```

### Usage

> Endomorph can, currently, only process consistent and evenly distributed byte streams with/without whitespaces.

| Option    | Description                    |
| :--------- | :------------------------------ |
| -i        | specify input file             |
| -o        | specify output file            |
| -b        | specify byte step              |
| -w        | delimit output with whitespace |

#### I/O Processing
- `-b` allows you process byte stream(s) in different number systems. To process a binary file, given that 8 symbols(bits) make a byte, following command will do
	```
	endomorph -b 8 -f input.txt -o output.txt
	```

- `-w` is the option that generates output delimited by whitespaces
	```
	input.txt: 1010101111011101

	output.txt: 01 11 01 11 11 10 10 10
	```

#### Example

```
endomorph -b 2 -f input.txt -w -o output.txt
```



Sample `input.txt`:
```
ab cd 9e 7b
11 2d 8a 4e
3e 9b 7f 1c
``` 


Output generated i.e. `output.txt`:

```
7b 9e cd ab 
4e 8a 2d 11 
1c 7f 9b 3e
```

### Future

Here's a non-exhaustive list of features that you can expect or contribute to:
- [x] Process solid(non-whitespaced) byte streams
- [x] Byte delimiter option
- [x] Whitespace inclusion option in output
- [ ] Process data from I/O stream 
- [ ] Mechanism to process discrepant byte streams


Ultimately, all the implemented functions will be accommodated into a static C library.

### Contribution

You can contribute to the project in following ways:
- See the [future](#future)
- Open and/or fix issue(s)
- Create pull request(s)
- Hit me up on <a href="https://x.com/r0075h3ll" target="_blank">x.com</a> with a new idea
