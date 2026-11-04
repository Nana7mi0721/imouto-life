
undefined4 FUN_005bf720(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    if (*(int *)(param_1 + 0x38) == 0x10) {
      *(undefined4 *)(param_1 + 0x3c) = 0x28;
      *(undefined4 *)(param_1 + 0x40) = 0;
      goto LAB_005bf762;
    }
  }
  else if (*(int *)(param_1 + 0x38) == 0x10) {
    *(undefined4 *)(param_1 + 0x3c) = 0x29;
    *(undefined4 *)(param_1 + 0x40) = 0;
    goto LAB_005bf762;
  }
  *(undefined4 *)(param_1 + 0x40) = 2;
  *(undefined4 *)(param_1 + 0x3c) = 0x2a;
LAB_005bf762:
  if (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 0x3c) * 4) == 0) {
    FUN_0056bb10(&DAT_007fc460);
    return 0xffffffff;
  }
  if (*(int *)(*(int *)(param_1 + 0x450) + 0xc) == 0) {
    FUN_0056d380(&local_2c,0,0x2c);
    local_28 = *(undefined4 *)(param_1 + 0x124);
    local_2c = *(undefined4 *)(param_1 + 0x120);
    local_1c = (&DAT_00ee9b1c)[*(int *)(param_1 + 0x40)];
    local_24 = 1;
    local_20 = 1;
    local_18 = 1;
    local_14 = 0;
    local_10 = 0;
    local_c = 0x40;
    local_8 = 0;
    local_4 = 0;
    iVar1 = FUN_005d4ee0(&local_2c,0,*(int *)(param_1 + 0x450) + 0xc,param_2);
    if (iVar1 < 0) {
      FUN_0056bb10(&DAT_007fdc6c);
      return 0xffffffff;
    }
    FUN_0056d380(&local_5c,0,0x18);
    local_5c = (&DAT_00ee9b28)[*(int *)(param_1 + 0x40)];
    local_58 = 3;
    local_50 = 0;
    iVar1 = FUN_005d5060(*(undefined4 *)(*(int *)(param_1 + 0x450) + 0xc),&local_5c,
                         *(int *)(param_1 + 0x450) + 0x10,param_2);
    if (iVar1 < 0) {
      FUN_0056bb10(&DAT_007fdc30);
      return 0xffffffff;
    }
  }
  if (**(int **)(param_1 + 0x450) == 0) {
    FUN_0056d380(&local_2c,0,0x2c);
    local_1c = *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 0x3c) * 4);
    local_2c = *(undefined4 *)(param_1 + 0x120);
    local_28 = *(undefined4 *)(param_1 + 0x124);
    local_10 = 0;
    local_c = 0x28;
    local_8 = 0;
    local_24 = 1;
    local_20 = 1;
    local_18 = 1;
    local_14 = 0;
    iVar1 = FUN_005d4ee0(&local_2c,0,*(undefined4 *)(param_1 + 0x450),param_2);
    if (iVar1 < 0) {
      FUN_0056bb10(&DAT_007fc3f0);
      return 0xffffffff;
    }
    FUN_0056d380(&local_70,0,0x14);
    local_70 = *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 0x3c) * 4);
    local_6c = 4;
    iVar1 = FUN_005d5000(**(undefined4 **)(param_1 + 0x450),&local_70,
                         *(undefined4 **)(param_1 + 0x450) + 2,param_2);
    if (iVar1 < 0) {
      FUN_0056bca0(&DAT_007fdbb0,*(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 0x3c) * 4),
                   *(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x124));
      return 0xffffffff;
    }
    FUN_0056d380(&local_44,0,0x18);
    local_44 = *(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 0x3c) * 4);
    local_40 = 4;
    local_38 = 1;
    iVar1 = FUN_005d4fa0(**(undefined4 **)(param_1 + 0x450),&local_44,
                         *(undefined4 **)(param_1 + 0x450) + 1,param_2);
    if (iVar1 < 0) {
      FUN_0056bca0(&DAT_007fdb30,*(undefined4 *)(&DAT_00ee9a58 + *(int *)(param_1 + 0x3c) * 4),
                   *(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x124));
      return 0xffffffff;
    }
  }
  return 0;
}

