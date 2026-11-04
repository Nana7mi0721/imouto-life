
undefined4 FUN_0057ab80(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = DAT_00ca39d4;
  iVar2 = DAT_00ca39d0;
  iVar4 = 0;
  bVar1 = false;
  local_24 = 0;
  local_1c = 0;
  local_20 = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (DAT_00ca39d4 != 0) {
    if (param_2 < DAT_00ca39cc) {
      param_2 = DAT_00ca39cc;
    }
    if (param_3 < DAT_00ca39d0) {
      param_3 = DAT_00ca39d0;
    }
    if ((DAT_00ca39cc < param_2) || (DAT_00ca39d0 < param_3)) {
      DAT_00ca39d4 = 0;
      local_1c = DAT_00ca39d8;
      local_20 = DAT_00ca39cc;
      local_18 = DAT_00ca3a00;
      local_14 = DAT_00ca3a04;
      local_10 = DAT_00ca3a08;
      bVar1 = true;
      local_24 = iVar5;
      local_c = DAT_00ca3a0c;
      local_8 = DAT_00ca3a10;
      local_4 = DAT_00ca3a14;
      FUN_0056d380(&DAT_00ca3a00,0,0x18);
      FUN_005d90d0();
      iVar4 = iVar2;
    }
  }
  DAT_00ca39cc = param_2;
  DAT_00ca39d0 = param_3;
  if (DAT_00ca39d4 == 0) {
    DAT_00ca39d8 = ((int)(param_2 + 3 + (param_2 + 3 >> 0x1f & 3U)) >> 2) * 4;
    DAT_00ca39d4 = FUN_0056e030(DAT_00ca39d8 * param_3,
                                "..\\..\\..\\..\\Source\\Library\\Main\\DxMask.cpp",0x7c2);
    FUN_0056d380(DAT_00ca39d4,0,DAT_00ca39d8 * param_3);
  }
  if (DAT_00a37d78 == 1) {
    iVar2 = FUN_005d90f0(param_2,param_3);
    if (iVar2 < 0) {
      return 0xffffffff;
    }
  }
  else {
    iVar2 = FUN_005813e0(&DAT_00ca3a00);
    if (iVar2 == 0) {
      iVar2 = FUN_00582330(&DAT_00ca3a00,param_2,param_3,0xffffffff);
      if (iVar2 < 0) {
        uVar3 = FUN_0056bb10(&DAT_007d8198);
        return uVar3;
      }
      DAT_00ca39fc = 1;
    }
  }
  if (bVar1) {
    iVar2 = 0;
    if (0 < iVar4) {
      iVar5 = local_24;
      do {
        FUN_0056d420(DAT_00ca39d8 * iVar2 + DAT_00ca39d4,iVar5,local_20);
        iVar5 = iVar5 + local_1c;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar4);
    }
    FUN_0056e1d0(local_24);
    if (DAT_00a37d78 == 1) {
      iVar2 = FUN_005d9110(local_20,iVar4);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
    }
    else {
      FUN_006c8cc0(&DAT_00ca3a00,&local_18,0,0,0,0);
      FUN_00581400(&local_18);
    }
  }
  return 0;
}

