
undefined4
FUN_00527370(uint param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  int local_468;
  int local_460;
  int local_45c;
  int local_458;
  int local_454;
  undefined4 local_450;
  uint local_44c;
  int *local_448;
  undefined4 local_444;
  undefined1 local_440 [1064];
  undefined4 local_18;
  undefined4 local_14;
  
  if (((((DAT_00cc47d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc47f8)) ||
      ((DAT_00cc4800 <= (int)(param_1 & 0xffff) ||
       (local_448 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), local_448 == (int *)0x0)))) ||
     ((*local_448 * 0x10000 != (param_1 & 0x3ff0000) || (local_448[4] != 0)))) {
    return 0xffffffff;
  }
  if (((param_2 == 0) && (param_3 == 0)) &&
     ((param_4 == local_448[0x18] &&
      (((param_5 == local_448[0x19] && (param_7 == 3)) &&
       (iVar7 = local_448[0x13], *(char *)(iVar7 + 8) == '\x01')))))) {
    local_44c = (uint)*(byte *)(iVar7 + 9);
    iVar7 = *(int *)(iVar7 + 0x34);
    iVar4 = (-(uint)(local_44c != 0) & 5) + 1;
    iVar5 = iVar7 * iVar4 * 0x440;
    iVar1 = FUN_0056e030(iVar5,"..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x4843);
    if (iVar1 != 0) {
      FUN_0056d380(iVar1,0,iVar5);
      iVar5 = 0;
      local_468 = 0;
      if (iVar4 != 0) {
        do {
          iVar6 = 0;
          if (0 < iVar7) {
            iVar8 = iVar5 * 0x440 + iVar1;
LAB_005274e0:
            FUN_005185c0(local_448[0x18],local_448[0x19],iVar6,&local_450,&local_444);
            local_460 = 0;
            local_45c = 0;
            local_458 = local_450;
            local_454 = local_444;
            iVar2 = FUN_005229c0(&local_460,local_440,param_1,local_468,iVar6,1,0);
            if (iVar2 < 0) {
              FUN_0056e1d0(iVar1);
              if (iVar5 < 1) {
                return 0xffffffff;
              }
              iVar7 = 0;
              do {
                FUN_005421c0(iVar7);
                iVar7 = iVar7 + 0x440;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              return 0xffffffff;
            }
            iVar2 = FUN_00541fe0(local_18,local_14,local_440,iVar8);
            if (-1 < iVar2) goto code_r0x00527567;
            FUN_0056e1d0(iVar1);
            if (0 < iVar5) {
              iVar7 = 0;
              do {
                FUN_005421c0(iVar7);
                iVar7 = iVar7 + 0x440;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            puVar9 = &DAT_007d56e0;
            goto LAB_0052748e;
          }
LAB_00527598:
          local_468 = local_468 + 1;
        } while (local_468 < iVar4);
      }
      uVar3 = FUN_005409e0(param_6,iVar1,local_44c,iVar7);
      if (0 < iVar5) {
        iVar7 = iVar1;
        do {
          FUN_005421c0(iVar7);
          iVar7 = iVar7 + 0x440;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      FUN_0056e1d0(iVar1);
      return uVar3;
    }
    puVar9 = &DAT_007d5738;
LAB_0052748e:
    FUN_0056bb10(puVar9);
  }
  else if ((((param_2 < param_4) && (param_3 < param_5)) &&
           ((-1 < param_2 && ((-1 < param_3 && (param_4 <= local_448[0x18])))))) &&
          (param_5 <= local_448[0x19])) {
    local_460 = param_2;
    local_45c = param_3;
    local_458 = param_4;
    local_454 = param_5;
    iVar7 = FUN_005229c0(&local_460,local_440,param_1,0,0,1,0);
    if (-1 < iVar7) {
      switch(param_7) {
      case 0:
        FUN_0054e0d0(param_6,local_440);
        FUN_00517420();
        return 0;
      case 1:
        FUN_00540db0(param_6,local_440,param_8,param_9);
        FUN_00517420();
        return 0;
      case 2:
        FUN_00540dd0(param_6,local_440,param_10);
        FUN_00517420();
        return 0;
      case 3:
        FUN_005409e0(param_6,local_440,0,1);
      }
      FUN_00517420();
      return 0;
    }
  }
  return 0xffffffff;
code_r0x00527567:
  FUN_0054ecc0(0,0,local_440,iVar8);
  FUN_00517420();
  iVar6 = iVar6 + 1;
  iVar5 = iVar5 + 1;
  iVar8 = iVar8 + 0x440;
  if (iVar7 <= iVar6) goto LAB_00527598;
  goto LAB_005274e0;
}

