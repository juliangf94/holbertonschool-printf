holbertonschool-printf

# Recreating the printf function:
    This project consists of recreating the C standard library function `printf`. The goal is to understand how formatted output works internally by handling various format specifiers, managing variable arguments, and producing output exactly like the original function. Through this project, we explore low-level programming concepts such as buffers, variadic functions, and string manipulation.

# Project Goals:
	Our function is designed to produce output according to a specified format string, writing to stdout. The current implementation handles the following mandatory conversion specifiers:
		%c  Prints a single character.
		%s  Prints a string of characters.
		%d  Prints a signed decimal integer.
		%i  Prints a signed integer.
		%%  Prints a percent sign.

<!-- Exemple d'utilisation -->
Usage:
	The function prototype is:
		int _printf(const char *format, ...);
		It returns the number of characters printed (excluding the null byte).

<!-- Requierements + environement de  travail-->
Design and Structure:
	For this project we used git and gcc on Ubuntu 20.04 LTS, it also follows a design to adhere to the Betty style guide.

Core Files:
	main.h: Contains all function prototypes and the definition of the fmt_t structure.
	man_3_printf: The manual page for the _printf function.

<!-- Compilation command -->
##
Compilation:
	The code is compiled on Ubuntu 20.04 LTS using gcc with the following flags:
		gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

<!-- Exemple de tests avec resultats attendus + valgreed + valleur de retour -->

## Man page
The dedicated `man_3_printf` page will be added once every mandatory conversion is implemented

# Flowchart of the _printf Function
The following flowchart illustrates the main logic loop of the function, from the start to the processing of the characters and format specifiers.
```mermaid

flowchart TB
    A["Start"] --> B[/"input: char, string, percent, decimal or int"/]
    A --> C["int _printf(const char *format, ...);"]
    B --> D["Initialize sum = 0 to keep track of everything printed."]
    D --> E["va_list, va_start(ap, format)"]
    %%E --> F{"Is format == NULL?"}
        %% NULL check
        %% F -- YES --> G[/"return (-1)"/]
        E --> AA(["Loop: i = 0, format[i] != '\\0', i++"])
            %% Loop start
            AA -- format[i] != '\0'--> AB{"Is format[i] a directive (%)?"}
                %% Directive found
                AB -- YES --> AC["i++ (move i to specifier)"]
                AC --> ACA["update the character count (sum) with select_type function"]
                        ACA --> AD{"Which specifier is it? c, s, %, i or d"}
                            AD --> AE["'c' print a character"] & AF["'s' print a string"] & AG["'%' print an percent"] & AH["'d' print a decimal"] & AI["'i' print an int"]
                            AE --> AJ(("Keeps track of sum"))
                            AF --> AJ
                            AG --> AJ
                            AH --> AJ
                            AI --> AJ
                            AJ --> AA
                %% Directive not found, prints regular character
                AB -- NO --> BA["_putchar(format[i])"]
                BA --> BB{"sum++ (keep track of sum)" }
                    BB --> AA
            %% Loop End    
            AA -- format[i] == '\0'--> H["va_end(ap)"]
            H --> I[/"Return (sum);"/]

    %% Style
    classDef start fill:#EB892D,stroke:#1D4ED8,stroke-width:3px,color:white, font-size:16px;
    classDef process fill:#079C40,stroke:#1D4ED8,stroke-width:3px,color:white, font-size:16px;
    classDef data fill:#8FABFA,stroke:#1D4ED8,stroke-width:3px,color:white, font-size:15px;
    classDef loop fill:#F42E0B,stroke:#1D4ED8,stroke-width:3px,color:white, font-size:16px;
    classDef decision fill:#BE22DD,stroke:#1D4ED8,stroke-width:3px,color:white, font-size:16px;
    classDef connector fill:#F2F527,stroke:#1D4ED8,stroke-width:3px,color:#1E3A8A, font-size:18px;

    class A start;
    class C,D,E,AC,ACA,AE,AF,AG,AH,AI,BA,H process;
    class AA loop;
    class B,G,I data;
    class F,AB,AD,BB decision;
    class AJ connector;
```
