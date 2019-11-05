#include <iostream>
#include <stdio.h>
using namespace std;

const int maxsize = 100;
const int null = 0;

struct huff_node
{
  char symbol;
  int freq;
  huff_node *parent;
  char childtype;
};

typedef huff_node *ptr;
ptr node[maxsize];

void create(int k); 
void print(int k);    
void twosmall(ptr &p, ptr &q, int numnode);   
                                              
                                             

int main()
{
  int numsymbols;
  ptr p, q, r;
  cout << "Introduce el numero de simbolos: ";
  cin >> numsymbols;
  for (int i = 0; i < numsymbols; i++)
    create(i);


  for (int j = numsymbols; j < 2*numsymbols - 1; j++)
    {
      r = new huff_node;
      node[j] = r;
      r->parent = NULL;
      twosmall(p, q, j);  
      p->parent = r;
      q->parent = r;
      p->childtype = 'L';
      q->childtype = 'R';
      r->symbol = ' ';
      r->freq = p->freq + q->freq;
    }
  cout << endl << endl;
  cout <<"simbolo *-------* codigo: " << endl;
  for (int k = 0; k < numsymbols; k++)
    print(k);
  return 0;
}

void create(int k)
{
  ptr t = new huff_node;
  cout << "introduce el simbolo numero " << k+1 << ": ";
  cin >> t->symbol;
  cout << "introduce su frecuencia: ";
  cin >> t->freq;
  t->parent = NULL;
  node[k] = t;
}

void print(int k)
{
  ptr t = node[k];
  char code[10];
  int size = 0;
  cout << t->symbol << " - ";

  while (t->parent != NULL)
    {
      if (t->childtype == 'L')
            code[size] = '0';
      else
            code[size] = '1';
      t = t->parent;
      size++;
    }

  for (int j = size-1; j >= 0; j--)
    cout << code[j];
  cout << endl;
}

void twosmall(ptr &p, ptr &q, int numnodes)
{
  int min1 = 9999;
  int min2 = 9999;
  p = NULL;
  q = NULL;

  for (int i = 0; i < numnodes; i++)
    {
      if (node[i]->parent == NULL)
            {
              if (node[i]->freq < min1)
                {
                  min2 = min1;
                  min1 = node[i]->freq;
                  q = p;
                  p = node[i];
                }
              else
                if (node[i]->freq < min2)
                  {
                        min2 = node[i]->freq;
                        q = node[i];
                  }
            }
    }

}