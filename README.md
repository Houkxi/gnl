# Get_next_line

## Grade		122	/100

### Mandatory	100	/100
## Bonus		22	/25

## Description

Code a fonction that will read from a FDm retrieve the content line by line and return the line. Usually used in a loop.

Example of use :

```C
fd = open(a_file_to_read, O_RDONLY);
while (get_next_line(fd, &line) > 0)
{
	save_line = line;
	ft_strdel(&line);
}
```

This is to get all the lines from an input file.
Under no circumstances will the function quit unexpectedly (Segmentation fault, bus error, double free, etc).
There will be no leaks (*Thus the ft_strdel()*).
