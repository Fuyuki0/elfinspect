#include <stdio.h>
#include <elf.h>
#include "elf_info.h"

void print_elf_header(Elf64_Ehdr* ehdr) {
	printf("ELF Header: \n");
	printf("├────── Entry point: 0x%lx\n", ehdr->e_entry);
}

