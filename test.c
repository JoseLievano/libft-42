#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Link to your libft library
extern int ft_atoi(const char *str);
extern void ft_bzero(void *str, size_t len);
extern void *ft_calloc(size_t count, size_t size);
extern int ft_isalnum(int c);
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
    run_test_ft_isalnum('a', isalnum('a'));
    run_test_ft_isalnum('3', isalnum('3'));
    run_test_ft_isalnum(' ', isalnum(' ')); // Non-alphanumeric character
    run_test_ft_isalnum('Z', isalnum('Z'));
    run_test_ft_isalnum('7', isalnum('7'));
    run_test_ft_isalnum('!', isalnum('!')); // Non-alphanumeric character
    run_test_ft_isalnum('0', isalnum('0'));
    run_test_ft_isalnum('9', isalnum('9'));
    run_test_ft_isalnum('?', isalnum('?'));

    draw_sep();


    return 0;
}