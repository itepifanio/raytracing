#include "../include/api.h"
#include "../include/tinyxml2.h"
#include "../include/paramset.h"

using namespace tinyxml2;

Api::Api(RunningOptions options)
{
    this->options = options;
}

Film createFilm(const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "image");
    int xRes = ps.find_one<int>("x_res", 500);
    int yRes = ps.find_one<int>("y_res", 500);
    std::string filename = ps.find_one<string>("filename", "out.ppm");

    Film film(xRes, yRes, type, filename);
    return film;
}

Background createBackground(Film film, const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "colors");
    Vector3 color = Vector3::string_to_vector(ps.find_one<string>("color", "-1 -1 -1"));
    Vector3 bl = Vector3::string_to_vector(ps.find_one<string>("bl", "0 0 0"));
    Vector3 br = Vector3::string_to_vector(ps.find_one<string>("br", "0 0 0"));
    Vector3 tl = Vector3::string_to_vector(ps.find_one<string>("tl", "0 0 0"));
    Vector3 tr = Vector3::string_to_vector(ps.find_one<string>("tr", "0 0 0"));

    if (color.vector[0] != -1 && color.vector[1] != -1 && color.vector[2] != -1)
    {
        Background bg(film.getImageWidth(), film.getImageHeight(), type, color.toPixel());
        return bg;
    }
    
    Point points[4];
    points[0] = bl.toPoint();
    points[1] = tl.toPoint();
    points[2] = tr.toPoint();
    points[3] = br.toPoint();

    Background bg(film.getImageWidth(), film.getImageHeight(), type, points);

    return bg;
}

void Api::parser(std::string xmlFile)
{
    XMLDocument doc;

    // cast string to char*
    char xmlCharFile[xmlFile.length()];
    for (int i = 0; i < sizeof(xmlFile); i++)
    {
        xmlCharFile[i] = xmlFile[i];
    }
    doc.LoadFile(xmlCharFile);

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

                this->film = createFilm(ps);
                // std::cout << film.getXres() << " " << film.getYres() << std::endl;
            }
            else if (strcmp(tag, "world_begin") == 0)
            {
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

                        this->background = createBackground(this->film, ps);
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

void Api::render()
{
    // TODO::raytracking loop
}

void Api::run()
{
    this->parser(this->options.getSceneFile());
}

Background Api::getBackground()
{
    return this->background;
}
