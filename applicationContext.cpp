#include "applicationContext.h"

ApplicationContext *ApplicationContext::instance = 0;

ApplicationContext *ApplicationContext::getInstance()
{

    if(!instance) {
        instance = new ApplicationContext();        
    }
    return instance;

}

SpectralJob *ApplicationContext::getSpectralJob()
{
    if(!spectralJob) {
        spectralJob = new SpectralJob();
    }
    return spectralJob;

}

SpectrasServerResponseHandler *ApplicationContext::getSpectrasServerResponseHandler()
{
    if(!spectrasServerResponseHandler) {
        spectrasServerResponseHandler = new SpectrasServerResponseHandler();
    }
    return spectrasServerResponseHandler;

}

ApplicationContext::ApplicationContext()
{
}
