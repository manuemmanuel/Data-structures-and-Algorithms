#include <stdio.h>

int main()
{   

  struct poly2
  {
    float coe2;
    int Exp2;
    struct poly2 * next;
  };

  struct poly2 *phead2 = NULL;


 struct poly1
 {
    float coe;
    int Exp;
    struct poly1 * next;
 };

 struct poly1 *phead = NULL;


}


struct poly * new_element12(float coe2, int Exp2)
{
  struct poly2 *p = malloc(sizeof *p);
  p->coe2 = coe2;
  p->Exp2 = Exp2;
  return p;
}



struct poly * new_element1(float coe, int Exp) 
{
  struct poly1 *p = malloc(sizeof *p);
  p->coe = coe;
  p->Exp = Exp;
  return p;
}
