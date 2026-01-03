#include <stdio.h>
#include "elf_loader.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <elf-file>\n", argv[0])
		return 1;
	}
	if (load_elf(argv[1]) != 0) {
		printf("Failed to analyze ELF file.\n");
		return 1;
	}
	return 0;
}
