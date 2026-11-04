
int FUN_00517710(int param_1,short *param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (-(uint)(param_6 != 0) & 3) + 1;
  if (param_5 == 0) {
    iVar3 = DAT_00a37db4;
  }
  else {
    iVar3 = param_5;
  }
  if ((param_4 == 0) && (((DAT_00a37db0 == 0 || (DAT_00a37dac != 0)) && (param_1 <= iVar3)))) {
    if (param_2 != (short *)0x0) {
      if (param_6 != 0) {
        *param_2 = (short)((int)(param_1 + 3 + (param_1 + 3 >> 0x1f & 3U)) >> 2) * 4;
        return 1;
      }
      *param_2 = (short)param_1;
    }
    return 1;
  }
  if (param_1 <= iVar4) {
    if (param_2 != (short *)0x0) {
      *param_2 = (short)iVar4;
    }
    return 1;
  }
  iVar2 = 0;
  for (iVar1 = iVar3; (iVar4 < iVar1 && (param_1 < iVar1)); iVar1 = iVar1 >> 1) {
  }
  if (((param_3 != 0) || ((param_5 == 0 && (param_1 <= DAT_00a37e60)))) && (iVar1 * 2 <= iVar3)) {
    if (iVar1 < param_1) {
      iVar1 = iVar1 * 2;
    }
    if (param_2 != (short *)0x0) {
      *param_2 = (short)iVar1;
    }
    return 1;
  }
  while( true ) {
    if (param_2 != (short *)0x0) {
      param_2[iVar2] = (short)iVar1;
    }
    param_1 = param_1 - iVar1;
    if (param_1 < 1) goto LAB_0051783b;
    if (((int)(iVar1 * 3 + (iVar1 * 3 >> 0x1f & 3U)) >> 2 < param_1) && (iVar1 < iVar3)) break;
    for (; (param_1 < iVar1 && (iVar4 < iVar1)); iVar1 = iVar1 >> 1) {
    }
    iVar2 = iVar2 + 1;
  }
  if (param_2 != (short *)0x0) {
    param_2[iVar2] = (short)iVar1 * 2;
  }
LAB_0051783b:
  if (((0 < iVar2) && (param_2[iVar2 + -1] == param_2[iVar2])) && (param_2[iVar2 + -1] * 2 <= iVar3)
     ) {
    iVar2 = iVar2 + -1;
    param_2[iVar2] = param_2[iVar2] << 1;
  }
  return iVar2 + 1;
}

