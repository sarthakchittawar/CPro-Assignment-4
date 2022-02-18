# Computer Programming - Assignment 4 
#### Roll No.: 2021111010

# ~
Collection of all files (.c as well as .pdf) required for the assignment submission.


* The input files should be stored in the same directory as the executable files, while running/compiling.
* The output(s) of the programs will either be printed on terminal after execution, or stored as a file in the same directory. (depending on the question)
* Some codes (Eg: [Q5 Encrypt/Decrypt](./S3)) may take long time for execution for large data inputs, but they do work properly.
* The code used for plotting the curve for approximate variance is [graph.c](./S2/graph.c)
* Report.pdf in [S1](./S1), [S2](./S2) & [S3](./S3) has the necessary explanation & details for those subsets of problems in the assignment.

### Shortcut links:
1. [Randomness in Computation](./S1)  (*[Report.pdf](./S1/Report.pdf)*)
2. [Streaming Computations](./S2)  (*[Report.pdf](./S2/Report.pdf)*)
3. [Cryptography and Bit Manipulation](./S3)  (*[Report.pdf](./S3/Report.pdf)*)
4. [Data on the Disk](./S4)

## Instructions to compile and run (all done on Ubuntu 20.04)
1. [S1](./S1) - Compilation doesn't require files.
   * ```$ gcc <filename>.c```\
     ```$ ./a.out```
2. [S2 - 4a](./S2/4a.c) -
   * ```$ gcc 4a.c```\
     ```$ ./a.out data.txt mean.txt```
   * *mean.txt contains the mean of the data*
3. [S2 - 4b](./S2/4b.c) - 
   * ```$ gcc 4b.c```\
     ```$ ./a.out data.txt mean.txt variance.txt```
   * *variance.txt contains the actual final variance of the data*
4. [S2 - 4c](./S2/4c.c) -
   * ```$ gcc 4c.c```\
     ```$ ./a.out data.txt mean.txt perc.txt```
   * *perc.txt contains the required percentage*
5. [S2 - graph.c](./S2/graph.c) -
   * ```$ gcc graph.c```\
     ```$ ./a.out data.txt```
   * *The output in terminal will have the approximate variance values from i=1 to i=N*
6. [S3 - 5a.c & 5b.c](./S3) - Compilation doesn't require files.
   * ```$ gcc <filename>.c```\
     ```$ ./a.out```
7. [S3 - 5c_encrypt.c & 5c_decrypt.c](./S3) -
   * ```$ gcc 5c_encrypt.c```\
     ```$ ./a.out input.txt key.txt encrypted.txt```
   * ```$ gcc 5c_decrypt.c```\
     ```$ ./a.out key.txt encrypted.txt output.txt```
   * *Encryption/Decryption has no file size-limit, but computing time will increase as data size of input.txt increases.*
   * Also, Encryption/Decryption will work for several input file extentions such as **.txt, .pdf, .mp3, .mp4, .png, etc.**
8. [S4 - 6.c](./S4/6.c) -
   * ```$ gcc 6.c```\
     ```$ ./a.out charcount.txt file1.txt file2.txt ... filen.txt```
   * *Here, file1.txt, file2.txt, ... filen.txt are the input files, and charcount.txt is the output file*
9. [S4 - 7.c](./S4/7.c) -
   * ```$ gcc 7.c```\
     ```$ ./a.out wordcount.txt file1.txt file2.txt ... filen.txt```
   * *Here, file1.txt, file2.txt, ... filen.txt are the input files, and wordcount.txt is the output file*
10. [S4 - 8.c](./S4/8.c) -
    * ```$ gcc 8.c```\
      ```$ ./a.out file1.txt file2.txt sorted.txt```
    * *Here, file1.txt & file2.txt are 2 sorted files (Max word length = 15 & Max data size = 15Mb) & sorted.txt is the output file after combining both files.
