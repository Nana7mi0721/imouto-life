
int * FUN_005777b0(undefined4 param_1,int *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar2 = FUN_00572ac0(param_1);
  if (iVar2 == 1) {
    if ((char)*param_2 != '\0') {
      iVar2 = 0;
      do {
        iVar3 = 0;
        cVar1 = (char)*param_3;
        while (((cVar1 != '\0' && (cVar1 = *(char *)((int)param_2 + iVar3 + iVar2), cVar1 != '\0'))
               && (cVar1 == *(char *)(iVar3 + (int)param_3)))) {
          iVar3 = iVar3 + 1;
          cVar1 = *(char *)(iVar3 + (int)param_3);
        }
        if (*(char *)(iVar3 + (int)param_3) == '\0') {
          return (int *)(iVar2 + (int)param_2);
        }
        if (*(char *)(iVar3 + iVar2 + (int)param_2) == '\0') {
          return (int *)0x0;
        }
        iVar2 = iVar2 + 1;
      } while (*(char *)(iVar2 + (int)param_2) != '\0');
      return (int *)0x0;
    }
  }
  else if (iVar2 == 2) {
    iVar2 = 0;
    if ((short)*param_2 != 0) {
      piVar5 = param_2;
      do {
        iVar3 = 0;
        if ((short)*param_3 != 0) {
          piVar4 = piVar5;
          do {
            if (((short)*piVar4 == 0) || ((short)*piVar4 != *(short *)((int)param_3 + iVar3 * 2)))
            break;
            iVar3 = iVar3 + 1;
            piVar4 = (int *)((int)piVar4 + 2);
          } while (*(short *)((int)param_3 + iVar3 * 2) != 0);
        }
        if (*(short *)((int)param_3 + iVar3 * 2) == 0) {
          return (int *)((int)param_2 + iVar2 * 2);
        }
        if (*(short *)((int)param_2 + (iVar3 + iVar2) * 2) == 0) {
          return (int *)0x0;
        }
        piVar5 = (int *)((int)piVar5 + 2);
        iVar2 = iVar2 + 1;
        if (*(short *)piVar5 == 0) {
          return (int *)0x0;
        }
      } while( true );
    }
  }
  else if ((iVar2 == 4) && (iVar2 = 0, *param_2 != 0)) {
    piVar5 = param_2;
    do {
      iVar3 = 0;
      if (*param_3 != 0) {
        piVar4 = piVar5;
        do {
          if ((*piVar4 == 0) || (*piVar4 != param_3[iVar3])) break;
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (param_3[iVar3] != 0);
      }
      if (param_3[iVar3] == 0) {
        return param_2 + iVar2;
      }
      if (param_2[iVar3 + iVar2] == 0) {
        return (int *)0x0;
      }
      piVar5 = piVar5 + 1;
      iVar2 = iVar2 + 1;
    } while (*piVar5 != 0);
  }
  return (int *)0x0;
}

