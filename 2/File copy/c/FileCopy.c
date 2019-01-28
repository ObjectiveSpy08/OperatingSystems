#include<stdio.h>
#include<fcntl.h>
#include<unistd.h> // For ssize_t

#define BUFFER_SIZE 4096
// https://www.quora.com/Why-is-buffer-size-set-in-a-C-program

int main(int argc, char* argv[]) {
	int fin, fout;
	ssize_t ret_in, ret_out; // https://jameshfisher.com/2017/02/22/ssize_t.html
	char buffer[BUFFER_SIZE];

	if(argc != 3) {
		printf("Usage: FileCopy source destination");
		return 0;
	}

	fin = open(argv[1], O_RDONLY); // Read only

	if(fin == -1) {
		perror("Source file open error");
		return 0;
	}

	fout = open(argv[2], O_WRONLY | O_CREAT, 0644); // Write only bitwise OR with create if not exist; give permission to write.
	 // http://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html
	
	if(fout == -1) {
		perror("Destination file opening/creating issue");
		return 0;
	}

	while((ret_in = read(fin, &buffer, BUFFER_SIZE)) > 0) { // http://man7.org/linux/man-pages/man2/read.2.html
		ret_out = write(fout, &buffer, ret_in); // http://man7.org/linux/man-pages/man2/write.2.html
		if(ret_in != ret_out) {
			perror("Error copying");
			return 0;
		}
	}

	close(fin);
	close(fout);

	return 1;
}
