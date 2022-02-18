/*
** EPITECH PROJECT, 2021
** tool
** File description:
** tool
*/

#include "parser.hpp"

std::vector<std::string> Parser::Split(std::string input, std::string token)
{
    std::vector<std::string> result;

    boost::split(result, input, boost::is_any_of(token));
    return (result);
}

std::string Parser::StringToLowerCase(std::string data)
{
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return (data);
}

std::string Parser::StringToUpperCase(std::string data)
{
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::toupper(c); });
    return (data);
}

Address::road Parser::GetTypeRoadWithString(std::string typeRoad)
{
    if (typeRoad == "boulevard") return (Address::BOULEVARD);
    else if (typeRoad == "allée") return (Address::ALLEE);
    else if (typeRoad == "avenue") return (Address::AVENUE);
    else if (typeRoad == "chemin") return (Address::CHEMIN);
    else if (typeRoad == "impasse") return (Address::IMPASSE);
    else if (typeRoad == "place") return (Address::PLACE);
    else if (typeRoad == "quai") return (Address::QUAI);
    else if (typeRoad == "rue") return (Address::RUE);
    else if (typeRoad == "square") return (Address::SQUARE);
    return (Address::NOTHING);
}

std::string Parser::GetStringRoadWithType(Address::road typeRoad)
{
    switch (typeRoad)
    {
    case Address::BOULEVARD :
        return ("boulevard");
    case Address::AVENUE :
        return ("avenue");
    case Address::ALLEE :
        return ("allée");
    case Address::CHEMIN :
        return ("chemin");
    case Address::IMPASSE : 
        return ("impasse");
    case Address::PLACE :
        return ("place");
    case Address::QUAI :
        return ("quai");
    case Address::RUE :
        return ("rue");
    case Address::SQUARE :
        return ("square");
    default:
        return "";
    }
}

std::string Parser::build(std::string line, std::regex pattern, int group)
{
    std::regex_token_iterator<std::string::iterator> iterator (line.begin(), line.end(), pattern, group);
    std::string str = (std::string)(*iterator++);
    std::vector<std::string> list;

    list = Split(str, " ");
    str.clear();
    for (int nbr = 0; nbr < list.size(); nbr++) {
        if (list[nbr] == " " || list[nbr] == "") {
            list.erase(list.begin() + nbr);
            nbr--;
        }
        else str = str + " " + list[nbr];
    }
    for (int nbr = 0; str[0] == ' '; nbr++) str.erase(str.begin());
    for (; str[str.size() - 1] == ' ';) str.pop_back();
    return (str);
}

Address Parser::Format(Address addr)
{
    addr.setAddrComplete(addr.getCity() + ", " + std::to_string(addr.getNbrRoad()) + " " + GetStringRoadWithType(addr.getTypeRoad()) + " " + addr.getNameRoad());
    addr.setCity(StringToLowerCase(addr.getCity()));
    addr.setNameRoad(StringToLowerCase(addr.getNameRoad()));
    return (addr);
}

Address Parser::ParseLine_pattern_one(std::string line, std::regex pattern)
{
    Address::road roadtype = GetTypeRoadWithString(StringToLowerCase(build(line, pattern, 3)));

    if (roadtype == Address::NOTHING) throw (ErrorInvalidAddr(line));
    return Format(Address(line, (build(line, pattern, 1)), (build(line, pattern, 4)), roadtype, stoi(build(line, pattern, 2))));
}

Address Parser::ParseLine_pattern_two(std::string line, std::regex pattern)
{
    Address::road roadtype = GetTypeRoadWithString(StringToLowerCase(build(line, pattern, 2)));

    if (roadtype == Address::NOTHING) throw (ErrorInvalidAddr(line));
    return Format(Address(line, (build(line, pattern, 4)), (build(line, pattern, 3)), roadtype, stoi(build(line, pattern, 1))));
}
