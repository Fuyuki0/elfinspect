#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include "elf_loader.h"

int load_elf(const char* filename) {
	FILE* fp = fopen(filename, "rb");
	if (!fp) {
		perror("fopen");
		return -1;
	}

	Elf64_Ehdr ehdr;
	fread(&ehdr, 1, sizeof(ehdr), fp);

	if (ehdr.e_ident[0] != 0x7f || ehdr.e_ident[1] != 'E' || ehdr.e_ident[2] != 'L' || ehdr.e_ident[3] != 'F') {
		printf("Not an ELF file\n");
		fclose(fp);
		return -1;
	}

	printf("ELF Header: \n");

	printf("	Class: %s\n", ehdr.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("	Endianness: %s\n", ehdr.e_ident[EI_DATA] == ELFCLASS64 ? "Little Endian" : "Big Endian");

	printf("	Entry point: 0x%lx\n", ehdr.e_entry);

	printf("	Machine: ");
	switch (ehdr.e_machine) {
		case EM_X86_64: printf("x86-64\n"); break;
		case EM_386: printf("x86\n"); break;
		case EM_ARM: printf("ARM\n"); break;
		default: printf("Unknown (%d)\n", ehdr.e_machine);
	}
	
	fclose(fp);
	return 0;
}

