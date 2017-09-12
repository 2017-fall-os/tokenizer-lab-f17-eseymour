# Lab 1: Tokenizer

## Building

By default running make will run unit tests then build for release

```shell
make
```

To run unit tests

```shell
make test
```

To build for release

```shell
make release
```

To build for debug

```
make debug
```

To clean

```
make clean
```

## Running

To run the tokenizer application in the directory you built it

```
/path/to/tokenizer: $ ./tokenizer
Tokenizer Lab by Edward Seymour
Type "quit" to quit program.
$ 
```

Once running, the application will give you a prompt and it will tokenize your input

```
$ My dog's name is Darwin.
My
dog's
name
is
Darwin.
$ 
```

To quit the program, simply type `quit`

```
$ quit
/path/to/tokenizer: $
```
