
undefined4 FUN_005e3bc0(uint param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *local_1c;
  int *local_18;
  int local_14;
  undefined4 *local_10;
  int local_c;
  int *local_8;
  
  if (DAT_00dccde0 != '\0') {
    if (param_2 == 0) {
      if (((((DAT_00cc6e00 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc6e28)
           ) && (((int)(param_1 & 0xffff) < DAT_00cc6e30 &&
                 (local_1c = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4),
                 local_1c != (int *)0x0)))) &&
         ((*local_1c * 0x10000 == (param_1 & 0x3ff0000) && (local_1c[4] == 0)))) goto LAB_005e3c7e;
    }
    else if ((((DAT_00cc6e00 != 0) && (-1 < (int)param_1)) &&
             ((param_1 & 0x7c000000) == DAT_00cc6e28)) &&
            ((((int)(param_1 & 0xffff) < DAT_00cc6e30 &&
              (local_1c = *(int **)(DAT_00cc6e04 + (param_1 & 0xffff) * 4), local_1c != (int *)0x0))
             && (*local_1c * 0x10000 == (param_1 & 0x3ff0000))))) {
LAB_005e3c7e:
      iVar1 = local_1c[0x10];
      bVar2 = true;
      if (((DAT_00a37d78 != 0) && ((DAT_00ddb4b0 != 0 || (DAT_00ddb5f0 != 0)))) ||
         (bVar2 = false, DAT_00a37dc8 != 0)) {
        local_c = 0;
        if (0 < *(int *)(iVar1 + 0x7c)) {
          local_8 = (int *)(*(int *)(iVar1 + 0x80) + 0x170);
          local_18 = (int *)(local_1c[0x5f] + 0x208);
          do {
            if (local_8[0x12] != 0) {
              local_14 = 0;
              if (0 < *local_8) {
                piVar4 = (int *)(local_8[1] + 0x40);
                local_10 = (undefined4 *)(*local_18 + 0xac);
                do {
                  if (*(char *)((int)piVar4 + 10) != '\0') {
                    puVar6 = (undefined4 *)*local_10;
                    iVar3 = 0;
                    if (0 < *piVar4) {
                      piVar5 = (int *)(piVar4[1] + 0x124);
                      do {
                        if ((short)piVar5[-0x48] == 0) {
                          if (bVar2) {
LAB_005e3d61:
                            if ((*(int *)puVar6[3] == 0) && (*piVar5 != 0)) {
                              FUN_005d5ba0(*(int *)(*piVar5 + 0x10) * piVar5[-0x46],0x208,
                                           **(undefined4 **)(*piVar5 + 0x14),0,(int *)puVar6[3],
                                           param_2);
                              *(undefined1 *)(local_1c + 0x67) = 1;
                              *(undefined1 *)(*(int *)*puVar6 + 0x210) = 1;
                            }
                          }
                        }
                        else if (DAT_00a37dc8 != 0) goto LAB_005e3d61;
                        iVar3 = iVar3 + 1;
                        piVar5 = piVar5 + 0x4e;
                        puVar6 = puVar6 + 6;
                      } while (iVar3 < *piVar4);
                    }
                  }
                  local_14 = local_14 + 1;
                  local_10 = local_10 + 0x2e;
                  piVar4 = piVar4 + 0x1f;
                } while (local_14 < *local_8);
              }
            }
            local_18 = local_18 + 0xae;
            local_c = local_c + 1;
            local_8 = local_8 + 0x75;
          } while (local_c < *(int *)(iVar1 + 0x7c));
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}

