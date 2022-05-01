#ifndef PARSER_H
#define PARSER_H

#include "../include/tinyxml2.h"

#include "../include/paramset.h"
#include "../include/api.h"
#include "../include/film.h"
#include "../include/background.h"
#include <string>
#include <memory>
#include <algorithm>

using namespace tinyxml2;
using namespace std;

class XmlParser
{
public:
    /*
    Film createFilm(const ParamSet &ps)
    {
        string type = ps.find_one<string>("type", "image");
        int x_res = ps.find_one<int>("x_res", 500);
        int y_res = ps.find_one<int>("y_res", 500);
        string filename = ps.find_one<string>("filename", "out.ppm");
        string img_type = ps.find_one<string>("img_type", "ppm");

        Film film(type, filename, img_type, x_res, y_res);
        return film;
    }*/

    Background createBackground(const ParamSet &ps)
    {
        string type = ps.find_one<string>("type", "colors");
        Vector3 color = Vector3::string_to_vector(ps.find_one<string>("color", "0 0 0"));
        Vector3 bl = Vector3::string_to_vector(ps.find_one<string>("bl", "0 0 0"));
        Vector3 br = Vector3::string_to_vector(ps.find_one<string>("br", "0 0 0"));
        Vector3 tl = Vector3::string_to_vector(ps.find_one<string>("tl", "0 0 0"));
        Vector3 tr = Vector3::string_to_vector(ps.find_one<string>("tr", "0 0 0"));
        Pixel corners[4] = {bl.toPixel(), tl.toPixel(), tr.toPixel(), br.toPixel()};
        Background bg(type, corners);
        return bg;
    }

    /*
    void parser(char *input_file, Film &film, Background &background)
    {
        XMLDocument doc;
        doc.LoadFile(input_file);

        // Verift if there isn't no mistake in open file.
        if (!doc.ErrorID())
        {

            XMLElement *attr = doc.FirstChildElement();

            // Interate over all components/tags.
            for (XMLElement *e = attr->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
            {
                const char *tag = e->Value();

                // Compare each possible type
                if (strcmp(tag, "camera") == 0)
                {
                    ParamSet ps;
                    // Read each attribs from XML
                    for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                    {
                        // createCamera(ps);
                    }
                }
                else if (strcmp(tag, "film") == 0)
                {
                    ParamSet ps;
                    for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                    {
                        // Get the key of attribute
                        std::string key_ = att->Name();

                        // Inform the number of elements that it's going to be in the array.
                        int size_elements = 1;

                        if (key_ == "x_res" || key_ == "y_res")
                        {
                            // Get the value of the attribute that are being interated
                            int v_ = att->IntValue();

                            // Create the vector
                            auto item_insert = make_unique<int[]>(size_elements);

                            // Copy item to the vector
                            item_insert[0] = v_;

                            // Add element to the ParamSet
                            ps.add<int>(key_, std::move(item_insert), 0);
                        }
                        else
                        {
                            // Get the value of the attribute that are being interated
                            std::string v_ = att->Value();
                            // Create the vector
                            auto item_insert = make_unique<std::string[]>(size_elements);

                            // Copy item to the vector
                            item_insert[0] = v_;

                            // Add element to the ParamSet
                            ps.add<std::string>(key_, std::move(item_insert), 0);
                        }
                    }

                    film = createFilm(ps);
                    // std::cout << film.getXres() << " " << film.getYres() << std::endl;
                }
                else if (strcmp(tag, "world_begin") == 0)
                {
                    //
                    /*
                     *   -> GENERATE WORLD
                     *
                     *   Realizando esse laço faz com que caso o cliente queira mudar algumas configurações
                     *   após a criação ele pode depois que criar o mundo.
                     //
                    for (auto attr_world = e; strcmp(tag, "world_end") != 0; attr_world = attr_world->NextSiblingElement())
                    {
                        tag = attr_world->Value();

                        // Evitar inconsistência de dados.
                        e = attr_world;

                        if (strcmp(tag, "background") == 0)
                        {
                            ParamSet ps;
                            for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                            {
                                // Get the key of attribute
                                std::string key_ = att->Name();

                                // Inform the number of elements that it's going to be in the array.
                                int size_elements = 1;

                                // Get the value of the attribute that are being interated
                                std::string v_ = att->Value();
                                // Create the vector
                                auto item_insert = make_unique<std::string[]>(size_elements);

                                // Copy item to the vector
                                item_insert[0] = v_;

                                // Add element to the ParamSet
                                ps.add<std::string>(key_, std::move(item_insert), 0);
                            }

                            background = createBackground(ps);
                        }
                    }
                }
            }
        }
        else
        {
            printf("Erro!\n");
        }
    }
    */
};

#endif
