

#ifndef fees_h
#define fees_h

namespace ARK
{

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
/*  /api/blocks/getFees */
struct Fees
{
    Balance send;
    Balance vote;
    Balance delegate;
    Balance secondsignature;
    Balance multisignature;

    Fees(
        const char* const s,
        const char* const v,
        const char* const d,
        const char* const ss,
        const char* const ms
    ) : send(s), vote(v), delegate(d), secondsignature(ss), multisignature(ms) { }

    void description(char* const buf, size_t size);
};
/*  =========  */
/*  ================================================  */

};

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
/*  Description  */
void ARK::Fees::Fees::description(char* const buf, size_t /*size*/)
{
    //TODO:  check len for sufficient size  
    strcpy(buf, "send.ark: ");
    strcat(buf, this->send.ark());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote.ark());
    strcat(buf, "\ndelegate.ark: ");
    strcat(buf, this->delegate.ark());
    strcat(buf, "\nsecondsignature.ark: ");
    strcat(buf, this->secondsignature.ark());
    strcat(buf, "\nmultisignature.ark: ");
    strcat(buf, this->multisignature.ark());
}
/*  =========  */
/*  ================================================  */

#endif
