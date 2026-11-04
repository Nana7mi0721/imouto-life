
undefined4 FUN_005a5300(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = 0;
  iVar3 = 0;
  if (DAT_00f3a04c != 0) {
    if ((((DAT_00cc47d0 != 0) && (-1 < (int)DAT_00a38120)) &&
        ((DAT_00a38120 & 0x7c000000) == DAT_00cc47f8)) &&
       ((int)(DAT_00a38120 & 0xffff) < DAT_00cc4800)) {
      iVar3 = *(int *)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4);
    }
    if (((DAT_00cc79c0 != 0) && (-1 < (int)DAT_00a38120)) &&
       (((DAT_00a38120 & 0x7c000000) == DAT_00cc79e8 &&
        ((int)(DAT_00a38120 & 0xffff) < DAT_00cc79f0)))) {
      iVar2 = *(int *)(DAT_00cc79c4 + (DAT_00a38120 & 0xffff) * 4);
    }
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    iVar1 = FUN_005d35f0();
    if ((iVar1 != 0) && (DAT_00e79688 != 0)) {
      FUN_005d3950();
      DAT_00e79688 = 0;
    }
    if (iVar2 == 0) {
      if (iVar3 == 0) {
        iVar3 = DAT_00ddb5c4;
        if (DAT_00ddb5c4 == 0) {
          iVar3 = DAT_00ddb5b4;
        }
      }
      else {
        iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x4c) + 0x3c) + 4 + DAT_00a38140 * 4);
      }
    }
    else {
      iVar3 = *(int *)(*(int *)(iVar2 + 0x450) + 4);
    }
    if ((DAT_00ca39f4 != 0) && (DAT_00f3a154 != 0)) {
      FUN_005a0bd0(iVar3,0);
    }
    FUN_0056d380(&local_18,0,0x18);
    local_8 = 0;
    local_4 = 0x3f800000;
    local_18 = 0;
    local_14 = 0;
    local_10 = DAT_00a381b4;
    local_c = DAT_00a381b8;
    FUN_005a09f0(&local_18);
    if (param_1 != (undefined4 *)0x0) {
      local_28 = *param_1;
      local_24 = param_1[1];
      local_20 = param_1[2];
      local_1c = param_1[3];
    }
    if (param_1 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = &local_28;
    }
    FUN_005d3970(param_1 != (undefined4 *)0x0,puVar4,1,
                 (DAT_00a37ed8 << 8 | DAT_00a37edc) << 8 | DAT_00a37ee0,0x3f800000,0);
    if (DAT_00ddb5c8 != 0) {
      if (param_1 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = &local_28;
      }
      FUN_005d3970(param_1 != (undefined4 *)0x0,puVar4,2,0,0x3f800000,0);
    }
    if ((DAT_00ca39f4 != 0) && (DAT_00f3a154 != 0)) {
      FUN_005a0bd0(DAT_00f3a154,0);
    }
    local_10 = DAT_00a3819c - DAT_00a38194;
    local_18 = DAT_00a38194;
    local_c = DAT_00a381a0 - DAT_00a38198;
    local_14 = DAT_00a38198;
    FUN_005a09f0(&local_18);
  }
  return 0;
}

