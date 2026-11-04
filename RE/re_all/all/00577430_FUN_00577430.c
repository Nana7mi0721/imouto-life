
int FUN_00577430(undefined4 param_1,int *param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar3 = FUN_00572ac0(param_1);
  if (iVar3 == 1) {
    iVar3 = 0;
    if ((char)*param_2 != '\0') {
      piVar5 = param_2;
      do {
        cVar1 = *(char *)((param_3 - (int)param_2) + (int)piVar5);
        if ((cVar1 == '\0') || ((char)*piVar5 != cVar1)) break;
        piVar5 = (int *)((int)piVar5 + 1);
        iVar3 = iVar3 + 1;
      } while (*(char *)piVar5 != '\0');
    }
    if ((*(byte *)(iVar3 + (int)param_2) == 0) && (*(char *)(iVar3 + param_3) == '\0')) {
      return 0;
    }
    return (-(uint)(*(byte *)(iVar3 + (int)param_2) < *(byte *)(iVar3 + param_3)) & 0xfffffffe) + 1;
  }
  if (iVar3 == 2) {
    iVar3 = 0;
    if ((short)*param_2 != 0) {
      iVar4 = 0;
      do {
        if ((*(short *)(iVar4 + param_3) == 0) ||
           (*(short *)(iVar4 + (int)param_2) != *(short *)(iVar4 + param_3))) break;
        iVar3 = iVar3 + 1;
        iVar4 = iVar3 * 2;
      } while (*(short *)(iVar4 + (int)param_2) != 0);
    }
    uVar2 = *(ushort *)((int)param_2 + iVar3 * 2);
    if ((uVar2 != 0) || (*(short *)(param_3 + iVar3 * 2) != 0)) {
      return (-(uint)(uVar2 < *(ushort *)(param_3 + iVar3 * 2)) & 0xfffffffe) + 1;
    }
  }
  else if (iVar3 == 4) {
    iVar6 = 0;
    iVar4 = *param_2;
    iVar3 = 0;
    while (((iVar4 != 0 && (*(int *)(iVar3 + param_3) != 0)) &&
           (*(int *)(iVar3 + (int)param_2) == *(int *)(iVar3 + param_3)))) {
      iVar6 = iVar6 + 1;
      iVar4 = param_2[iVar6];
      iVar3 = iVar6 * 4;
    }
    if ((param_2[iVar6] != 0) || (*(int *)(param_3 + iVar6 * 4) != 0)) {
      return (-(uint)((uint)param_2[iVar6] < *(uint *)(param_3 + iVar6 * 4)) & 0xfffffffe) + 1;
    }
  }
  return 0;
}

