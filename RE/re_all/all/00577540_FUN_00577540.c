
int FUN_00577540(undefined4 param_1,int *param_2,int param_3)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar4 = FUN_00572ac0(param_1);
  if (iVar4 != 1) {
    if (iVar4 == 2) {
      iVar4 = 0;
      sVar2 = (short)*param_2;
      while (((sVar2 != 0 && (*(byte *)(iVar4 + param_3) != 0)) &&
             (*(ushort *)((int)param_2 + iVar4 * 2) == (ushort)*(byte *)(iVar4 + param_3)))) {
        iVar4 = iVar4 + 1;
        sVar2 = *(short *)((int)param_2 + iVar4 * 2);
      }
      uVar3 = *(ushort *)((int)param_2 + iVar4 * 2);
      if ((uVar3 != 0) || (*(char *)(iVar4 + param_3) != '\0')) {
        return (-(uint)(uVar3 < *(byte *)(iVar4 + param_3)) & 0xfffffffe) + 1;
      }
    }
    else if (iVar4 == 4) {
      iVar4 = *param_2;
      iVar5 = 0;
      while (((iVar4 != 0 && (*(byte *)(iVar5 + param_3) != 0)) &&
             (param_2[iVar5] == (uint)*(byte *)(iVar5 + param_3)))) {
        iVar5 = iVar5 + 1;
        iVar4 = param_2[iVar5];
      }
      if ((param_2[iVar5] != 0) || (*(char *)(iVar5 + param_3) != '\0')) {
        return (-(uint)((uint)param_2[iVar5] < (uint)*(byte *)(iVar5 + param_3)) & 0xfffffffe) + 1;
      }
    }
    return 0;
  }
  iVar4 = 0;
  if ((char)*param_2 != '\0') {
    piVar6 = param_2;
    do {
      cVar1 = *(char *)((param_3 - (int)param_2) + (int)piVar6);
      if ((cVar1 == '\0') || ((char)*piVar6 != cVar1)) break;
      piVar6 = (int *)((int)piVar6 + 1);
      iVar4 = iVar4 + 1;
    } while (*(char *)piVar6 != '\0');
  }
  if ((*(byte *)(iVar4 + (int)param_2) == 0) && (*(char *)(iVar4 + param_3) == '\0')) {
    return 0;
  }
  return (-(uint)(*(byte *)(iVar4 + (int)param_2) < *(byte *)(iVar4 + param_3)) & 0xfffffffe) + 1;
}

