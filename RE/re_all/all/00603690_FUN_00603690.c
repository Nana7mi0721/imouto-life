
undefined4 __thiscall FUN_00603690(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar1 = 4;
  bVar6 = true;
  piVar2 = param_2;
  piVar4 = &DAT_00ddb33c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *piVar2 == *piVar4;
    piVar2 = piVar2 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar6);
  if (!bVar6) {
    iVar1 = 4;
    bVar6 = true;
    piVar2 = param_1;
    piVar4 = param_2;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *piVar2 == *piVar4;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar6);
    if (!bVar6) {
      return 0;
    }
  }
  iVar1 = 4;
  bVar6 = true;
  piVar2 = param_2 + 4;
  piVar4 = &DAT_00ddb33c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *piVar2 == *piVar4;
    piVar2 = piVar2 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar6);
  if (!bVar6) {
    iVar1 = 4;
    bVar6 = true;
    piVar2 = param_1 + 4;
    piVar4 = param_2 + 4;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *piVar2 == *piVar4;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar6);
    if (!bVar6) {
      return 0;
    }
  }
  iVar1 = 4;
  bVar6 = true;
  piVar2 = param_2 + 0xb;
  piVar4 = &DAT_00ddb33c;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar6 = *piVar2 == *piVar4;
    piVar2 = piVar2 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar6);
  if (!bVar6) {
    iVar1 = 4;
    bVar6 = true;
    piVar2 = param_1 + 0xb;
    piVar4 = param_2 + 0xb;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar6 = *piVar2 == *piVar4;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (bVar6);
    if (!bVar6) {
      return 0;
    }
    iVar1 = param_1[0x10];
    if (iVar1 != param_2[0x10]) {
      return 0;
    }
    if (iVar1 != 0) {
      bVar6 = true;
      pcVar3 = (char *)param_1[0x11];
      pcVar5 = (char *)param_2[0x11];
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar6 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (!bVar6) {
        return 0;
      }
    }
  }
  return 1;
}

