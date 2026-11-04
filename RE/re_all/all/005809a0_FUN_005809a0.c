
undefined4 FUN_005809a0(int param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  param_1 = param_1 * 0x2f0;
  if (*(int *)(&DAT_00cc44e0 + param_1) == 0) {
    return 0xffffffff;
  }
  puVar1 = &DAT_00cc4524 + param_1;
  FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x95);
  if (*(int *)(&DAT_00cc4514 + param_1) == *(int *)(&DAT_00cc4510 + param_1)) {
    FUN_0056dac0(puVar1);
    FUN_0056bca0(&DAT_007d99d8,param_1 + 0xcc4750,*(undefined4 *)(&DAT_00cc4510 + param_1));
    return 0xffffffff;
  }
  if (param_3 == 0xffffffff) {
LAB_00580a25:
    if (*(int *)(&DAT_00cc4514 + param_1) == 0) {
      piVar8 = *(int **)(&DAT_00cc44e4 + param_1);
      uVar6 = 0;
    }
    else {
      uVar6 = *(int *)(&DAT_00cc451c + param_1) + 1;
      if ((int)uVar6 < *(int *)(&DAT_00cc4510 + param_1)) {
        piVar8 = (int *)(*(int *)(&DAT_00cc44e4 + param_1) + uVar6 * 4);
      }
      else {
        uVar6 = *(int *)(&DAT_00cc4518 + param_1) - 1;
        if ((int)uVar6 < 1) {
          piVar8 = *(int **)(&DAT_00cc44e4 + param_1);
          uVar6 = 0;
          iVar4 = *piVar8;
          while (iVar4 != 0) {
            piVar8 = piVar8 + 1;
            uVar6 = uVar6 + 1;
            iVar4 = *piVar8;
          }
        }
        else {
          piVar8 = (int *)(*(int *)(&DAT_00cc44e4 + param_1) + uVar6 * 4);
        }
      }
    }
  }
  else {
    uVar6 = param_3 & 0xffff;
    if (*(int *)(*(int *)(&DAT_00cc44e4 + param_1) + uVar6 * 4) != 0) goto LAB_00580a25;
    piVar8 = (int *)(*(int *)(&DAT_00cc44e4 + param_1) + uVar6 * 4);
  }
  puVar5 = (uint *)FUN_0056e050(*(undefined4 *)(&DAT_00cc450c + param_1),
                                "..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0xc4);
  *piVar8 = (int)puVar5;
  if (puVar5 == (uint *)0x0) {
    FUN_0056dac0(puVar1);
    FUN_0056bca0(&DAT_007d9998,param_1 + 0xcc4750);
    return 0xffffffff;
  }
  if (param_3 == 0xffffffff) {
    *(int *)(&DAT_00cc4520 + param_1) = *(int *)(&DAT_00cc4520 + param_1) + 1;
    if (0x3fe < *(int *)(&DAT_00cc4520 + param_1)) {
      *(undefined4 *)(&DAT_00cc4520 + param_1) = 0;
    }
    puVar5 = (uint *)*piVar8;
    uVar7 = *(uint *)(&DAT_00cc4520 + param_1);
  }
  else {
    uVar7 = (int)param_3 >> 0x10 & 0x3ff;
  }
  *puVar5 = uVar7;
  *(undefined4 *)(*piVar8 + 8) = *(undefined4 *)(&DAT_00cc450c + param_1);
  *(undefined4 *)(*piVar8 + 0x1c) = 0;
  if (param_2 != 0) {
    *(undefined4 *)(*piVar8 + 0x10) = 1;
    *(undefined4 *)(*piVar8 + 0x18) = 0xffffffff;
  }
  ((int *)*piVar8)[1] = *(int *)*piVar8 << 0x10 | *(uint *)(&DAT_00cc4508 + param_1) | uVar6;
  uVar3 = *(undefined4 *)(*piVar8 + 4);
  *(int *)(&DAT_00cc4514 + param_1) = *(int *)(&DAT_00cc4514 + param_1) + 1;
  if (*(int *)(&DAT_00cc4514 + param_1) == 1) {
    *(uint *)(&DAT_00cc451c + param_1) = uVar6;
  }
  else {
    if (*(int *)(&DAT_00cc451c + param_1) < (int)uVar6) {
      *(uint *)(&DAT_00cc451c + param_1) = uVar6;
    }
    if (*(int *)(&DAT_00cc4518 + param_1) <= (int)uVar6) goto LAB_00580b2c;
  }
  *(uint *)(&DAT_00cc4518 + param_1) = uVar6;
LAB_00580b2c:
  iVar4 = *piVar8;
  puVar2 = (undefined4 *)(iVar4 + 0x20);
  *puVar2 = *(undefined4 *)(iVar4 + 4);
  *(int *)(iVar4 + 0x24) = iVar4;
  *(undefined **)(iVar4 + 0x28) = &DAT_00cc44e8 + param_1;
  *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(&DAT_00cc44f4 + param_1);
  *(undefined4 **)(*(int *)(&DAT_00cc44f4 + param_1) + 8) = puVar2;
  *(undefined4 **)(&DAT_00cc44f4 + param_1) = puVar2;
  if (*(code **)(&DAT_00cc4744 + param_1) != (code *)0x0) {
    (**(code **)(&DAT_00cc4744 + param_1))(*piVar8);
  }
  FUN_0056dac0(puVar1);
  return uVar3;
}

