/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Parser_Json
*/

#include <vector>
#include <sstream>
#include "Parser.hpp"

/**
* @brief Construct a new Parser_Json object
*
* @param filepath filepath to the .json file that you whant to open
*/
Parser_Json::Parser_Json(std::string const &filepath) : _filepath(filepath)
{
}

/**
* @brief Destroy the Parser_Json object
*
*/
Parser_Json::~Parser_Json()
{
}

/**
 * @brief read the file given in the ctor
 *
 */
void Parser_Json::read_file()
{
    for (std::string line; std::getline(_file, line);) {
        _file_content.append(line);
        _file_content.append("\n");
    }
}

/**
 * @brief open the file given in the ctor
 *
 */
void Parser_Json::open_file()
{
    _file.open(_filepath.c_str());
}

/**
 * @brief close the file given in the ctor
 *
 */
void Parser_Json::close_file()
{
    _file.close();
}

/**
 * @brief function that put the information and there correspondding value in a map
 *
 * @param config_info std::string with the information that we want from the file
 * @return std::map<std::string, std::string> information and there given value in a map
 */
std::map<std::string, std::string> Parser_Json::get_info_in_map(std::string const &config_info)
{
    std::map<std::string, std::string> mapped_info;
    std::vector<std::string> tmp;
    size_t start = config_info.find("{");
    size_t loop_stop = config_info.find("}");
    size_t stop = 0;

    start = find_char_from_pos(config_info, start, '\"');
    stop = find_char_from_pos(config_info, start, '\n');

    for (; start != 0;) {
        tmp.emplace_back(config_info.substr(start, stop - start));
        start = find_char_from_pos(config_info, stop, '\"');
        stop = find_char_from_pos(config_info, start, '\n');
    }

    for (size_t i = 0; i < tmp.size(); i++) {
        std::string var;
        std::string value;
        var = tmp[i].substr(1, tmp[i].find(":") - 2);
        if (tmp[i].find(":") > tmp[i].find_last_of("\"")) {
            size_t temp = tmp[i].find(":") + 2;
            value = tmp[i].substr(temp);
            if (value.back() == ',')
                value.pop_back();
        } else {
            value = tmp[i].substr(tmp[i].find(":") + 3, (tmp[i].find_last_of("\"") - 1 - tmp[i].find(":") - 2));
        }
        mapped_info.emplace(var, value);
    }
    return mapped_info;
}

/**
* @brief Get the info from file object
*
* @param info Must be in lowercase !
* @param info information that you whant to get from the json file given in the ctor
*
* @return a std::map<std::string, std::sting> with the name
*/
std::map<std::string, std::string> Parser_Json::get_info_from_file(std::string const &info)
{
    std::map<std::string, std::string> found;
    std::string config_info;

    open_file();
    read_file();
    close_file();
    config_info = parse_file_content(info);
    if (config_info.empty()) {
        std::cerr << "Error parsing" << std::endl;
        return found;
    }
    found = get_info_in_map(config_info);
    return found;
}

/**
 * @brief function that get the position of a char whith a starting point
 *
 * @param str string where to find handle
 * @param start_point starting position to find handle
 * @param handle the char that we want to find in str
 * @return int
 */
int Parser_Json::find_char_from_pos(std::string const &str, unsigned int start_point, char const handle)
{
    for (size_t i = start_point; i < str.length(); i++) {
        if (str[i] == handle)
            return i;
    }
    return 0;
}

/**
 * @brief function that parser the file given in the ctor
 *
 * @param info info that we whant to get in the file given in the ctor
 * @return std::string information about "info" given in parameter from the file given in the ctor
 */
std::string Parser_Json::parse_file_content(std::string const &info)
{
    std::string to_find = "\"" + info + "\"";
    std::string found;
    size_t find_pos = 0;
    size_t end_pos = 0;

    if ((find_pos = _file_content.find(to_find)) != std::string::npos) {
        end_pos = find_char_from_pos(_file_content, find_pos, '}');
        if (end_pos)
            found = _file_content.substr(find_pos, (end_pos - find_pos + 1));
    } else
        std::cerr << "couldn't find your string in the config file" << std::endl;
    return found;
}