
int FUN_00577640(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = FUN_00572ac0(param_1);
  if (iVar4 == 1) {
    iVar4 = 0;
    if (0 < param_4) {
      piVar5 = param_3;
      do {
        cVar1 = *(char *)((int)piVar5 + (param_2 - (int)param_3));
        if ((cVar1 == '\0') || ((char)*piVar5 == '\0')) {
          if ((*(char *)(iVar4 + param_2) == '\0') && (*(char *)(iVar4 + (int)param_3) == '\0')) {
            return 0;
          }
          break;
        }
        if (cVar1 != (char)*piVar5) break;
        iVar4 = iVar4 + 1;
        piVar5 = (int *)((int)piVar5 + 1);
      } while (iVar4 < param_4);
    }
    if (iVar4 != param_4) {
      return (-(uint)(*(byte *)(iVar4 + param_2) < *(byte *)(iVar4 + (int)param_3)) & 0xfffffffe) +
             1;
    }
  }
  else if (iVar4 == 2) {
    iVar4 = 0;
    if (0 < param_4) {
      piVar5 = param_3;
      do {
        sVar2 = *(short *)((int)piVar5 + (param_2 - (int)param_3));
        if ((sVar2 == 0) || ((short)*piVar5 == 0)) {
          if ((*(short *)(param_2 + iVar4 * 2) == 0) && (*(short *)((int)param_3 + iVar4 * 2) == 0))
          {
            return 0;
          }
          break;
        }
        if (sVar2 != (short)*piVar5) break;
        iVar4 = iVar4 + 1;
        piVar5 = (int *)((int)piVar5 + 2);
      } while (iVar4 < param_4);
    }
    if (iVar4 != param_4) {
      return (-(uint)(*(ushort *)(param_2 + iVar4 * 2) < *(ushort *)((int)param_3 + iVar4 * 2)) &
             0xfffffffe) + 1;
    }
  }
  else if (iVar4 == 3) {
    iVar4 = 0;
    if (0 < param_4) {
      piVar5 = param_3;
      do {
        iVar3 = *(int *)((param_2 - (int)param_3) + (int)piVar5);
        if ((iVar3 == 0) || (*piVar5 == 0)) {
          if ((*(int *)(param_2 + iVar4 * 4) == 0) && (param_3[iVar4] == 0)) {
            return 0;
          }
          break;
        }
        if (iVar3 != *piVar5) break;
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < param_4);
    }
    if (iVar4 != param_4) {
      return (-(uint)(*(uint *)(param_2 + iVar4 * 4) < (uint)param_3[iVar4]) & 0xfffffffe) + 1;
    }
  }
  return 0;
}

