/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <map>
#include <fstream>

/**
 * @brief class to parse and get any of OUR JSON files
 *
 */
class Parser_Json {
    public:

        Parser_Json(std::string const &filepath);
        ~Parser_Json();
        std::map<std::string, std::string> get_info_from_file(std::string const &info);

    private:
        void open_file();
        void close_file();
        void read_file();
        void parse_file_info();
        std::string parse_file_content(std::string const &info);
        int find_char_from_pos(std::string const &str, unsigned int start_point, char const to_find);
        std::map<std::string , std::string> get_info_in_map(std::string const &info);

        std::string const _filepath;
        std::ifstream _file;
        std::string _file_content;
        std::map<std::string, std::string> _file_info;
};

#endif /* !PARSER_HPP_ */
