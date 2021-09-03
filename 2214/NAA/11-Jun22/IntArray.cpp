#include "IntArray.h"
namespace sdds {
   IntArray::IntArray(int size) :m_data(nullptr) {
      if (size < 1) size = 1;
      m_data = new int[size];
      m_size = size;
   }
   int& IntArray::operator[](int index) {
      if (index < 0) index = 0;
      if (index >= m_size) {
         resize(index + 1);
      }
      return m_data[index];
   }
   IntArray::IntArray(const IntArray& I):m_data(nullptr) {
      *this = I;        // Potatos
//      operator=(I);   // potaatos
   }
   IntArray& IntArray::operator=(const IntArray& Ro) {
      if (this != &Ro) {
         delete[] m_data;
         m_data = new int[Ro.size()];
         for (int i = 0; i < Ro.size(); i++) {
            m_data[i] = Ro.m_data[i];
         }
         m_size = Ro.size();
      }
      return *this;
   }
   int IntArray::size()const {
      return m_size;
   }
   void IntArray::resize(int newsize) {
      int* temp = new int[newsize];
      int i;
      for (i = 0; i < newsize && i < m_size; i++) {
         temp[i] = m_data[i];
      }
      delete[] m_data;
      m_size = newsize;
      m_data = temp;
   }
   IntArray::~IntArray() {
      delete[] m_data;
   }
   std::ostream& IntArray::print(std::ostream& ostr) const {
      for (int i = 0; i < m_size; i++) {
         if (i != 0) ostr << ',';
         ostr << m_data[i];
      }
      return ostr;
   }
   std::ostream& operator<<(std::ostream& ostr, const IntArray& I) {
      return I.print(ostr);
   }
}