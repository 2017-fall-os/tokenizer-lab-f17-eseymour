# Lab 1: Tokenizer

- [Building](#building)
- [Usage](#usage)
- [Source Structure](#source-structure)
  - [`mytok`](#mytok)
  - [`token`](#token)
  - [`tokenizer`](#tokenizer)
  - [`minunit`](#minunit)
  - [`token_test`](#token_test)


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

## Usage

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

## Source Structure

### `mytok`

Contains the implementation of the tokenizer function  `mytok(char *str, char delim)`.

### `token`

Contains useful functions helpful for tokenization.

### `tokenizer`

Defines the simple application for interacting with the tokenizer.

### `minunit`

Simple unit testing header modified to be more verbose.

### `token_test`

Contains all the unit tests and provides a simple test harness.

