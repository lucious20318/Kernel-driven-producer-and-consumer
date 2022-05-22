Firstly I created two programs P.c and C.c .

In P.c first we create a character array of size 8 because we want to read random 8 bytes.
Then we create a long variable to store the returned id by the syscall. Then we open the device 
/dev/urandom in read only mode. Then we use ssize_t to check whether the system calls are returning an 
error or not. Then we pass the random string through the syscall to the line mentioned as the first
argument in the syscalls. In the end we just print the character array of 8 bytes.

In C.c first we create a character array of size 8 to which the 8 bytes of the random string will be 
copied. Then we use syscall so that the syscall writes the string to the character array we passed 
as the second argument and then we just print it.

Now in the writer syscall mentioned in the line 449 we initialize variable c with the size 8 and in
the next line we assign space to the queue "q" using the kmalloc function. Now after that we call the 
function to enqueue. We use RWSEM which is the reader and writer semaphore. We use down_write to 
increment the lock to 1 then we copy the random string fom the user to kernel. Then we use up_write
to again decrement the lock to 0.

Now in the reader syscall mentioned in the line 450 we call the function to dequeue the array. 
In the functoin f_de we first down_read the RWSEM to decrement the lock by 1 and after that we
copy the 8bytes. Then we use up_read to increment the lock by 1. Then we use kfree(q) to free
the data stored in the queue.