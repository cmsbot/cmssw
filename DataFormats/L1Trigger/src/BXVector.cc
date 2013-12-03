
#include "DataFormats/L1Trigger/interface/BXVector.h"

#include <vector>

template < class T >
BXVector<T>::BXVector( int size,      // number of objects per BX
		    int bxFirst,   // first BX stored
		    int bxLast )  // last BX stored
  : data_(bxLast-bxFirst, std::vector<T>(size)),
    bxFirst_(bxFirst),
    bxLast_(bxLast)
{

}

// copy ctor
template < class T >
BXVector<T>::BXVector ( const BXVector& vector )
{

}

// dtor			
template < class T >
BXVector<T>::~BXVector()
{

}

// assignment operator (pass by value for exception safety)
template < class T >
BXVector<T> BXVector<T>::operator=( BXVector vector )
{
  
}

// set BX range
template < class T >
void BXVector<T>::setBXRange( int bxFirst, int bxLast )
{
  bxFirst_ = bxFirst;
  bxLast_ = bxLast;
}

// set size for a given BX
template < class T >
void BXVector<T>::resize( int bx, int size )
{
  data_.at(bx).resize(size);
}

// set size for all BXs
template < class T >
void BXVector<T>::resizeAll( int size )
{
  for (unsigned i=0; i<data_.size(); ++i) {
    data_.at(i).resize(size);
  }
}

// get the first BX stored
template < class T >
int BXVector<T>::getFirstBX()
{
  return bxFirst_;
}

// get the last BX stored
template < class T >
int BXVector<T>::getLastBX()
{
  return bxLast_;
}

// get N objects for a given BX
template < class T >
unsigned BXVector<T>::size( int bx )
{
  return data_.at(bx).size();
}

// add element with given BX index
template < class T >
void BXVector<T>::push_back( int bx, T object )
{
  data_.at(bx).push_back(object);
}

// random access
template < class T >
T& BXVector<T>::at( int bx, int i )
{
  return data_.at(bx).at(i);
}

// iterator access by BX
template < class T >
typename BXVector<T>::const_iterator BXVector<T>::begin( int bx )
{
  return data_.at(bx).begin();
}

// iterator access by BX
template < class T >
typename BXVector<T>::const_iterator BXVector<T>::end( int bx )
{
  return data_.at(bx).end();
}


template < class T >
unsigned BXVector<T>::indexFromBX(int bx) {
  return bx - bxFirst_;
}
