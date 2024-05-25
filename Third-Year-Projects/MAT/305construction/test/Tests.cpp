/*
** EPITECH PROJECT, 2022
** 305construction
** File description:
** Tests
*/

#include "Construction.hpp"
#include "Error.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

void redirect_stderr(void) {
    cr_redirect_stderr();
}

void usage_fct()
{
    Construction ctr;

    ctr.print_usage();
}

void manage_file_fct(const std::string &filename)
{
    Construction ctr;

    ctr.handle_file(filename);
}

Test(construction, usage, .init=redirect_stdout) {
    usage_fct();
    cr_assert_stdout_eq_str("USAGE\n\t./305construction file\nDESCRIPTION\n\tfile\tfile describing the tasks\n");
}

// Test(constrution, no_file, .init=redirect_stdout, .exit_code = 84) {
//     manage_file_fct("");
//     cr_assert_stderr_eq_str("No file given");
// }

Test(constrution, file_does_no_exist, .init=redirect_stderr, .exit_code=84) {
    manage_file_fct("example/aaaa");
    cr_assert_stderr_eq_str("No such file or directory\n");
}

Test(constrution, file_invalid_right, .init=redirect_stderr,  .exit_code=84) {
    manage_file_fct("example/invalid.cvs");
    cr_assert_stderr_eq_str("Permission denied\n");
}

Test(constrution, file_empty, .init=redirect_stderr,  .exit_code=84) {
    manage_file_fct("example/empty.cvs");
    cr_assert_stderr_eq_str("Empty file\n");
}