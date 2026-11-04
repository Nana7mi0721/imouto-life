
int FUN_00525f80(undefined4 *param_1,HANDLE param_2,HANDLE param_3,int param_4,undefined4 *param_5,
                undefined4 *param_6,undefined4 param_7,undefined4 param_8,uint param_9)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_8ac;
  int local_8a8;
  int local_8a4;
  undefined1 local_8a0 [4];
  undefined4 local_89c;
  undefined4 local_898;
  int local_894;
  undefined4 local_88c;
  undefined4 local_888;
  undefined4 local_460;
  undefined4 local_45c;
  int local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448 [266];
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_888._0_1_ = 0;
  _memset((void *)((int)&local_888 + 1),0,0x43f);
  if (DAT_00a37d70 == 0) {
    return -1;
  }
  if (param_4 != 0) {
    GetObjectA(param_2,0x18,local_8a0);
    local_14 = local_88c;
    local_1c = local_898;
    local_18 = ((int)(local_894 + 3 + (local_894 + 3 >> 0x1f & 3U)) >> 2) * 4;
    local_20 = local_89c;
    param_5 = local_448;
    puVar5 = param_1;
    puVar6 = local_448;
    for (iVar4 = 0x10a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    param_6 = (undefined4 *)0x0;
    local_10 = 0;
    local_c = 0;
    if (param_3 != (HANDLE)0x0) {
      GetObjectA(param_3,0x18,local_8a0);
      local_460 = local_89c;
      local_454 = local_88c;
      local_458 = ((int)(local_894 + 3 + (local_894 + 3 >> 0x1f & 3U)) >> 2) * 4;
      local_45c = local_898;
      puVar5 = param_1;
      puVar6 = &local_888;
      for (iVar4 = 0x10a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      local_450 = 0;
      local_44c = 0;
      param_6 = &local_888;
    }
  }
  local_8a4 = FUN_00523c60(param_5,param_6,param_7,param_8,param_9,DAT_00a37f54 == 0,0);
  if (local_8a4 == 0) {
    if (param_4 != 0) {
      local_8ac = DAT_00a37f44;
      FUN_00518060(&local_8ac,param_9,0,param_1,param_2,param_3,0,0,0,0,0,0,0,0,0xffffffff,0);
      return local_8a4;
    }
    local_8ac = DAT_00a37f44;
    if (((((DAT_00cc47d0 != 0) && (-1 < (int)param_9)) && ((param_9 & 0x7c000000) == DAT_00cc47f8))
        && (((int)(param_9 & 0xffff) < DAT_00cc4800 &&
            (piVar2 = *(int **)(DAT_00cc47d4 + (param_9 & 0xffff) * 4), piVar2 != (int *)0x0)))) &&
       ((*piVar2 * 0x10000 == (param_9 & 0x3ff0000) && (piVar2[4] == 0)))) {
      if (piVar2[0xe] != 0) {
        piVar1 = (int *)(piVar2[0xe] + 0x28);
        *piVar1 = *piVar1 + -1;
        if (*(int *)(piVar2[0xe] + 0x28) == 0) {
          FUN_0056e1d0(piVar2[0xe]);
          piVar2[0xe] = 0;
        }
      }
      if ((local_8ac == 0) && (param_5 != (undefined4 *)0x0)) {
        local_8ac = 0;
        iVar4 = FUN_00542060(param_5);
        local_8a8 = iVar4 + 0x440;
        if (param_6 != (undefined4 *)0x0) {
          local_8ac = FUN_00542060(param_6);
          local_8a8 = local_8a8 + 0x440 + local_8ac;
        }
        iVar3 = FUN_0056e030(local_8a8 + 0x2c,
                             "..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x67f4);
        piVar2[0xe] = iVar3;
        if (iVar3 == 0) {
          FUN_0056bb10(&DAT_007d53e8);
          return local_8a4;
        }
        FUN_0056d380(iVar3,0,0x2c);
        *(int *)(piVar2[0xe] + 8) = piVar2[0xe] + 0x2c;
        FUN_0056d420(*(undefined4 *)(piVar2[0xe] + 8),param_5,0x440);
        *(int *)(*(int *)(piVar2[0xe] + 8) + 0x434) = *(int *)(piVar2[0xe] + 8) + 0x440;
        FUN_0056d420(*(undefined4 *)(*(int *)(piVar2[0xe] + 8) + 0x434),param_5[0x10d],iVar4);
        if (param_6 != (undefined4 *)0x0) {
          *(int *)(piVar2[0xe] + 0xc) = *(int *)(*(int *)(piVar2[0xe] + 8) + 0x434) + iVar4;
          FUN_0056d420(*(undefined4 *)(piVar2[0xe] + 0xc),param_6,0x440);
          *(int *)(*(int *)(piVar2[0xe] + 0xc) + 0x434) = *(int *)(piVar2[0xe] + 0xc) + 0x440;
          FUN_0056d420(*(undefined4 *)(*(int *)(piVar2[0xe] + 0xc) + 0x434),param_6[0x10d],local_8ac
                      );
        }
        *(undefined4 *)(piVar2[0xe] + 0x20) = 0;
        *(undefined4 *)(piVar2[0xe] + 0x24) = 0;
        *(undefined4 *)(piVar2[0xe] + 0x28) = 1;
        return local_8a4;
      }
      piVar2[0xe] = 0;
    }
  }
  return local_8a4;
}

