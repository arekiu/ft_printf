# libftprintf.a

## Description
`libftprintf.a` is a custom implementation of the `printf()` function from the C standard library. This project involves writing a library that includes the `ft_printf()` function, which mimics the behavior of the original `printf()` function, handling various format specifiers.

## Project Structure
- **Program Name:** libftprintf.a
- **Turn in Files:** `Makefile`, `*.h`, `*/*.h`, `*.c`, `*/*.c`
- **Makefile Targets:** `NAME`, `all`, `clean`, `fclean`, `re`
- **External Functions:** `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
- **Libft Authorized:** Yes

## Requirements
- The `ft_printf()` function must handle the following conversions:
  - `%c` - Prints a single character.
  - `%s` - Prints a string.
  - `%p` - Prints a pointer in hexadecimal format.
  - `%d` - Prints a decimal (base 10) number.
  - `%i` - Prints an integer in base 10.
  - `%u` - Prints an unsigned decimal (base 10) number.
  - `%x` - Prints a number in hexadecimal (base 16) lowercase format.
  - `%X` - Prints a number in hexadecimal (base 16) uppercase format.
  - `%%` - Prints a percent sign.
