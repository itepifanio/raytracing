#pragma once
class Api
{
public:
    static Api& Instance();
private:
	Api() ;
	~Api();
	Api(Api const&) =delete;
	Api& operator=(Api const&)=delete ;
};
