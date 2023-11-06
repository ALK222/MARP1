//
//  IndexPQ.h
//
//  Implementación de colas con prioridad mediante montículos.
//  Los elementos son enteros de 0 a N-1 que tienen asociada una prioridad
//  dentro de la cola. La prioridad de un elemento puede ser modificada
//  con coste en O(log N).
//
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2015-2019  Alberto Verdejo
//

#ifndef INDEXPQ_H_
#define INDEXPQ_H_

#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>

// T es el tipo de las prioridades
// Comparator dice cuándo un valor de tipo T es más prioritario que otro
template <typename C, typename T, typename Comparator = std::less<T>>
class IndexPQ
{
public:
   // registro para las parejas < elem, prioridad >
   struct Par
   {
      std::string elem;
      T prioridad;
   };

private:
   // vector que contiene los datos (pares < elem, prio >)
   std::vector<Par> array; // primer elemento en la posición 1

   // vector que contiene las posiciones en array de los elementos
   // std::vector<string> posiciones; // un 0 indica que el elemento no está
   std::unordered_map<std::string, int> posiciones;

   /* Objeto función que sabe comparar prioridades.
    antes(a,b) es cierto si a es más prioritario que b */
   Comparator antes;

public:
   // IndexPQ(int N, Comparator c = Comparator()) : array(1), posiciones(N, 0), antes(c) {}
   IndexPQ(Comparator c = Comparator()) : array(1), antes(c) {}
   // IndexPQ(IndexPQ<T, Comparator> const &) = default;

   // IndexPQ<T, Comparator> &operator=(IndexPQ<T, Comparator> const &) = default;

   ~IndexPQ() = default;

   // e debe ser uno de los posibles elementos
   void push(std::string e, T const &p)
   {
      try
      {
         if (posiciones.at(e) != 0)
            throw std::invalid_argument("No se pueden insertar elementos repetidos.");
         else
         {
            array.push_back({e, p});
            posiciones.insert({e, size()});
            flotar(size());
         }
      }
      catch (const std::out_of_range &exception)
      {
         array.push_back({e, p});
         posiciones.insert({e, size()});
         // posiciones[e] = size();
         flotar(size());
      }
   }

   void update(std::string e, T const &p, bool sum)
   {
      try
      {
         int i = posiciones.at(e);
         sum ? array[i].prioridad += p : array[i].prioridad -= p;
         if (i != 1 && antes(array[i].prioridad, array[i / 2].prioridad))
            flotar(i);
         else
            hundir(i);
      }
      catch (const std::out_of_range &exception)
      {
         push(e, p);
      }
   }

   int size() const
   {
      return int(array.size()) - 1;
   }

   bool empty() const
   {
      return size() == 0;
   }

   Par const &top() const
   {
      if (size() == 0)
         throw std::domain_error("No se puede consultar el primero de una cola vacia");
      else
         return array[1];
   }

   void pop()
   {
      if (size() == 0)
         throw std::domain_error("No se puede eliminar el primero de una cola vacía.");
      else
      {
         posiciones[array[1].elem] = 0; // para indicar que no está
         if (size() > 1)
         {
            array[1] = std::move(array.back());
            posiciones[array[1].elem] = 1;
            array.pop_back();
            hundir(1);
         }
         else
            array.pop_back();
      }
   }

private:
   void flotar(int i)
   {
      Par parmov = std::move(array[i]);
      int hueco = i;
      while (hueco != 1 && antes(parmov.prioridad, array[hueco / 2].prioridad))
      {
         array[hueco] = std::move(array[hueco / 2]);
         posiciones[array[hueco].elem] = hueco;
         hueco /= 2;
      }
      array[hueco] = std::move(parmov);
      posiciones[array[hueco].elem] = hueco;
   }

   void hundir(int i)
   {
      Par parmov = std::move(array[i]);
      int hueco = i;
      int hijo = 2 * hueco; // hijo izquierdo, si existe
      while (hijo <= size())
      {
         // cambiar al hijo derecho de i si existe y va antes que el izquierdo
         if (hijo < size() && antes(array[hijo + 1].prioridad, array[hijo].prioridad))
            ++hijo;
         // flotar el hijo si va antes que el elemento hundiéndose
         if (antes(array[hijo].prioridad, parmov.prioridad))
         {
            array[hueco] = std::move(array[hijo]);
            posiciones[array[hueco].elem] = hueco;
            hueco = hijo;
            hijo = 2 * hueco;
         }
         else
            break;
      }
      array[hueco] = std::move(parmov);
      posiciones[array[hueco].elem] = hueco;
   }
};

#endif /* INDEXPQ_H_ */
