#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A handle for a temporary file created with write_temp_file. In
   this implementation, it's just a file descriptor. */
typedef int temp_file_handle;

/* Writes LENGTH bytes from BUFFER into a temporary file. The
   temporary file is immediately unlinked. Returns a handle to the
   temporary file. */
temp_file_handle write_temp_file(char* buffer, size_t length)
{
    /* Create the filename and file. The XXXXXX will be replaced with
       characters that make the filename unique. */
    char temp_filename[] = "/tmp/temp_file.XXXXXX";
    int fd = mkstemp(temp_filename);
    /* Unlink the file immediately, so that it will be removed when the
       file descriptor is closed. */
    unlink(temp_filename);
    /* Write the number of bytes to the file first. */
    write(fd, &length, sizeof(length));

    /* Now write the data itself. */
    write(fd, buffer, length);

    /* Use the file descriptor as the handle for the temporary file. */
    return fd;
}

/* Reads the contents of a temporary file TEMP_FILE created with
   write_temp_file. The return value is a newly allocated buffer of
   those contents, which the caller must deallocate with free.
   *LENGTH is set to the size of the contents, in bytes. The
   temporary file is removed. */
char* read_temp_file(temp_file_handle temp_file, size_t* length)
{
    char* buffer;
    /* The TEMP_FILE handle is a file descriptor to the temporary file. */
    int fd = temp_file;
    /* Rewind to the beginning of the file. */
    lseek(fd, 0, SEEK_SET);
    /* Read the size of the data in the temporary file. */
    read(fd, length, sizeof(*length));
    /* Allocate a buffer and read the data. */
    buffer = (char*)malloc(*length);
    read(fd, buffer, *length);
    /* Close the file descriptor, which will cause the temporary file to
       go away. */
    close(fd);
    return buffer;
}

int main() {
    char data[] = "Hello, World!"; // Datos que se escribirán en el archivo temporal
    size_t data_length = sizeof(data) - 1; // Longitud de los datos

    // Escribir los datos en un archivo temporal
    temp_file_handle temp_file = write_temp_file(data, data_length);
    printf("Datos escritos en el archivo temporal.\n");

    // Leer los datos desde el archivo temporal
    size_t read_length;
    char* read_data = read_temp_file(temp_file, &read_length);
    printf("Datos leídos desde el archivo temporal:\n%s\n", read_data);

    // Liberar la memoria utilizada por el búfer de lectura
    free(read_data);

    return 0;
}
