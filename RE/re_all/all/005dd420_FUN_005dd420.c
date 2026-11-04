
undefined4 FUN_005dd420(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint local_c;
  int local_8;
  int iStack_4;
  
  if (DAT_00ddb590 == 0) {
    uVar1 = FUN_0056bb10(&DAT_008021f8);
    return uVar1;
  }
  if (DAT_00ddb594 == 0) {
    uVar1 = FUN_0056bb10(&DAT_00802198);
    return uVar1;
  }
  uVar3 = 1;
  local_c = 1;
  if (1 < param_1) {
    do {
      uVar3 = uVar3 * 2;
    } while (uVar3 < param_1);
    local_c = uVar3;
  }
  uVar3 = 1;
  if (1 < param_2) {
    do {
      uVar3 = uVar3 * 2;
    } while (uVar3 < param_2);
  }
  DAT_00f3a144 = local_c;
  DAT_00f3a148 = uVar3;
  if (DAT_00f3a14c == (int *)0x0) {
    iVar2 = FUN_005d36d0(local_c,uVar3,1,0x200,DAT_00ddb594,0,&DAT_00f3a14c,0);
    if (iVar2 != 0) {
      uVar1 = FUN_0056bb10(&DAT_00802164);
      return uVar1;
    }
    iVar2 = (**(code **)(*DAT_00f3a14c + 0x4c))(DAT_00f3a14c,0,&local_8,0,0);
    if (iVar2 == 0) {
      iVar2 = FUN_00598180(DAT_00ddb594);
      iVar2 = *(byte *)(iVar2 + 4) * DAT_00f3a144;
      iVar4 = 0;
      if (0 < (int)DAT_00f3a148) {
        do {
          FUN_0056d380(iStack_4,0,iVar2);
          iStack_4 = iStack_4 + local_8;
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)DAT_00f3a148);
      }
      (**(code **)(*DAT_00f3a14c + 0x50))(DAT_00f3a14c,0);
    }
  }
  if (DAT_00f3a150 == (int *)0x0) {
    iVar2 = FUN_005d36d0(local_c,uVar3,1,1,DAT_00ddb4d0,0,&DAT_00f3a150,0);
    if (iVar2 != 0) {
      uVar1 = FUN_0056bb10(&DAT_00802130);
      return uVar1;
    }
    if (DAT_00f3a150 == (int *)0x0) {
      return 0;
    }
  }
  if (DAT_00f3a154 == 0) {
    (**(code **)(*DAT_00f3a150 + 0x48))(DAT_00f3a150,0,&DAT_00f3a154);
  }
  return 0;
}

