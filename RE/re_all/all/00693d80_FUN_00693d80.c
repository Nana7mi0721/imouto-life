
void FUN_00693d80(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piStack_18;
  int iStack_14;
  int iStack_10;
  int *piStack_c;
  
  iVar4 = param_1;
  iVar2 = *(int *)(param_1 + 0x104);
  iVar8 = *(int *)(param_1 + 0x180);
  iVar5 = (*(code *)**(undefined4 **)(param_1 + 4))
                    (param_1,1,*(int *)(param_1 + 0x4c) * iVar2 * 0x14);
  iStack_10 = 0;
  if (0 < *(int *)(param_1 + 0x4c)) {
    piStack_18 = (int *)(*(int *)(param_1 + 0x54) + 8);
    piStack_c = (int *)(iVar8 + 8);
    param_1 = iVar5;
    do {
      puVar6 = (undefined4 *)
               (**(code **)(*(int *)(iVar4 + 4) + 8))
                         (iVar4,1,(piStack_18[5] * *(int *)(iVar4 + 0x100) * *(int *)(iVar4 + 0x108)
                                  ) / *piStack_18,iVar2 * 3);
      puVar1 = (undefined4 *)(param_1 + iVar2 * 4);
      puVar10 = puVar6;
      puVar9 = puVar1;
      for (uVar7 = (uint)(iVar2 * 0xc) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar9 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar9 = puVar9 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
      if (0 < iVar2) {
        puVar9 = (undefined4 *)(iVar2 * 0x10 + param_1);
        puVar10 = puVar6 + iVar2 * 2;
        iVar8 = param_1 - (int)puVar6;
        iStack_14 = iVar2;
        do {
          uVar3 = *puVar10;
          puVar10 = puVar10 + 1;
          *(undefined4 *)(iVar8 + (int)puVar6) = uVar3;
          *puVar9 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar9 = puVar9 + 1;
          iStack_14 = iStack_14 + -1;
        } while (iStack_14 != 0);
      }
      *piStack_c = (int)puVar1;
      piStack_c = piStack_c + 1;
      param_1 = param_1 + iVar2 * 0x14;
      iStack_10 = iStack_10 + 1;
      piStack_18 = piStack_18 + 0x16;
    } while (iStack_10 < *(int *)(iVar4 + 0x4c));
  }
  return;
}

