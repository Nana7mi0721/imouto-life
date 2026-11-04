
int * FUN_00570590(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  ushort *puVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int local_414;
  int local_404 [256];
  ushort local_4;
  ushort local_2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x54);
  iVar3 = FUN_00577900(*(undefined4 *)(param_1 + 0x38));
  if ((iVar3 == 0) && (iVar3 = FUN_00577900(*(undefined4 *)(param_1 + 0x38)), iVar3 == 0)) {
    FUN_0056e290(param_1,local_404,0);
  }
  else {
    iVar3 = FUN_0056fab0(param_1);
    if (-1 < iVar3) goto LAB_005706a0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 8);
  piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x54) + 0xc) + *(int *)(param_1 + 0x48));
  local_414 = 0;
  if (0 < iVar3) {
    do {
      if ((((*(byte *)(piVar4 + 1) & 0x10) == 0) &&
          (puVar5 = (ushort *)(*(int *)(param_1 + 0x50) + *piVar4), local_2 == *puVar5)) &&
         (local_4 == puVar5[1])) {
        uVar8 = (uint)local_2;
        uVar6 = 0;
        if (uVar8 != 0) {
          piVar7 = local_404;
          iVar2 = 4 - (int)piVar7;
          do {
            if (*piVar7 != *(int *)((int)puVar5 + iVar2 + (int)piVar7)) break;
            uVar6 = uVar6 + 1;
            piVar7 = piVar7 + 1;
          } while ((int)uVar6 < (int)uVar8);
        }
        if (uVar8 == uVar6) break;
      }
      local_414 = local_414 + 1;
      piVar4 = (int *)((int)piVar4 + (-(uint)(*(ushort *)(param_1 + 10) < 2) & 0xfffffffc) + 0x2c);
    } while (local_414 < iVar3);
  }
  if (local_414 != iVar3) {
    *(undefined4 *)(param_1 + 0x54) = uVar1;
    return piVar4;
  }
LAB_005706a0:
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  return (int *)0x0;
}

