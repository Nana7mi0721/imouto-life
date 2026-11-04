
void FUN_00691f60(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x198);
  uVar2 = *(int *)(iVar1 + 0x10) + -1 + *(int *)(iVar1 + 0xc) & 0xffff0000;
  if ((int)uVar2 < *(int *)(iVar1 + 0xc)) {
    uVar2 = uVar2 + 0x8000;
  }
  uVar4 = uVar2 << ((byte)*(undefined4 *)(iVar1 + 0x1c) & 0x1f);
  *(uint *)(iVar1 + 0xc) = uVar2;
  *(uint *)(iVar1 + 0xc) = uVar4;
  iVar3 = *(int *)(iVar1 + 0x20);
  if ((uVar4 & 0xf8000000) == 0) {
    if (iVar3 == 0) {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    }
    else if (-1 < iVar3) {
      iVar3 = *(int *)(iVar1 + 0x18);
      while (iVar3 != 0) {
        FUN_00692100(0,param_1);
        iVar3 = *(int *)(iVar1 + 0x18) + -1;
        *(int *)(iVar1 + 0x18) = iVar3;
      }
      FUN_00692100(*(undefined4 *)(iVar1 + 0x20),param_1);
    }
    if (*(int *)(iVar1 + 0x14) != 0) {
      iVar3 = *(int *)(iVar1 + 0x18);
      while (iVar3 != 0) {
        FUN_00692100(0,param_1);
        iVar3 = *(int *)(iVar1 + 0x18) + -1;
        *(int *)(iVar1 + 0x18) = iVar3;
      }
      do {
        FUN_00692100(0xff,param_1);
        FUN_00692100(0,param_1);
        iVar3 = *(int *)(iVar1 + 0x14) + -1;
        *(int *)(iVar1 + 0x14) = iVar3;
      } while (iVar3 != 0);
    }
  }
  else {
    if (-1 < iVar3) {
      iVar3 = *(int *)(iVar1 + 0x18);
      while (iVar3 != 0) {
        FUN_00692100(0,param_1);
        iVar3 = *(int *)(iVar1 + 0x18) + -1;
        *(int *)(iVar1 + 0x18) = iVar3;
      }
      FUN_00692100(*(int *)(iVar1 + 0x20) + 1,param_1);
      if (*(int *)(iVar1 + 0x20) == 0xfe) {
        FUN_00692100(0,param_1);
      }
    }
    iVar3 = *(int *)(iVar1 + 0x14);
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + iVar3;
  }
  if ((*(uint *)(iVar1 + 0xc) & 0x7fff800) != 0) {
    iVar3 = *(int *)(iVar1 + 0x18);
    while (iVar3 != 0) {
      FUN_00692100(0,param_1);
      iVar3 = *(int *)(iVar1 + 0x18) + -1;
      *(int *)(iVar1 + 0x18) = iVar3;
    }
    FUN_00692100(*(int *)(iVar1 + 0xc) >> 0x13 & 0xff,param_1);
    if ((*(uint *)(iVar1 + 0xc) & 0x7f80000) == 0x7f80000) {
      FUN_00692100(0,param_1);
    }
    if (((*(uint *)(iVar1 + 0xc) & 0x7f800) != 0) &&
       (FUN_00692100((int)*(uint *)(iVar1 + 0xc) >> 0xb & 0xff,param_1),
       (*(uint *)(iVar1 + 0xc) & 0x7f800) == 0x7f800)) {
      FUN_00692100(0,param_1);
    }
  }
  return;
}

