
/* Library Function - Single Match
    _shortsort
   
   Library: Visual Studio 2003 Release */

void __cdecl shortsort(undefined1 *param_1,int param_2,code *param_3)

{
  undefined1 uVar1;
  undefined1 *in_EAX;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  for (; param_1 < in_EAX; in_EAX = in_EAX + -param_2) {
    puVar4 = param_1 + param_2;
    puVar3 = param_1;
    if (puVar4 <= in_EAX) {
      do {
        iVar2 = (*param_3)(puVar4,puVar3);
        if (0 < iVar2) {
          puVar3 = puVar4;
        }
        puVar4 = puVar4 + param_2;
      } while (puVar4 <= in_EAX);
    }
    if ((puVar3 != in_EAX) && (param_2 != 0)) {
      puVar4 = in_EAX;
      iVar2 = param_2;
      do {
        uVar1 = puVar4[(int)puVar3 - (int)in_EAX];
        puVar4[(int)puVar3 - (int)in_EAX] = *puVar4;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}

