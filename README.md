# Pipex

Pipex is a C programming project that emulates the behavior of a UNIX pipeline. It accepts four arguments: two file names and two shell commands, and executes them in a pipeline manner.

## Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

- GCC compiler
- Make

### Installation

1. Clone the repo
   ```
   git clone https://github.com/your_username_/pipex.git
   ```
2. Compile the project
   ```
   make
   ```

## Usage

Run the program with the following command:
```
./pipex infile "command1" "command2" outfile
```
This will execute the commands as if you were running:
```
< infile command1 | command2 > outfile
```
in a UNIX shell.

## Project Structure

The project has the following structure:

- `src/pipex.c`: Main file of the application. It contains the main function which accepts command line arguments and uses them to execute the pipex program.
- `src/utils.c`: Contains utility functions used in `pipex.c`.
- `src/utils.h`: Header file for `utils.c`.
- `Makefile`: Used to compile the project.
- `libft/ft_strlen.c`, `libft/ft_strdup.c`, `libft/ft_strjoin.c`, `libft/ft_split.c`: Part of the libft library. They contain implementations of some standard C library functions.
- `libft/libft.h`: Header file for the libft library.

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Contact

Your Name - rubendfraga@gmail.com

Project Link: [https://github.com/rubendiazzz_/pipex](https://github.com/rubendiazzz_/pipex)
