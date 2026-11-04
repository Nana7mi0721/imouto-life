
void __thiscall FUN_00620ae0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 local_20 [8];
  
  if (param_2 < 0) {
    param_2 = param_1[3];
  }
  if ((*param_1 != 0) && (0 < param_2)) {
    do {
      puVar3 = (undefined4 *)*param_1;
      bVar5 = 0;
      iVar6 = puVar3[10];
      while (iVar6 != 0) {
        puVar1 = (undefined4 *)puVar3[8];
        if (puVar3 < puVar1) {
          puVar8 = (undefined4 *)puVar1[10];
          iVar6 = puVar1[8];
          iVar2 = -(uint)(puVar8 == puVar3);
          iVar4 = puVar1[iVar2 + 10];
          if (iVar6 == 0) {
            *param_1 = (int)puVar3;
          }
          else {
            *(undefined4 **)(iVar6 + 0x24 + (uint)(*(undefined4 **)(iVar6 + 0x28) == puVar1) * 4) =
                 puVar3;
          }
          *(undefined4 **)(iVar4 + 0x20) = puVar3;
          puVar1[8] = puVar3;
          puVar3[8] = iVar6;
          puVar1[9] = puVar3[9];
          puVar1[10] = puVar3[10];
          *(undefined4 **)(puVar3[9] + 0x20) = puVar1;
          *(undefined4 **)(puVar3[10] + 0x20) = puVar1;
          puVar3[(puVar8 == puVar3) + 9] = puVar1;
          puVar3[iVar2 + 10] = iVar4;
          puVar8 = puVar1;
          puVar9 = local_20;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          puVar8 = puVar3;
          puVar9 = puVar1;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
          puVar8 = local_20;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar3 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar3 = puVar3 + 1;
          }
          puVar3 = puVar1;
        }
        uVar7 = (uint)param_1[4] >> bVar5;
        bVar5 = bVar5 + 1 & 0x1f;
        puVar3 = (undefined4 *)puVar3[(uVar7 & 1) + 9];
        iVar6 = puVar3[10];
      }
      iVar4 = FUN_00620e10(param_1,puVar3);
      iVar6 = 0;
      if (iVar4 != 0) {
        iVar6 = *param_1;
      }
      FUN_00620c20(param_1,iVar6,puVar3);
      param_2 = param_2 + -1;
      param_1[4] = param_1[4] + 1;
    } while (param_2 != 0);
  }
  return;
}

