#ifndef TARGETABLE_H
#define TARGETABLE_H

// Class targetable contains all elements a target can have
class Targetable
{
    protected:
    bool m_invul = false;
public:
    Targetable();
    // Targets must be able to respawn
    virtual void respawn(){};
    // Make invul standard false
    virtual bool get_invul(){return false;}

    // Set the invulnerability value
    void set_invul(bool value);

};

#endif // TARGETABLE_H
