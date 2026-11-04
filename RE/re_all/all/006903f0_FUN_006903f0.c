
undefined4 FUN_006903f0(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *local_30;
  int *piStack_2c;
  int *local_28;
  int iStack_24;
  int local_20;
  uint local_18;
  int local_10 [4];
  
  iVar8 = 0;
  iVar1 = *(int *)(param_1 + 0x184);
  if (0 < *(int *)(param_1 + 0x114)) {
    local_28 = local_10;
    local_30 = (int *)(param_1 + 0x118);
    do {
      iVar3 = *(int *)(*local_30 + 0xc);
      iVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x20))
                        (param_1,*(undefined4 *)(iVar1 + 0x40 + *(int *)(*local_30 + 4) * 4),
                         *(int *)(iVar1 + 8) * iVar3,iVar3,0);
      iVar8 = iVar8 + 1;
      *local_28 = iVar3;
      local_30 = local_30 + 1;
      local_28 = local_28 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x114));
  }
  local_30 = *(int **)(iVar1 + 0x10);
  if ((int)local_30 < *(int *)(iVar1 + 0x14)) {
    do {
      local_18 = *(uint *)(iVar1 + 0xc);
      if (local_18 < *(uint *)(param_1 + 0x128)) {
        do {
          iVar8 = 0;
          local_20 = 0;
          if (0 < *(int *)(param_1 + 0x114)) {
            local_28 = local_10;
            piStack_2c = (int *)(param_1 + 0x118);
            do {
              iStack_24 = 0;
              iVar3 = *piStack_2c;
              iVar6 = *(int *)(iVar3 + 0x38);
              iVar4 = iVar6 * local_18;
              if (0 < *(int *)(iVar3 + 0x3c)) {
                piVar9 = (int *)(*local_28 + (int)local_30 * 4);
                do {
                  iVar5 = *piVar9 + iVar4 * 0x80;
                  iVar7 = 0;
                  if (0 < iVar6) {
                    piVar10 = (int *)(iVar1 + 0x18 + iVar8 * 4);
                    do {
                      *piVar10 = iVar5;
                      iVar6 = *(int *)(iVar3 + 0x38);
                      iVar8 = iVar8 + 1;
                      piVar10 = piVar10 + 1;
                      iVar5 = iVar5 + 0x80;
                      iVar7 = iVar7 + 1;
                    } while (iVar7 < iVar6);
                  }
                  iStack_24 = iStack_24 + 1;
                  piVar9 = piVar9 + 1;
                } while (iStack_24 < *(int *)(iVar3 + 0x3c));
              }
              piStack_2c = piStack_2c + 1;
              local_28 = local_28 + 1;
              local_20 = local_20 + 1;
            } while (local_20 < *(int *)(param_1 + 0x114));
          }
          cVar2 = (**(code **)(*(int *)(param_1 + 0x198) + 4))(param_1,iVar1 + 0x18);
          if (cVar2 == '\0') {
            *(uint *)(iVar1 + 0xc) = local_18;
            *(int **)(iVar1 + 0x10) = local_30;
            return 0;
          }
          local_18 = local_18 + 1;
        } while (local_18 < *(uint *)(param_1 + 0x128));
      }
      local_30 = (int *)((int)local_30 + 1);
      *(undefined4 *)(iVar1 + 0xc) = 0;
    } while ((int)local_30 < *(int *)(iVar1 + 0x14));
  }
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  FUN_0068fea0(param_1);
  return 1;
}

