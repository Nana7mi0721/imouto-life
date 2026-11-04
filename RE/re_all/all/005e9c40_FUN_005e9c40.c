
undefined4 FUN_005e9c40(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *local_34;
  undefined4 *local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int local_18 [6];
  
  if (DAT_00dccde0 != '\0') {
    if (param_2 == 0) {
      if ((((DAT_00cc6e00 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc6e28))
         && ((((int)(param_1 & 0xffff) < DAT_00cc6e30 &&
              (local_34 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), local_34 != (int *)0x0))
             && ((*local_34 * 0x10000 == (param_1 & 0x3ff0000) && (local_34[4] == 0))))))
      goto LAB_005e9cfc;
    }
    else if (((DAT_00cc6e00 != 0) && (-1 < (int)param_1)) &&
            (((param_1 & 0x7c000000) == DAT_00cc6e28 &&
             ((((int)(param_1 & 0xffff) < DAT_00cc6e30 &&
               (local_34 = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), local_34 != (int *)0x0)
               ) && (*local_34 * 0x10000 == (param_1 & 0x3ff0000))))))) {
LAB_005e9cfc:
      iVar1 = local_34[0x10];
      local_28 = 0;
      if (0 < *(int *)(iVar1 + 0x7c)) {
        local_20 = (int *)(*(int *)(iVar1 + 0x80) + 0x170);
        local_24 = (int *)(local_34[0x5f] + 0x208);
        do {
          if (local_20[0x12] != 0) {
            local_2c = 0;
            if (0 < *local_20) {
              piVar5 = (int *)(local_20[1] + 0x40);
              local_30 = (undefined4 *)(*local_24 + 0xac);
              do {
                if (*(char *)((int)piVar5 + 10) != '\0') {
                  puVar6 = (undefined4 *)*local_30;
                  iVar4 = 0;
                  if (0 < *piVar5) {
                    piVar7 = (int *)(piVar5[1] + 0x124);
                    do {
                      if ((short)piVar7[-0x48] == 3) {
                        if (*(int *)puVar6[3] == 0) {
                          uVar2 = FUN_0056e030(piVar7[-0x46] * 0xc,
                                               "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D11.cpp"
                                               ,0x4a9);
                          *(undefined4 *)puVar6[3] = uVar2;
                          if (*(int *)puVar6[3] == 0) {
                            return 0xffffffff;
                          }
                          *(undefined1 *)(local_34 + 0x67) = 1;
                          *(undefined1 *)(*(int *)*puVar6 + 0x210) = 1;
                        }
                      }
                      else if ((*(int *)(puVar6[3] + 4) == 0) && (*piVar7 != 0)) {
                        FUN_0056d380(local_18,0,0x18);
                        local_18[0] = *(int *)(*piVar7 + 0x10) * piVar7[-0x46];
                        local_18[1] = 0;
                        local_18[2] = 1;
                        local_18[3] = 0;
                        iVar3 = FUN_005d4e80(local_18,0,puVar6[3] + 4,param_2);
                        if (iVar3 < 0) {
                          return 0xffffffff;
                        }
                        *(undefined1 *)(local_34 + 0x67) = 1;
                        *(undefined1 *)(*(int *)*puVar6 + 0x210) = 1;
                      }
                      iVar4 = iVar4 + 1;
                      piVar7 = piVar7 + 0x4e;
                      puVar6 = puVar6 + 6;
                    } while (iVar4 < *piVar5);
                  }
                }
                local_30 = local_30 + 0x2e;
                local_2c = local_2c + 1;
                piVar5 = piVar5 + 0x1f;
              } while (local_2c < *local_20);
            }
          }
          local_28 = local_28 + 1;
          local_24 = local_24 + 0xae;
          local_20 = local_20 + 0x75;
        } while (local_28 < *(int *)(iVar1 + 0x7c));
      }
      return 0;
    }
  }
  return 0xffffffff;
}

