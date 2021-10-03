#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include "spectralJob.h"
#include "spectrasServerResponseHandler.h"

class ApplicationContext
{
public:    
    static ApplicationContext* getInstance();

    SpectralJob* getSpectralJob();
    SpectrasServerResponseHandler* getSpectrasServerResponseHandler();

private:

    SpectralJob* spectralJob=0;

    SpectrasServerResponseHandler* spectrasServerResponseHandler=0;

    static ApplicationContext* instance;
    ApplicationContext();


};

#endif // APPLICATIONCONTEXT_H
