
undefined4 FUN_00580b80(uint param_1)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = (param_1 >> 0x1a & 0x1f) * 0x2f0;
  if (*(int *)(&DAT_00cc44e0 + iVar5) == 0) {
    return 0xffffffff;
  }
  puVar1 = &DAT_00cc4524 + iVar5;
  FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x119);
  uVar4 = param_1 & 0xffff;
  if (((((*(int *)(&DAT_00cc44e0 + iVar5) == 0) || ((int)param_1 < 0)) ||
       ((param_1 & 0x7c000000) != *(uint *)(&DAT_00cc4508 + iVar5))) ||
      ((*(int *)(&DAT_00cc4510 + iVar5) <= (int)uVar4 ||
       (piVar2 = *(int **)(*(int *)(&DAT_00cc44e4 + iVar5) + uVar4 * 4), piVar2 == (int *)0x0)))) ||
     (*piVar2 * 0x10000 != (param_1 & 0x3ff0000))) {
    FUN_0056dac0(puVar1);
    return 0xffffffff;
  }
  if ((piVar2[4] != 0) && ((piVar2[6] < 0 || (iVar3 = FUN_0057fc10(piVar2[6],1), iVar3 < -1)))) {
    FUN_0056dac0(puVar1);
    iVar3 = piVar2[4];
    while (iVar3 != 0) {
      FUN_0057fe80();
      FUN_0056da20(0);
      iVar3 = piVar2[4];
    }
    FUN_0056da60(puVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxHandle.cpp",0x138);
  }
  if ((*(code **)(&DAT_00cc4748 + iVar5) == (code *)0x0) ||
     (iVar3 = (**(code **)(&DAT_00cc4748 + iVar5))(piVar2), iVar3 != 1)) {
    if ((undefined4 *)piVar2[3] != (undefined4 *)0x0) {
      *(undefined4 *)piVar2[3] = 0xffffffff;
    }
    *(int *)(piVar2[10] + 0xc) = piVar2[0xb];
    *(int *)(piVar2[0xb] + 8) = piVar2[10];
    FUN_0056e1d0(piVar2);
    *(undefined4 *)(*(int *)(&DAT_00cc44e4 + iVar5) + uVar4 * 4) = 0;
    piVar2 = (int *)(&DAT_00cc4514 + iVar5);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      *(undefined4 *)(&DAT_00cc451c + iVar5) = 0;
      *(undefined4 *)(&DAT_00cc4518 + iVar5) = 0;
      FUN_0056dac0(puVar1);
      return 0;
    }
    if (uVar4 == *(uint *)(&DAT_00cc451c + iVar5)) {
      if (*(int *)(*(int *)(&DAT_00cc44e4 + iVar5) + *(uint *)(&DAT_00cc451c + iVar5) * 4) == 0) {
        do {
          *(int *)(&DAT_00cc451c + iVar5) = *(int *)(&DAT_00cc451c + iVar5) + -1;
        } while (*(int *)(*(int *)(&DAT_00cc44e4 + iVar5) + *(int *)(&DAT_00cc451c + iVar5) * 4) ==
                 0);
        FUN_0056dac0(puVar1);
        return 0;
      }
    }
    else if (uVar4 == *(uint *)(&DAT_00cc4518 + iVar5)) {
      iVar3 = *(int *)(*(int *)(&DAT_00cc44e4 + iVar5) + *(uint *)(&DAT_00cc4518 + iVar5) * 4);
      while (iVar3 == 0) {
        *(int *)(&DAT_00cc4518 + iVar5) = *(int *)(&DAT_00cc4518 + iVar5) + 1;
        iVar3 = *(int *)(*(int *)(&DAT_00cc44e4 + iVar5) + *(int *)(&DAT_00cc4518 + iVar5) * 4);
      }
    }
  }
  FUN_0056dac0(puVar1);
  return 0;
}

