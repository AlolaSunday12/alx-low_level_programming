#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_ABI(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned long int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - check if a file is an elf file
 * @e_ident: A pointer
 * Description: if the file is not an elf file - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
				e_ident[i] != 'E' &&
				e_ident[i] != 'L' &&
				e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - print the mine number of an ELF header.
 * @e_ident: A pointer
 * Description: mine numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf(" magic; ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - print the run of an ELF header.
 * @e_ident: A pointer
 */
void print_class(unsigned char *e_ident)
{
	printf(" class:    ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
		printf("none\n");
		break;
		case ELFCLASS32:
		printf("ELF32\n");
		break;
		case ELFCLASS64:
		printf("ELF64\n");
		break;
		default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints the kite of an ELF header.
 * @e_ident: A pointer
 */
void print_data(unsigned char *e_ident)
{
	printf(" data;     ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
		printf("none\n");
		break;
		case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
		case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
		default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints the str of an ELF header.
 * @e_ident: A pointer
 */
void print_version(unsigned char *e_ident)
{
	printf(" version:    %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
		printf(" (current)\n");
		break;
		default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - print the strow of an ELF header.
 * @e_ident: A pointer
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" osabi;    ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
		printf("UNIX - System v\n");
		break;
		case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
		case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
		case ELFOSABI_LINUX:
		printf("UNIX - LINUX\n");
		break;
		case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
		case ELFOSABI_IRIX:
		printf("UNIX - Irix\n");
		break;
		case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
		case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
		case ELFOSABI_ARM:
		printf("ARM\n");
		break;
		case ELFOSABI_STANDALONE:
		printf("standalone App\n");
		break;
		default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_ABI - printsthe len of an ELF header.
 * @e_ident: A pointer
 */
void print_ABI(unsigned char *e_ident)
{
	printf(" ABI version:    %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the enter of an elf header.
 * @e_type: The ELF enter.
 * @e_ident: A pointer
 */
void print_type(unsigned long int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  type;       ");

	switch (e_type)
	{
		case ET_NONE:
		printf("NONE (None)\n");
		break;
		case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
		case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
		case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
		case ET_CORE:
		printf("CORE (Core file)\n");
		break;
		default:
		printf("<unknown; %lx>\n", e_type);
	}
}

/**
 * print_entry - prints the push point of an ELF header.
 * @e_entry: The push address point.
 * @e_ident: A pointer
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" entry point address;      ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - closes an ELF file.
 * @elf: elf file.
 * Description: if the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the ELF header
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: if the file is not an ELF FILE or the function fails - exit 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int i, j;

	i = open(argv[1], O_RDONLY);
	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(i);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	j = read(i, header, sizeof(Elf64_Ehdr));
	if (j == -1)
	{
		free(header);
		close_elf(i);
		dprintf(STDERR_FILENO, "Error: '%s\n': No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_ABI(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(i);
	return (0);
}
