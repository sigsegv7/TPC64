/*
 * Copyright (c) 2026, Ian Moffett.
 * Provided under the BSD-3 clause.
 */

#ifndef EMUL_FILE_H
#define EMUL_FILE_H 1

#include <stdint.h>
#include <stddef.h>

/*
 * Represents an opened file
 *
 * @data: File data
 * @size: Number of bytes in file
 * @fd:   File descriptor of file
 *
 * XXX: Do not touch these fields directly! Use the
 *      helper macros.
 */
struct emul_file {
    void *data;
    size_t size;
    int fd;
};

/* Fields that can be accessed */
#define emul_file_data(file) \
    ((file)->data)
#define emul_file_size(file) \
    ((file)->size)

/*
 * Open a file
 *
 * @name: Name of file
 * @flags: Open flags (see open(2))
 * @res:   Result is written here
 *
 * Returns zero on success
 */
int emul_file_open(const char *name, int flags, struct emul_file *res);

/*
 * Close an opened file
 *
 * @file: File to close
 */
void emul_file_close(struct emul_file *file);

#endif  /* !EMUL_FILE_H */
