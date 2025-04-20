#pragma once

#include "libftpp.hpp"

class Memento 
{
	public:
	class Snapshot
	{
		public:
		Snapshot() = default;
		~Snapshot() = default;
		Snapshot(const Snapshot & rhs) = default;
		Snapshot(Snapshot && rhs) = default;
		Snapshot & operator=(const Snapshot & rhs) = default;
		Snapshot & operator=(Snapshot && rhs) = default;
		
		template<typename T>
		Snapshot & operator<<(const T& value);

		template<typename T>
		Snapshot & operator>>(T& value);
	
		private:
		DataBuffer buffer;
	};

	Memento() = default;
	~Memento() = default;
	Memento(const Memento & rhs) = delete;
	Memento(Memento && rhs) = delete;
	Memento & operator=(const Memento & rhs) = delete;
	Memento & operator=(Memento && rhs) = delete;

	Snapshot save();
	void load(Snapshot & snapshot);

	private:
	virtual void _saveToSnapshot(Snapshot & snapshotToFill) const = 0;
    virtual void _loadFromSnapshot(Snapshot & snapshot) = 0;

};

template<typename T>
Memento::Snapshot & Memento::Snapshot::operator<<(const T& value)
{
    buffer << value;
	return *this;
}

template<typename T>
Memento::Snapshot & Memento::Snapshot::operator>>(T& value)
{
	buffer >> value;
	return *this;
}

