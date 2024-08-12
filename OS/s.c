#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static char message[] = "hai Hello world";

int main() {
    int fd;
    char buffer[80];

    // Attempt to open the file with the specified flags and permissions
    fd = open("IOSytemCall_file.txt", O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);

    // Check if the file was opened successfully
    if (fd != -1) {
        printf("IOSytemCall_file.txt opened for read/write access\n");

        // Write the message to the file
        if (write(fd, message, sizeof(message)) != sizeof(message)) {
            perror("Error writing to the file");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Move the file pointer to the beginning of the file
        if (lseek(fd, 0L, SEEK_SET) == -1) {
            perror("Error seeking to the beginning of the file");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Read the content from the file into the buffer
        if (read(fd, buffer, sizeof(message)) == sizeof(message)) {
            printf("\"%s\" was written to IOSytemCall_file.txt\n", buffer);
        } else {
            perror("Error reading the file");
        }

        // Close the file descriptor
        if (close(fd) == -1) {
            perror("Error closing the file");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    return 0;
}

