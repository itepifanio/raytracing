#include "../include/core/api.h"

Api::Api(RunningOptions options)
{
    this->options = options;
}

void Api::createFilm(const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "image");
    int xRes = ps.find_one<int>("x_res", 500);
    int yRes = ps.find_one<int>("y_res", 500);
    std::string filename = ps.find_one<string>("filename", "out.ppm");

    Film film(type, xRes, yRes, filename);
    this->camera->film = film;
}

void Api::createBackground(const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "colors");
    Vector3 color = Vector3::string_to_vector(ps.find_one<string>("colors", "-1 -1 -1"));
    Vector3 bl = Vector3::string_to_vector(ps.find_one<string>("bl", "0 0 0"));
    Vector3 br = Vector3::string_to_vector(ps.find_one<string>("br", "0 0 0"));
    Vector3 tl = Vector3::string_to_vector(ps.find_one<string>("tl", "0 0 0"));
    Vector3 tr = Vector3::string_to_vector(ps.find_one<string>("tr", "0 0 0"));

    if (color.vector[0] != -1 && color.vector[1] != -1 && color.vector[2] != -1)
    {
        Background bg(this->camera->film.getXRes(), this->camera->film.getYRes(), type, color.toPixel());
        this->background = bg;
    } else {
        Point points[4];
        points[0] = bl.toPoint();
        points[1] = tl.toPoint();
        points[2] = tr.toPoint();
        points[3] = br.toPoint();

        Background bg(this->camera->film.getXRes(), this->camera->film.getYRes(), type, points);

        bg.interpolateAll();

        this->background = bg;
        this->scene.setBackground(bg);
    }
}

void Api::createLookat(const ParamSet &ps)
{
    Vector3 look_from = Vector3::string_to_vector(ps.find_one<string>("look_from", "0 0 0"));
    Vector3 look_at = Vector3::string_to_vector(ps.find_one<string>("look_at", "0 0 0"));
    Vector3 vup = Vector3::string_to_vector(ps.find_one<string>("up", "0 0 0"));
    
    Lookat lookat(look_from, look_at, vup);
    this->lookat = lookat;
}

void Api::createCamera(const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "orthographic");
    std::tuple<double, double, double, double> screenWindow = Camera::string_to_tuple(
        ps.find_one<string>("screen_window", "-4 4 -3 3")
    );
    this->camera = Camera::make(type, this->lookat, screenWindow);
    this->scene.setCamera(this->camera);
}

void Api::createMaterial(const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "flat");

    if(type.compare("flat") == 0) {
        Vector3 color = Vector3::string_to_vector(ps.find_one<string>("color", "0 0 0"));
        FlatMaterial *flatMaterial = new FlatMaterial(color.toColor24());
        // TODO::we may now be allowed to remove the material reference from api.h
        this->material = dynamic_cast<FlatMaterial*>(flatMaterial);
    }
    else if(type.compare("blinn") == 0)
    {
        std::string name = ps.find_one<string>("name", "gold");
        Vector3 ambient = Vector3::string_to_vector(ps.find_one<string>("ambient", "0.2 0.2 0.2"));
        Vector3 diffuse = Vector3::string_to_vector(ps.find_one<string>("diffuse", "1.0 0.65 0.0"));
        Vector3 specular = Vector3::string_to_vector(ps.find_one<string>("specular", "0.8 0.6 0.2"));
        double glossiness = std::stod(ps.find_one<string>("glossiness", "256"));

        BlinnPhongMaterial *blinnMaterial = new BlinnPhongMaterial(
            name, ambient, diffuse,
            specular, glossiness
        );

        std::string mirrorStr = ps.find_one<string>("mirror", "");
        if (mirrorStr.compare("") != 0)
        {
            blinnMaterial->setMirror(Vector3::string_to_vector(mirrorStr));
        }
        this->material = dynamic_cast<BlinnPhongMaterial*>(blinnMaterial);
    }
}

void Api::createIntegrator(const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "flat");
    if(type.compare("flat") == 0)
    {
        this->integrator = new FlatIntegrator();
    }
    else if(type.compare("blinn_phong") == 0)
    {
        this->integrator = new BlinnPhongIntegrator();
    }
}

void Api::addSphere(const ParamSet &ps)
{
    std::string type = ps.find_one<string>("type", "sphere");
    double radius = std::stod(ps.find_one<string>("radius", "0.4"));
    Vector3 center = Vector3::string_to_vector(ps.find_one<string>("center", "0 0 0"));

    Shape *shape = new Sphere(radius, center.toPoint());

    Primitive *primitive = new GeometricPrimitive(
        dynamic_cast<Shape*>(shape), 
        dynamic_cast<Material*>(this->material)
    );

    shape->primitive = dynamic_cast<GeometricPrimitive*>(primitive);

    this->scene.setPrimitive(primitive);
}

void Api::readInclude(const ParamSet &ps)
{
    std::string filename = ps.find_one<string>("filename", "");
    this->parser(filename);
}

void Api::addLight(const ParamSet &ps)
{
    Light *light;
    std::string type = ps.find_one<string>("type", "point");
    
    if (type.compare("ambient") == 0)
    {
        Vector3 l = Vector3::string_to_vector(ps.find_one<string>("L", "0.2 0.2 0.2"));
        light = new AmbientLight(l);
    }
    else if (type.compare("point") == 0)
    {
        Vector3 i = Vector3::string_to_vector(ps.find_one<string>("I", "0.3 0.3 0.1"));
        Vector3 scale = Vector3::string_to_vector(ps.find_one<string>("scale", "1.0 1.0 1.0"));
        Vector3 from = Vector3::string_to_vector(ps.find_one<string>("from", "0 1.3 -1.7"));

        light = new PointLight(i, scale, from);
    }
    else if (type.compare("directional") == 0)
    {
        Vector3 i = Vector3::string_to_vector(ps.find_one<string>("I", "0.5 0.5 0.6"));
        Vector3 scale = Vector3::string_to_vector(ps.find_one<string>("scale", "1.0 1.0 1.0"));
        Vector3 from = Vector3::string_to_vector(ps.find_one<string>("from", "0 25 -14"));
        Vector3 to = Vector3::string_to_vector(ps.find_one<string>("to", "0 0 1"));

        light = new DirectionalLight(i, scale, from, to);
    }
    else if (type.compare("spot") == 0)
    {
        Vector3 i = Vector3::string_to_vector(ps.find_one<string>("I", "0.5 0.5 0.6"));
        Vector3 scale = Vector3::string_to_vector(ps.find_one<string>("scale", "1.0 1.0 1.0"));
        Vector3 from = Vector3::string_to_vector(ps.find_one<string>("from", "0 25 -14"));
        Vector3 to = Vector3::string_to_vector(ps.find_one<string>("to", "0 0 1"));

        double cutoff = std::stod(ps.find_one<string>("cutoff", "30"));
        double falloff = std::stod(ps.find_one<string>("falloff", "15"));
        light = new SpotLight(i, scale, from, to, cutoff, falloff);
    }

    this->scene.setLights(light);
}

ParamSet Api::getParams(XMLElement *e, int size_elements)
{
    ParamSet ps;
    // Read each attribs from XML
    for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
    {
        // Get the key of attribute
        std::string key_ = att->Name();

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

    return ps;
}

void Api::parser(std::string xmlFile)
{
    XMLDocument doc;
    // cast string to char*
    const char *xmlCharFile = xmlFile.c_str();

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
            if (strcmp(tag, "lookat") == 0)
            {
                this->createLookat(this->getParams(e));
            }
            else if (strcmp(tag, "camera") == 0)
            {
                this->createCamera(this->getParams(e));
            }
            else if (strcmp(tag, "film") == 0)
            {
                this->createFilm(this->getParams(e));
            }
            else if(strcmp(tag, "include") == 0)
            {
                this->readInclude(this->getParams(e));
            }
            else if(strcmp(tag, "integrator") == 0)
            {
                this->createIntegrator(this->getParams(e));
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
                        this->createBackground(this->getParams(e));
                    }
                    else if(strcmp(tag, "material") == 0)
                    {
                        this->createMaterial(this->getParams(e));
                    }
                    else if(strcmp(tag, "object") == 0)
                    {
                        this->addSphere(this->getParams(e));
                    }
                    else if(strcmp(tag, "light_source") == 0)
                    {
                        this->addLight(this->getParams(e));
                    }
                }
            }
        }
    }
    else
    {
        throw std::invalid_argument(("Couldn't open the file!\n"));
    }
}

void Api::render()
{
    auto w = this->camera->film.getXRes();
    auto h = this->camera->film.getYRes();

    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            Ray ray = this->camera->generate_ray(i, j);

            Vector3 v = this->background.interpolate(
                    double(i) / double(this->background.width),
                    double(j) / double(this->background.height)
            );

            auto color = this->integrator->Li(ray, scene, v);
            this->camera->film.addSample(i, j, color);
        }
    }

    this->camera->film.toPPM(this->camera->film.getFilenameOutput());
}

void Api::run()
{
    this->parser(this->options.getSceneFile());
    this->render();
}

Background Api::getBackground()
{
    return this->background;
}

Camera * Api::getCamera()
{
    return this->camera;
}

// std::vector<Primitive*> Api::getPrimitives()
// {
//     return this->primitives;
// }