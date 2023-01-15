#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


off_t getFileSize(int fd) {
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        return -1;
    }
    return file_stat.st_size;
}

void nm(const char *file_name) {
    printf("FileName == %s\n", file_name);
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        (void)printf("Can't open file %s\n", file_name);
        return ;
    }
    off_t file_size = getFileSize(fd);
    if (file_size == -1) {
        (void)printf("Can't read size file %s\n", file_name);
        (void)close(fd);
        return;
    }
    (void)printf("File size == %lld\n", file_size);
    void *file = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (!file) {
        printf("Can't mmap file");
        (void)close(fd);
        return;
    }
        
    
    
    (void)munmap(file, file_size);
    (void)close(fd);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    nm(argv[1]);
    return 0;
}
