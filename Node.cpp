#include "Node.h"

Node::Node (std::string name , std::string description)
: name_ (name) ,
    description_ (description) ,
    north_ (nullptr) ,
    east_ (nullptr) ,
    south_ (nullptr) ,
    west_ (nullptr) ,
    event_ (nullptr) ,
    hasEvent_ (false) ,
    triggerEventOnStart_ (false) ,
    kickOutOfRoomOnEventFail_ (false)
{

}

std::string Node::getName (void)
{
    return this->name_;
}

std::string Node::getDescription (void)
{
    return this->description_;
}

void Node::setNorth (Node * node)
{
    this->north_ = node;
}

Node * Node::getNorth (void)
{
    return this->north_;
}

void Node::setEast (Node * node)
{
    this->east_ = node;
}

Node * Node::getEast (void)
{
    return this->east_;
}

void Node::setSouth (Node * node)
{
    this->south_ = node;
}

Node * Node::getSouth (void)
{
    return this->south_;
}

void Node::setWest (Node * node)
{
    this->west_ = node;
}

Node * Node::getWest (void)
{
    return this->west_;
}

void Node::setEvent (Event * event , bool triggerOnEnter , bool KickOutOfRoom)
{
    this->event_ = event;
    this->hasEvent_ = true;
    this->triggerEventOnStart_ = triggerOnEnter;
    this->kickOutOfRoomOnEventFail_ = KickOutOfRoom;
}

bool Node::startEvent (Player * player)
{
    bool result = this->event_->trigger (player);
    this->triggerEventOnStart_ = !result;
    return result;
}

bool Node::getHasEvent (void)
{
    return this->hasEvent_;
}

bool Node::getTriggerOnStart (void)
{
    return this->triggerEventOnStart_;
}

bool Node::getKickOutOfRoomOnFail (void)
{
    return this->kickOutOfRoomOnEventFail_;
}