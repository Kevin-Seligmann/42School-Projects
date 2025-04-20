#include "memento.hpp"

Memento::Snapshot Memento::save()
{
	Snapshot snap;
	_saveToSnapshot(snap);
	return snap;
}

void Memento::load(Memento::Snapshot & snap)
{
	_loadFromSnapshot(snap);
}
