
void FUN_00686d40(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar5 = 0;
  iVar6 = 0;
  if (0 < param_1[0x13]) {
    puVar4 = (undefined4 *)(param_1[0x15] + 0x10);
    do {
      iVar2 = FUN_00686e60(param_1,*puVar4);
      iVar5 = iVar5 + iVar2;
      iVar6 = iVar6 + 1;
      puVar4 = puVar4 + 0x16;
    } while (iVar6 < param_1[0x13]);
  }
  if ((((*(char *)((int)param_1 + 0xd1) == '\0') && ((char)param_1[0x3f] == '\0')) &&
      (param_1[0x12] == 8)) && (param_1[0x5b] == 8)) {
    iVar6 = param_1[0x13];
    bVar1 = true;
    if (0 < iVar6) {
      piVar3 = (int *)(param_1[0x15] + 0x18);
      do {
        if ((1 < piVar3[-1]) || (1 < *piVar3)) {
          bVar1 = false;
        }
        piVar3 = piVar3 + 0x16;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if ((iVar5 != 0) && (bVar1)) {
      bVar1 = false;
      *(undefined4 *)(*param_1 + 0x14) = 0x4d;
      (**(code **)(*param_1 + 4))(param_1,0);
    }
  }
  else {
    bVar1 = false;
  }
  if (*(char *)((int)param_1 + 0xd1) == '\0') {
    if ((char)param_1[0x3f] == '\0') {
      if (bVar1) {
        uVar7 = 0xc0;
      }
      else {
        uVar7 = 0xc1;
      }
    }
    else {
      uVar7 = 0xc2;
    }
  }
  else if ((char)param_1[0x3f] == '\0') {
    uVar7 = 0xc9;
  }
  else {
    uVar7 = 0xca;
  }
  FUN_00687040(param_1,uVar7);
  if (param_1[0x3d] != 0) {
    FUN_00686f60(param_1);
  }
  if (((char)param_1[0x3f] != '\0') && (param_1[0x5b] != 8)) {
    FUN_00687100(param_1);
  }
  return;
}

