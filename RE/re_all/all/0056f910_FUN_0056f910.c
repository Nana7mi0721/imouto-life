
undefined4 FUN_0056f910(int *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  int local_10;
  
  if (param_1[0x221] == 1) {
    iVar3 = FUN_0056ef10(param_1);
    while (iVar3 == 0) {
      FUN_0056da20(0);
      iVar3 = FUN_0056ef10(param_1);
    }
  }
  uVar1 = *(ushort *)((int)param_2 + 0x402);
  iVar3 = param_1[0x15];
  local_10 = 0;
  if (*param_1 == 0) {
    iVar2 = *(int *)(iVar3 + 0x10);
    piVar8 = (int *)(*(int *)(iVar3 + 0x18) + param_1[0x12]);
    if (0 < iVar2) {
      do {
        if ((((piVar8[2] & 0x10U) != 0) &&
            (puVar4 = (ushort *)(param_1[0x14] + *piVar8), uVar1 == *puVar4)) &&
           (*(ushort *)(param_2 + 0x100) == puVar4[1])) {
          uVar7 = (uint)uVar1;
          uVar5 = 0;
          if (uVar7 != 0) {
            piVar6 = param_2;
            do {
              if (*piVar6 != *(int *)((int)piVar6 + (int)puVar4 + (4 - (int)param_2))) break;
              uVar5 = uVar5 + 1;
              piVar6 = piVar6 + 1;
            } while ((int)uVar5 < (int)uVar7);
          }
          if (uVar7 == uVar5) break;
        }
        local_10 = local_10 + 1;
        piVar8 = piVar8 + 0x10;
      } while (local_10 < iVar2);
    }
    if (local_10 != iVar2) {
      param_1[0x15] = piVar8[10] + param_1[0x13];
      return 0;
    }
  }
  else {
    piVar8 = (int *)(*(int *)(iVar3 + 0xc) + param_1[0x12]);
    iVar3 = *(int *)(iVar3 + 8);
    if (0 < iVar3) {
      do {
        if ((((*(byte *)(piVar8 + 1) & 0x10) != 0) &&
            (puVar4 = (ushort *)(param_1[0x14] + *piVar8), uVar1 == *puVar4)) &&
           (*(ushort *)(param_2 + 0x100) == puVar4[1])) {
          uVar7 = (uint)uVar1;
          uVar5 = 0;
          if (uVar7 != 0) {
            piVar6 = param_2;
            do {
              if (*piVar6 != *(int *)((int)puVar4 + (4 - (int)param_2) + (int)piVar6)) break;
              uVar5 = uVar5 + 1;
              piVar6 = piVar6 + 1;
            } while ((int)uVar5 < (int)uVar7);
          }
          if (uVar7 == uVar5) break;
        }
        local_10 = local_10 + 1;
        piVar8 = (int *)((int)piVar8 +
                        (-(uint)(*(ushort *)((int)param_1 + 10) < 2) & 0xfffffffc) + 0x2c);
      } while (local_10 < iVar3);
    }
    if (local_10 != iVar3) {
      param_1[0x15] = piVar8[8] + param_1[0x13];
      return 0;
    }
  }
  return 0xffffffff;
}

