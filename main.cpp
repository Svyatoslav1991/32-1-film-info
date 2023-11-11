#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

void printInfoAboutMovie(const nlohmann::json& movie) noexcept;


int main()
{
	std::cout << "\tTASK 32.1 FILM INFO\n\n";

	nlohmann::json movie;

    movie["title"] = "Harry Potter and the Philosopher's Stone";
    movie["country"] = "United Kingdom";
    movie["release_date"] = "2001-11-04";
    movie["studio"] = "Warner Bros. Pictures";
    movie["screenplay_author"] = "Steve Kloves";
    movie["director"] = "Chris Columbus";
    movie["producer"] = "David Heyman";

    nlohmann::json characters;
    characters["Harry Potter"] = "Daniel Radcliffe";
    characters["Hermione Granger"] = "Emma Watson";
    characters["Ron Weasley"] = "Rupert Grint";

    movie["characters"] = characters;

    std::ofstream writeFile("Harry_Potter&PS.json");
    writeFile << std::setw(4) << movie << std::endl;
    writeFile.close();


    std::ifstream readFile("Harry_Potter&PS.json");
    nlohmann::json readMovie;
    readFile >> readMovie;
    readFile.close();

    printInfoAboutMovie(readMovie);

	return 0;
}

void printInfoAboutMovie(const nlohmann::json& movie) noexcept
{
    std::cout << "Title: " << movie["title"] << "\n";
    std::cout << "Country: " << movie["country"] << "\n";
    std::cout << "Release Date: " << movie["release_date"] << "\n";
    std::cout << "Studio: " << movie["studio"] << "\n";
    std::cout << "Screenplay Author: " << movie["screenplay_author"] << "\n";
    std::cout << "Director: " << movie["director"] << "\n";
    std::cout << "Producer: " << movie["producer"] << "\n";

    std::cout << "Main Characters:" << "\n";
    for (const auto& character : movie["characters"].items()) {
        std::cout << character.key() << "\t-\t" << character.value() << "\n";
    }
}
