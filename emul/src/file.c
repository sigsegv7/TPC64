/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#include <sys/mman.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "emul/file.h"

/*
 * Convert open(2) flags to memory map protection
 * flags
 *
 * @oflags: Flags to convert
 */
static inline int
oflags_to_prot(int oflags)
{
    int prot = PROT_READ;

    if ((oflags & O_WRONLY) != 0)
        prot |= PROT_WRITE;
    if ((oflags & O_RDWR) != 0)
        prot |= PROT_WRITE;

    return prot;
}

int
emul_file_open(const char *name, int flags, struct emul_file *res)
{
    if (name == NULL || res == NULL) {
        errno = -EINVAL;
        return -1;
    }

    res->fd = open(name, flags);
    if (res->fd < 0) {
        return -1;
    }

    /* Obtain the file size */
    res->size = lseek(res->fd, 0, SEEK_END);
    lseek(res->fd, 0, SEEK_SET);

    res->data = mmap(
        NULL,
        res->size,
        oflags_to_prot(flags),
        MAP_SHARED,
        res->fd,
        0
    );

    if (res->data == NULL) {
        close(res->fd);
        return -1;
    }

    return 0;
}

void
emul_file_close(struct emul_file *file)
{
    if (file == NULL) {
        return;
    }

    munmap(file->data, file->size);
    close(file->fd);

    file->data = NULL;
    file->fd = -1;
}
