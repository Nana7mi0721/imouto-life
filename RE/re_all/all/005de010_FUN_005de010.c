
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005de010(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_70 [5];
  int local_5c [3];
  undefined4 local_50;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (DAT_00ee9b14 == 0) {
    uVar1 = FUN_0056bb10(&DAT_008021f8);
    return uVar1;
  }
  if (DAT_00ee9b18 == 0) {
    uVar1 = FUN_0056bb10(&DAT_00802198);
    return uVar1;
  }
  _DAT_00f3a180 = param_1;
  _DAT_00f3a184 = param_2;
  if (DAT_00f3a1a0 == 0) {
    FUN_0056d380(&local_2c,0,0x2c);
    local_1c = DAT_00ee9b18;
    local_10 = 0;
    local_c = 8;
    local_2c = DAT_00ca39cc;
    local_28 = DAT_00ca39d0;
    local_8 = 0;
    local_24 = 1;
    local_20 = 1;
    local_18 = 1;
    local_14 = 0;
    iVar2 = FUN_005d4ee0(&local_2c,0,&DAT_00f3a1a0,0);
    if (iVar2 < 0) {
      uVar1 = FUN_0056bb10(&DAT_00802360);
      return uVar1;
    }
    FUN_0056d380(local_5c,0,0x18);
    local_5c[0] = DAT_00ee9b18;
    local_5c[1] = 4;
    local_50 = 1;
    iVar2 = FUN_005d4fa0(DAT_00f3a1a0,local_5c,&DAT_00f3a1a4,0);
    if (iVar2 < 0) {
      uVar1 = FUN_0056bb10(&DAT_00802318);
      return uVar1;
    }
    local_38 = DAT_00ca39cc;
    local_34 = DAT_00ca39d0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_30 = 1;
    FUN_005d52f0(DAT_00f3a1a0,0,&local_44,DAT_00ca39d4,DAT_00ca39d8,0,0);
  }
  if (DAT_00f3a188 == 0) {
    FUN_0056d380(&local_2c,0,0x2c);
    local_1c = DAT_00ee9a54;
    local_10 = 0;
    local_c = 0x28;
    local_2c = DAT_00ca39cc;
    local_28 = DAT_00ca39d0;
    local_8 = 0;
    local_24 = 1;
    local_20 = 1;
    local_18 = 1;
    local_14 = 0;
    iVar2 = FUN_005d4ee0(&local_2c,0,&DAT_00f3a188,0);
    if (iVar2 < 0) {
      FUN_0056bb10(&DAT_008022e4);
      return 0xffffffff;
    }
    FUN_0056d380(local_5c,0,0x18);
    local_5c[0] = DAT_00ee9a54;
    local_5c[1] = 4;
    local_50 = 1;
    iVar2 = FUN_005d4fa0(DAT_00f3a188,local_5c,&DAT_00f3a18c,0);
    if (iVar2 < 0) {
      uVar1 = FUN_0056bb10(&DAT_00802298);
      return uVar1;
    }
    FUN_0056d380(local_70,0,0x14);
    local_70[0] = DAT_00ee9a54;
    local_70[1] = 4;
    iVar2 = FUN_005d5000(DAT_00f3a188,local_70,&DAT_00f3a190,0);
    if (iVar2 < 0) {
      uVar1 = FUN_0056bb10(&DAT_00802248);
      return uVar1;
    }
  }
  return 0;
}

