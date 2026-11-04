
undefined4 FUN_0057ae10(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_8;
  
  DAT_00ca39f8 = DAT_00ca39f8 + -1;
  if (((DAT_00ca39f8 == 0) && (FUN_00514e10(&param_1,&DAT_00a38194), param_1 != param_3)) &&
     (param_2 != param_4)) {
    if (DAT_00a37d78 != 0) {
      FUN_005d9190(&param_1);
      return 0;
    }
    if (DAT_00ca39f4 != 0) {
      iVar1 = FUN_00519300(DAT_00a38120,0);
      puVar3 = (undefined *)(iVar1 + 0x88);
      if (iVar1 == 0) {
        puVar3 = &DAT_00a37df8;
      }
      uVar7 = (uint)*(byte *)(*(int *)(*(int *)(puVar3 + 0x14) + 0x14) + 4);
      param_3 = param_3 - param_1;
      local_8 = param_4 - param_2;
      iVar9 = DAT_00ca39d8 - param_3;
      iVar1 = *(int *)(DAT_00ca3a14 + 0xc) - param_3 * uVar7;
      iVar8 = *(int *)(*(int *)(puVar3 + 0x14) + 0xc) - param_3 * uVar7;
      pcVar6 = (char *)(DAT_00ca39d8 * param_2 + DAT_00ca39d4 + param_1);
      puVar2 = (undefined4 *)
               (*(int *)(DAT_00ca3a14 + 0xc) * param_2 + uVar7 * param_1 + DAT_00ca3a0c);
      puVar4 = (undefined4 *)
               (*(int *)(*(int *)(puVar3 + 0x14) + 0xc) * param_2 + *(int *)(puVar3 + 0xc) +
               uVar7 * param_1);
      if (DAT_00ca39e4 == 1) {
        if (uVar7 == 2) {
          do {
            iVar5 = param_3;
            do {
              if (*pcVar6 != '\0') {
                *(undefined2 *)puVar4 = *(undefined2 *)puVar2;
              }
              puVar2 = (undefined4 *)((int)puVar2 + 2);
              puVar4 = (undefined4 *)((int)puVar4 + 2);
              pcVar6 = pcVar6 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            puVar2 = (undefined4 *)((int)puVar2 + iVar1);
            puVar4 = (undefined4 *)((int)puVar4 + iVar8);
            pcVar6 = pcVar6 + iVar9;
            local_8 = local_8 + -1;
          } while (local_8 != 0);
          return 0;
        }
        if (uVar7 == 4) {
          do {
            iVar5 = param_3;
            do {
              if (*pcVar6 != '\0') {
                *puVar4 = *puVar2;
              }
              puVar2 = puVar2 + 1;
              puVar4 = puVar4 + 1;
              pcVar6 = pcVar6 + 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            puVar2 = (undefined4 *)((int)puVar2 + iVar1);
            puVar4 = (undefined4 *)((int)puVar4 + iVar8);
            pcVar6 = pcVar6 + iVar9;
            local_8 = local_8 + -1;
          } while (local_8 != 0);
          return 0;
        }
      }
      else if (uVar7 == 2) {
        do {
          iVar5 = param_3;
          do {
            if (*pcVar6 == '\0') {
              *(undefined2 *)puVar4 = *(undefined2 *)puVar2;
            }
            puVar2 = (undefined4 *)((int)puVar2 + 2);
            puVar4 = (undefined4 *)((int)puVar4 + 2);
            pcVar6 = pcVar6 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar2 = (undefined4 *)((int)puVar2 + iVar1);
          puVar4 = (undefined4 *)((int)puVar4 + iVar8);
          pcVar6 = pcVar6 + iVar9;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      else if (uVar7 == 4) {
        do {
          iVar5 = param_3;
          do {
            if (*pcVar6 == '\0') {
              *puVar4 = *puVar2;
            }
            puVar2 = puVar2 + 1;
            puVar4 = puVar4 + 1;
            pcVar6 = pcVar6 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          puVar2 = (undefined4 *)((int)puVar2 + iVar1);
          puVar4 = (undefined4 *)((int)puVar4 + iVar8);
          pcVar6 = pcVar6 + iVar9;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
        return 0;
      }
    }
  }
  return 0;
}

