
/* Library Function - Multiple Matches With Different Base Names
    int __cdecl operator==(struct _GUID const &,struct _GUID const &)
    int __cdecl IsEqualGUID(struct _GUID const &,struct _GUID const &)
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict_operator__(_GUID *param_1,_GUID *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0x10;
  do {
    if (*(int *)param_1 != *(int *)param_2) goto LAB_005635b8;
    uVar3 = uVar3 - 4;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
  } while (3 < uVar3);
  if (uVar3 == 0) {
LAB_0056361f:
    bVar1 = false;
  }
  else {
LAB_005635b8:
    iVar2 = (uint)(byte)*param_1 - (uint)(byte)*param_2;
    if (iVar2 == 0) {
      if (uVar3 == 1) goto LAB_0056361f;
      iVar2 = (uint)(byte)param_1[1] - (uint)(byte)param_2[1];
      if (iVar2 == 0) {
        if (uVar3 == 2) goto LAB_0056361f;
        iVar2 = (uint)(byte)param_1[2] - (uint)(byte)param_2[2];
        if (iVar2 == 0) {
          if ((uVar3 == 3) || (iVar2 = (uint)(byte)param_1[3] - (uint)(byte)param_2[3], iVar2 == 0))
          goto LAB_0056361f;
        }
      }
    }
    bVar1 = true;
    if (iVar2 < 1) {
      return 0;
    }
  }
  return (uint)!bVar1;
}

