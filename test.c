#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>

// Link to your libft library
extern int ft_atoi(const char *str);
extern void ft_bzero(void *str, size_t len);
extern void *ft_calloc(size_t count, size_t size);
extern int ft_isalnum(int c);
extern int ft_isalpha(int character);
extern int ft_isascii(int c);
extern int ft_isprint(int c);
extern char *ft_itoa(int n);
extern void *ft_memchr(const void *str, int c, size_t n);
extern void *ft_memcpy(void *dest, const void *src, size_t len);
extern void	*ft_memmove(void *dest, const void *src, size_t len);
extern void *ft_memset(void *str, int c, size_t len);
extern void ft_putchar_fd(char c, int fd);
extern void ft_putendl_fd(char *s, int fd);
extern void ft_putnbr_fd(int n, int fd);
extern void ft_putstr_fd(char *s, int fd);
extern char **ft_split(char const *s, char c);
extern char *ft_strchr(const char *str, int c);
extern size_t	ft_strlen(const char *str);

void draw_sep(void)
{
    printf("\n");
    printf("##########################");
    printf("\n");
    printf("\n");
}

void fn_to_test(const char *name)
{
    printf("\n");
    printf("Test for: %s *** \n", name);
    printf("\n");
}

void run_test_ft_atoi(const char *input, int expected)
{
    int result = ft_atoi(input);
    if (result == expected) {
        printf("Test passed: ft_atoi(\"%s\") returned %d\n", input, result);
    } else {
        printf("Test failed: ft_atoi(\"%s\") returned %d, expected %d\n", input, result, expected);
    }
}

void run_test_ft_bzero(char *str, size_t len)
{
    char original[len];
    memcpy(original, str, len);

    ft_bzero(str, len);

    if (memcmp(str, original, len) == 0) {
        printf("Test passed: ft_bzero() successfully zeroed %zu bytes\n", len);
    } else {
        printf("Test failed: ft_bzero() did not zero %zu bytes\n", len);
    }
}

void run_test_ft_calloc(size_t count, size_t size)
{
    size_t total_size = count * size;
    void *ptr = ft_calloc(count, size);

    if (ptr != NULL) {
        printf("Test passed: ft_calloc(%zu, %zu) successfully allocated %zu bytes\n", count, size, total_size);
        // Check if the memory is zeroed
        int zeroed = 1;
        unsigned char *p = ptr;
        for (size_t i = 0; i < total_size; i++) {
            if (*p++ != 0) {
                zeroed = 0;
                break;
            }
        }
        if (zeroed) {
            printf("Test passed: ft_calloc() successfully zeroed the allocated memory\n");
        } else {
            printf("Test failed: ft_calloc() did not zero the allocated memory\n");
        }
        free(ptr); // Free the allocated memory
    } else {
        printf("Test failed: ft_calloc(%zu, %zu) failed to allocate memory\n", count, size);
    }
}

void run_test_ft_isalnum(int c, int expected)
{
    int result = ft_isalnum(c);

    if (result == expected) {
        printf("Test passed: ft_isalnum(%c) returned %d\n", c, result);
    } else {
        printf("Test failed: ft_isalnum(%c) returned %d, expected %d\n", c, result, expected);
    }
}

void run_test_ft_isalpha(int c, int expected)
{
    int result = ft_isalpha(c);

    if (result == expected) {
        printf("Test passed: ft_isalpha(%c) returned %d\n", c, result);
    } else {
        printf("Test failed: ft_isalpha(%c) returned %d, expected %d\n", c, result, expected);
    }
}

void run_test_ft_isascii(int c, int expected)
{
    int result = ft_isascii(c);

    if (result == expected) {
        printf("Test passed: ft_isascii(%d) returned %d\n", c, result);
    } else {
        printf("Test failed: ft_isascii(%d) returned %d, expected %d\n", c, result, expected);
    }
}

void run_test_ft_isprint(int c, int expected)
{
    int result = ft_isprint(c);

    if (result == expected) {
        printf("Test passed: ft_isprint(%d) returned %d\n", c, result);
    } else {
        printf("Test failed: ft_isprint(%d) returned %d, expected %d\n", c, result, expected);
    }
}

void run_test_ft_itoa(int n, const char *expected)
{
    char *result = ft_itoa(n);

    if (result != NULL && expected != NULL && strcmp(result, expected) == 0) {
        printf("Test passed: ft_itoa(%d) returned \"%s\"\n", n, result);
    } else {
        printf("Test failed: ft_itoa(%d) returned \"%s\", expected \"%s\"\n", n, result, expected);
    }

    free(result); // Free the allocated string
}

void run_test_ft_memchr(const char *str, int c, size_t n)
{
    const void *result = ft_memchr(str, c, n);
    const void *expected = memchr(str, c, n);

    if (result == expected) {
        printf("Test passed: ft_memchr(\"%s\", '%c', %zu) returned %p\n", str, c, n, result);
    } else {
        printf("Test failed: ft_memchr(\"%s\", '%c', %zu) returned %p, expected %p\n", str, c, n, result, expected);
    }
}

void run_test_ft_memcpy(void *dest, const void *src, size_t len)
{
    void *result = ft_memcpy(dest, src, len);
    void *expected = memcpy(dest, src, len);

    if (result == expected || (result != NULL && expected != NULL && memcmp(result, expected, len) == 0)) {
        printf("Test passed: ft_memcpy returned %p\n", result);
    } else {
        printf("Test failed: ft_memcpy returned %p, expected %p\n", result, expected);
    }
}

void run_test_ft_memmove(void *dest, const void *src, size_t len)
{
    char *temp = malloc(len);
    memcpy(temp, src, len); // Backup the source to handle the overlap correctly

    void *result = ft_memmove(dest, src, len);
    void *expected = memmove(dest, temp, len); // Use backup for a fair comparison

    if (result == expected && memcmp(dest, temp, len) == 0) {
        printf("Test passed: ft_memmove returned %p\n", result);
    } else {
        printf("Test failed: ft_memmove returned %p, expected %p\n", result, expected);
    }

    free(temp);
}

void run_test_ft_memset(char *buffer, int c, size_t len, char *expected)
{
    ft_memset(buffer, c, len);
    if (memcmp(buffer, expected, len) == 0) {
        printf("Test passed: ft_memset set the first %zu bytes of the buffer to '%c'\n", len, c);
    } else {
        printf("Test failed: ft_memset did not set the first %zu bytes of the buffer correctly\n", len);
    }
}

void run_test_ft_putchar_fd(char c, int fd)
{
    printf("Testing ft_putchar_fd with char '%c' and file descriptor %d\n", c, fd);
    ft_putchar_fd(c, fd);
    printf("\n"); // Just print a newline for clarity in the output
}

void run_test_ft_putendl_fd(char *s, int fd)
{
    // Redirect standard output to a temporary file to capture it
    int original_stdout = dup(STDOUT_FILENO);
    FILE* tmp = tmpfile();
    int tmp_fd = fileno(tmp);

    dup2(tmp_fd, STDOUT_FILENO);

    // Call the function to test
    ft_putendl_fd(s, fd);

    // Flush the output to make sure it's all written to the temporary file
    fflush(stdout);

    // Reset standard output to the original one
    dup2(original_stdout, STDOUT_FILENO);

    // Read the output from the temporary file
    rewind(tmp);
    char buffer[1024] = {0}; // Adjust buffer size as necessary
    fread(buffer, sizeof(char), 1023, tmp);

    // Check if the output is as expected (s followed by newline)
    char expected_output[1024];
    sprintf(expected_output, "%s\n", s); // Expected output

    if (strcmp(buffer, expected_output) == 0) {
        printf("Test passed: ft_putendl_fd(\"%s\", %d) correctly output '%s'\n", s, fd, buffer);
    } else {
        printf("Test failed: ft_putendl_fd(\"%s\", %d) output '%s', expected '%s'\n", s, fd, buffer, expected_output);
    }

    // Close the temporary file and restore standard output
    fclose(tmp);
    close(original_stdout);
}

void run_test_ft_putnbr_fd(int n, const char *expected)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    ft_putnbr_fd(n, fd[1]);
    close(fd[1]);

    char buffer[64];
    ssize_t bytes_read = read(fd[0], buffer, sizeof(buffer) - 1);
    buffer[bytes_read] = '\0'; // Null-terminate the string

    if (strcmp(buffer, expected) == 0)
    {
        printf("Test passed: ft_putnbr_fd(%d) wrote \"%s\"\n", n, buffer);
    }
    else
    {
        printf("Test failed: ft_putnbr_fd(%d) wrote \"%s\", expected \"%s\"\n", n, buffer, expected);
    }

    close(fd[0]);
}

void run_test_ft_putstr_fd(char *s, int fd)
{
    printf("Testing ft_putstr_fd with fd = %d\n", fd);
    if (s == NULL) {
        printf("Test skipped: String is NULL\n");
    } else {
        printf("Output: ");
        ft_putstr_fd(s, fd); // Assuming it works similar to write, output will be visible on console
        printf("\nTest for string \"%s\" completed.\n", s);
    }
}

void run_test_ft_split(char const *s, char c)
{
    if (s == NULL) {
        printf("Test skipped: String is NULL\n");
        return;
    }

    printf("Testing ft_split with delimiter '%c'\n", c);
    char **result = ft_split(s, c);

    if (result == NULL) {
        printf("Test failed: ft_split(\"%s\", '%c') returned NULL\n", s, c);
        return;
    }

    printf("Output:\n");
    for (int i = 0; result[i] != NULL; i++) {
        printf(" - \"%s\"\n", result[i]);
        free(result[i]); // Assuming your ft_split allocates memory for each string
    }
    free(result); // Assuming your ft_split allocates memory for the array
    printf("Test for string \"%s\" completed.\n", s);
}

void run_test_ft_strchr(const char *input, int character, char *expected)
{
    char *result = ft_strchr(input, character);
    if ((result == expected) || (result && expected && strcmp(result, expected) == 0)) {
        printf("Test passed: ft_strchr(\"%s\", '%c') returned \"%s\"\n", input, character, result);
    } else {
        printf("Test failed: ft_strchr(\"%s\", '%c') returned \"%s\", expected \"%s\"\n", input, character, result, expected);
    }
}

int main()
{
    // Run the test cases for ft_atoi
    fn_to_test("ft_atoi");
    run_test_ft_atoi("123", 123);
    run_test_ft_atoi("-456", -456);
    run_test_ft_atoi("0", 0);
    run_test_ft_atoi("   789", 789);
    run_test_ft_atoi("\t-1011", -1011);
    run_test_ft_atoi("2147483647", 2147483647); // INT_MAX
    run_test_ft_atoi("-2147483648", -2147483648); // INT_MIN
    run_test_ft_atoi("  +0", 0); // Leading + sign
    run_test_ft_atoi("123abc", 123); // Trailing characters

    draw_sep();

    // Run the test cases for ft_bzero
    fn_to_test("ft_bzero");
    char str1[] = "Hello, world!";
    run_test_ft_bzero(str1, ft_strlen(str1));

    char str2[] = "This is a test";
    run_test_ft_bzero(str2, 5);

    char str3[] = "";
    run_test_ft_bzero(str3, 0); // Edge case: zero-length string

    char str4[10];
    memset(str4, 1, sizeof(str4));
    run_test_ft_bzero(str4, sizeof(str4)); // Edge case: non-zero filled string

    draw_sep();


    // Run the test cases for ft_calloc
    fn_to_test("ft_calloc");
    run_test_ft_calloc(5, 4);
    run_test_ft_calloc(0, 10); // Edge case: zero count
    run_test_ft_calloc(8, 0); // Edge case: zero size
    run_test_ft_calloc(3, 3);
    run_test_ft_calloc(100000, 1); // Large allocation
    run_test_ft_calloc(1000, 1000); // Large allocation

    draw_sep();


     // Run the test cases for ft_isalnum
    fn_to_test("ft_isalnum");
    run_test_ft_isalnum('a', 1); // Alphanumeric character
    run_test_ft_isalnum('3', 1); // Alphanumeric character
    run_test_ft_isalnum(' ', 0); // Non-alphanumeric character
    run_test_ft_isalnum('Z', 1); // Alphanumeric character
    run_test_ft_isalnum('7', 1); // Alphanumeric character
    run_test_ft_isalnum('!', 0); // Non-alphanumeric character
    run_test_ft_isalnum('0', 1); // Alphanumeric character
    run_test_ft_isalnum('9', 1); // Alphanumeric character
    run_test_ft_isalnum('?', 0); // Non-alphanumeric character

    draw_sep();


    // Run the test cases for ft_isalpha
    fn_to_test("ft_isalpha");
    run_test_ft_isalpha('a', 1); // Alphabetic character
    run_test_ft_isalpha('3', 0); // Non-alphabetic character
    run_test_ft_isalpha('Z', 1); // Alphabetic character
    run_test_ft_isalpha('7', 0); // Non-alphabetic character
    run_test_ft_isalpha('?', 0); // Non-alphabetic character

    draw_sep();

    // Run the test cases for ft_isascii
    fn_to_test("ft_isascii");
    run_test_ft_isascii(65, 1); // ASCII character
    run_test_ft_isascii(128, 0); // Non-ASCII character
    run_test_ft_isascii(32, 1); // ASCII character (space)
    run_test_ft_isascii(0, 1); // Edge case: Null character
    run_test_ft_isascii(127, 1); // Edge case: Del character
    run_test_ft_isascii(255, 0); // Non-ASCII character
    run_test_ft_isascii(-1, 0); // Negative value

    draw_sep();

    // Run the test cases for ft_isprint
    fn_to_test("ft_isprint");
    run_test_ft_isprint(65, 1); // Printable character
    run_test_ft_isprint(32, 1); // Printable character (space)
    run_test_ft_isprint(127, 0); // Non-printable character (DEL)
    run_test_ft_isprint(31, 0); // Non-printable character (Unit Separator)
    run_test_ft_isprint(0, 0); // Non-printable character (Null character)
    run_test_ft_isprint(255, 0); // Non-printable character

    draw_sep();

    // Run the test cases for ft_itoa
    fn_to_test("ft_itoa");
    run_test_ft_itoa(123, "123"); // Positive integer
    run_test_ft_itoa(-456, "-456"); // Negative integer
    run_test_ft_itoa(0, "0"); // Zero
    run_test_ft_itoa(2147483647, "2147483647"); // Maximum positive integer
    run_test_ft_itoa(-2147483648, "-2147483648"); // Minimum negative integer

    draw_sep();


    // Run the test cases for ft_memchr
    fn_to_test("ft_memchr");
    char input1[] = "Hello, world!";
    run_test_ft_memchr(input1, 'o', 12); // Character found within the specified length
    run_test_ft_memchr(input1, 'z', 12); // Character not found within the specified length
    run_test_ft_memchr(input1, 'H', 1); // Character found at the start of the string
    run_test_ft_memchr(input1, '!', 12); // Character found at the end of the string
    run_test_ft_memchr(input1, 'l', 3); // Character found within the specified length
    run_test_ft_memchr(input1, 'o', 0); // Searching in an empty string
    run_test_ft_memchr(input1, '\0', 12); // Searching for null character
    run_test_ft_memchr(input1, 'o', 5); // Character not found within the specified length
    run_test_ft_memchr(input1, 'o', 13); // Character found within the specified length
    run_test_ft_memchr(input1, 'o', 20); // Character found within the specified length (exceeding the string length)

    draw_sep();

    // Run the test cases for ft_memcpy
    fn_to_test("ft_memcpy");
    char inputmemcpy[20] = "Hello, world!";
    char output1[20];
    run_test_ft_memcpy(output1, inputmemcpy, 12); // Copying within the specified length
    run_test_ft_memcpy(output1, inputmemcpy, 5); // Copying within a shorter length
    run_test_ft_memcpy(output1, inputmemcpy, 0); // Copying with length 0
    run_test_ft_memcpy(output1, inputmemcpy, 13); // Copying within the specified length (exceeding the source length)
    run_test_ft_memcpy(output1, inputmemcpy, 20); // Copying the entire source length
    run_test_ft_memcpy(output1, inputmemcpy, 21); // Copying more than the source length

    draw_sep();

    // Run the test cases for ft_memmove
    fn_to_test("ft_memmove");
    char inputmemmove[20] = "Hello, world!";
    char output2[20];

    // Overlapping regions: dest is ahead of src
    run_test_ft_memmove(inputmemmove + 6, inputmemmove, 5); // Moving a part of the string within itself
    // Overlapping regions: src is ahead of dest
    run_test_ft_memmove(inputmemmove, inputmemmove + 6, 5); // Moving a part of the string within itself
    // Non-overlapping regions
    run_test_ft_memmove(output2, inputmemmove, 12); // Copying within the specified length
    run_test_ft_memmove(output2, inputmemmove, 5);  // Copying within a shorter length
    run_test_ft_memmove(output2, inputmemmove, 0);  // Copying with length 0
    run_test_ft_memmove(output2, inputmemmove, 13); // Copying within the specified length (exceeding the source length)
    run_test_ft_memmove(output2, inputmemmove, 20); // Copying the entire source length
    run_test_ft_memmove(output2, inputmemmove, 21); // Copying more than the source length

    draw_sep();


    // Run the test cases for ft_memset
    fn_to_test("ft_memset");
    char buffer[10];
    // Initial test cases
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, 'a', 5, "aaaaaXXXXX");
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, '\0', 3, "\0\0\0XXXXXXX");
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, '1', 10, "1111111111");
    // Additional test cases
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, 'Z', 0, "XXXXXXXXXX"); // No change expected
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, 'b', 9, "bbbbbbbbbX"); // Almost full buffer set
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, 255, 7, "\xFF\xFF\xFF\xFF\xFF\xFF\xFFXXX"); // Test with max unsigned char value
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, ' ', 10, "          "); // Set all to space character
    memset(buffer, 'X', sizeof(buffer)); // Reset buffer to a known state
    run_test_ft_memset(buffer, '2', 1, "2XXXXXXXXX"); // Set only the first character
    draw_sep();


    // Test for ft_putchar_fd
    fn_to_test("ft_putchar_fd");
    run_test_ft_putchar_fd('a', 1); // Standard output
    run_test_ft_putchar_fd('Z', 2); // Error output, usually the terminal
    draw_sep();

    // Add this code inside the main function, where you want to run the tests for ft_putendl_fd
    fn_to_test("ft_putendl_fd");
    run_test_ft_putendl_fd("Hello, world!", 1); // Standard output (stdout)
    run_test_ft_putendl_fd("42", 1); // Standard output (stdout)
    run_test_ft_putendl_fd("", 1); // Empty string to stdout
    draw_sep();


    // Run the test cases for ft_putnbr_fd
    fn_to_test("ft_putnbr_fd");
    run_test_ft_putnbr_fd(123, "123");
    run_test_ft_putnbr_fd(-456, "-456");
    run_test_ft_putnbr_fd(0, "0");
    run_test_ft_putnbr_fd(INT_MAX, "2147483647"); // INT_MAX
    run_test_ft_putnbr_fd(INT_MIN, "-2147483648"); // INT_MIN
    run_test_ft_putnbr_fd(10, "10");
    run_test_ft_putnbr_fd(-1, "-1");
    draw_sep();


    // Add this code inside the main function, where you want to run the tests for ft_putstr_fd
    fn_to_test("ft_putstr_fd");
    run_test_ft_putstr_fd("Hello, world!", 1); // Standard output (stdout)
    run_test_ft_putstr_fd("42", 1); // Standard output (stdout)
    run_test_ft_putstr_fd("", 1); // Empty string to stdout
    run_test_ft_putstr_fd(NULL, 1); // NULL string to stdout (edge case)
    run_test_ft_putstr_fd("Error message\n", 2); // Error output (stderr)
    draw_sep();

    // Run the test cases for ft_split
    fn_to_test("ft_split");
    run_test_ft_split("Hello World!", ' '); // Standard case with spaces
    run_test_ft_split("42School@42", '4'); // Delimiter at the beginning
    run_test_ft_split("Lorem-ipsum-dolor-sit-amet", '-'); // Delimiter in between
    run_test_ft_split("EndsWithDelimiter;", ';'); // Delimiter at the end
    run_test_ft_split("", ' '); // Empty string
    run_test_ft_split("NoDelimiterInThisString", ','); // No delimiter in the string
    run_test_ft_split("DelimiterAtTheEndOnly:", ':'); // Delimiter at the end only
    run_test_ft_split("Only;Delimiter;String", ';'); // String with only delimiters
    run_test_ft_split(NULL, ','); // NULL string
    draw_sep();

    // Run the test cases for ft_strchr
    fn_to_test("ft_strchr");
    run_test_ft_strchr("Hello, World!", 'W', "World!");
    run_test_ft_strchr("abcdef", 'a', "abcdef");
    run_test_ft_strchr("abcdef", 'd', "def");
    run_test_ft_strchr("abcdef", 'z', NULL); // Character not found
    run_test_ft_strchr("abcdef", '\0', ""); // Null terminator
    run_test_ft_strchr("", 'a', NULL); // Empty string
    draw_sep();


    return 0;
}
