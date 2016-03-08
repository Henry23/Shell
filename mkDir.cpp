#include <iostream>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
	if (mkdir(argv[0], S_IRUSR | S_IWUSR | S_IXUSR) == 0)
	return 0;
}

/*

dev_t     st_dev     ID of device containing file
ino_t     st_ino     file serial number
mode_t    st_mode    mode of file (see below)
nlink_t   st_nlink   number of links to the file
uid_t     st_uid     user ID of file
gid_t     st_gid     group ID of file
dev_t     st_rdev    device ID (if file is character or block special)
off_t     st_size    file size in bytes (if file is a regular file)
time_t    st_atime   time of last access
time_t    st_mtime   time of last data modification
time_t    st_ctime   time of last status change
blksize_t st_blksize a filesystem-specific preferred I/O block size for
                     this object.  In some filesystem types, this may
                     vary from file to file
blkcnt_t  st_blocks  number of blocks allocated for this object

File serial number and device ID taken together uniquely identify the file within the system. The blkcnt_t, blksize_t, dev_t, ino_t, mode_t, nlink_t, uid_t, gid_t, off_t and time_t types are defined as described in <sys/types.h>. Times are given in seconds since the Epoch.

The following symbolic names for the values of st_mode are also defined:

File type:

S_IFMT
type of file
S_IFBLK
block special
S_IFCHR
character special
S_IFIFO
FIFO special
S_IFREG
regular
S_IFDIR
directory
S_IFLNK
symbolic link
File mode bits:

S_IRWXU
read, write, execute/search by owner
S_IRUSR
read permission, owner
S_IWUSR
write permission, owner
S_IXUSR
execute/search permission, owner
S_IRWXG
read, write, execute/search by group
S_IRGRP
read permission, group
S_IWGRP
write permission, group
S_IXGRP
execute/search permission, group
S_IRWXO
read, write, execute/search by others
S_IROTH
read permission, others
S_IWOTH
write permission, others
S_IXOTH
execute/search permission, others
S_ISUID
set-user-ID on execution
S_ISGID
set-group-ID on execution
S_ISVTX
on directories, restricted deletion flag
The bits defined by S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH, S_ISUID, S_ISGID  and S_ISVTX are unique.

S_IRWXU is the bitwise OR of S_IRUSR, S_IWUSR and S_IXUSR.

S_IRWXG is the bitwise OR of S_IRGRP, S_IWGRP and S_IXGRP.

S_IRWXO is the bitwise OR of S_IROTH, S_IWOTH and S_IXOTH.

Implementations may OR other implementation-dependent bits into S_IRWXU, S_IRWXG and S_IRWXO, but they will not overlap any of the other bits defined in this document. The file permission bits are defined to be those corresponding to the bitwise inclusive OR of S_IRWXU, S_IRWXG and S_IRWXO.

The following macros will test whether a file is of the specified type. The value m supplied to the macros is the value of st_mode from a stat structure. The macro evaluates to a non-zero value if the test is true, 0 if the test is false.

S_ISBLK(m)
Test for a block special file.
S_ISCHR(m)
Test for a character special file.
S_ISDIR(m)
Test for a directory.
S_ISFIFO(m)
Test for a pipe or FIFO special file.
S_ISREG(m)
Test for a regular file.
S_ISLNK(m)
Test for a symbolic link.
The implementation may implement message queues, semaphores, or shared memory objects as distinct file types. The following macros test whether a file is of the specified type. The value of the buf argument supplied to the macros is a pointer to a stat structure. The macro evaluates to a non-zero value if the specified object is implemented as a distinct file type and the specified file type is contained in the stat structure referenced by buf. Otherwise, the macro evaluates to zero.

S_TYPEISMQ(buf)
Test for a message queue
S_TYPEISSEM(buf)
Test for a semaphore
S_TYPEISSHM(buf)
Test for a shared memory object
The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compiler.


int    chmod(const char *, mode_t);
int    fchmod(int, mode_t);
int    fstat(int, struct stat *);
int    lstat(const char *, struct stat *);
int    mkdir(const char *, mode_t);
int    mkfifo(const char *, mode_t);
int    mknod(const char *, mode_t, dev_t);
int    stat(const char *, struct stat *);
mode_t umask(mode_t);



*/