#include "targetable.h"

Targetable::Targetable()
{
    // invul is false at the beginning
    m_invul = false;

}

void Targetable::set_invul(bool value)
{
    m_invul = value;
}
