#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char** argv) {
	if (argc > 2)
	{
		printf("%s\n%s\n\n___________\n", argv[1], argv[2]);
		int fd1 = open(argv[1], O_RDONLY);
		int fd2 = open(argv[2], O_RDONLY);
		char *line1 = get_next_line(fd1);
		char *line2 = get_next_line(fd2);

		while (line1 || line2)
		{
			/*printf("fd1: %s\nfd2: %s\n", line1, line2);*/
			free(line1);
			free(line2);
			line1 = get_next_line(fd1);
			line2 = get_next_line(fd2);
		}
	}
	return 0;
}
