
int __thiscall FUN_00577cb0(int param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *unaff_EBX;
  int iVar4;
  size_t _Size;
  
  if (in_EAX < 0) {
    in_EAX = 6;
  }
  if (in_EAX == 0) {
    *unaff_EBX = 0x31;
    if (param_2 == 0) {
      return 1;
    }
    unaff_EBX[1] = 0x2e;
    return 2;
  }
  pcVar3 = (char *)0x0;
  iVar1 = 0;
  if (param_1 < 5) {
    if (param_1 != 4) {
      if ((0 < param_1) && (param_1 < 3)) {
        pcVar3 = s__Vf<q10123456789abcdef0123456789_0085e41a + 0x26;
        iVar1 = 5;
      }
      goto LAB_00577d0f;
    }
  }
  else if (param_1 != 0x200) goto LAB_00577d0f;
  pcVar3 = &DAT_0085e474;
  iVar1 = 4;
LAB_00577d0f:
  if (in_EAX < iVar1) {
    iVar1 = in_EAX;
  }
  iVar1 = iVar1 + 2;
  iVar2 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      unaff_EBX[iVar2] = pcVar3[iVar2 + iVar1 * 7 + -7];
      iVar2 = iVar2 + 1;
      iVar4 = iVar1;
    } while (iVar2 < iVar1);
  }
  _Size = in_EAX + (2 - iVar1);
  if ((param_3 != 0) && (0 < (int)_Size)) {
    _memset(unaff_EBX + iVar4,0x30,_Size);
    iVar4 = iVar4 + _Size;
  }
  return iVar4;
}

