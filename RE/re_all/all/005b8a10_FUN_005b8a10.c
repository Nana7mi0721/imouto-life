
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b8a10(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100 [8];
  undefined4 local_e0 [8];
  undefined4 local_c0 [8];
  undefined4 local_a0 [8];
  undefined4 local_80 [8];
  undefined4 local_60 [8];
  undefined4 local_40 [8];
  undefined4 local_20 [8];
  
  FUN_0056bb10(&DAT_007fd318);
  if (DAT_00ef1fb8 == 0) {
    local_108 = 0;
    local_104 = 0;
    puVar2 = &DAT_0086094c;
    puVar3 = local_100;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0086094c;
    puVar3 = local_e0;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0086094c;
    puVar3 = local_c0;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0086094c;
    puVar3 = local_a0;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0086094c;
    puVar3 = local_80;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0086094c;
    puVar3 = local_60;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0086094c;
    puVar3 = local_40;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0086094c;
    puVar3 = local_20;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    iVar1 = FUN_005d2940(&local_108,&DAT_00ef1fb8);
    if (iVar1 != 0) {
      FUN_0056bca0(&DAT_007fd2d0);
      return 0xffffffff;
    }
    puVar2 = &DAT_0086092c;
    puVar3 = local_100;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    iVar1 = FUN_005d2940(&local_108,&DAT_00ef1fbc);
    if (iVar1 != 0) {
      FUN_0056bca0(&DAT_007fd278);
      return 0xffffffff;
    }
  }
  if (DAT_00ef1fa8 == 0) {
    _DAT_008608f8 = 0;
    iVar1 = FUN_005d29d0(&DAT_008608f8,&DAT_00ef1fa8);
    if (iVar1 != 0) {
      FUN_0056bca0(&DAT_007fd218);
      return 0xffffffff;
    }
  }
  if (DAT_00ef1fac == 0) {
    _DAT_008608f8 = 0x15;
    iVar1 = FUN_005d29d0(&DAT_008608f8,&DAT_00ef1fac);
    if (iVar1 != 0) {
      FUN_0056bca0(&DAT_007fd1b8);
      return 0xffffffff;
    }
  }
  if (DAT_00ef1fb0 == 0) {
    iVar1 = FUN_005d29a0(&DAT_008608d0,&DAT_00ef1fb0);
    if (iVar1 != 0) {
      FUN_0056bca0(&DAT_007fd160);
      return 0xffffffff;
    }
  }
  if (DAT_00ef1fb4 == 0) {
    iVar1 = FUN_005d2970(&DAT_0086089c,&DAT_00ef1fb4);
    if (iVar1 != 0) {
      FUN_0056bca0(&DAT_007fd108);
      return 0xffffffff;
    }
  }
  FUN_0056bb10(&DAT_007d4974);
  return 0;
}

