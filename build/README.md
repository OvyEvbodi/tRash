# Build and Installation

It can be built and run on any computer with C compiler, and accessed via a [terminal](https://ubuntu.com/tutorials/command-line-for-beginners).

## Installation

Dependencies include `make`, `gcc`, `gzip`, `mandb`. Ensure you have them installed.

- Clone this repository and navigate into the local `tRash/build/` directory

```shell
git clone https://github.com/OvyEvbodi/tRash/ tRash ;
cd tRash/build/ ;
```

- To build `tRash` and run it in the current directory, use the following command:

```shell
make
```

- For the complete installation, and to add `tRash` to a standard location and install
  the [manpage](https://en.wikipedia.org/wiki/Man_page), run:

```shell
make install
```

- To uninstall the `tRash` binary, run:

```shell
make uninstall
```

- For a complete clean of the `tRash` binary as well as all object files, run:

```shell
make clean
```

- For help, checkout the manpage:

```shell
man tRash
```
