
uint FUN_005f6360(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined *local_2a4 [33];
  undefined1 local_220 [64];
  undefined4 local_1e0;
  int local_1dc;
  undefined4 local_1c4;
  undefined4 local_1c0;
  int local_184;
  uint local_180;
  int local_178;
  uint local_168;
  int local_cc;
  int local_18;
  uint local_14;
  undefined1 *local_10;
  int local_c;
  char local_5;
  
  local_10 = (undefined1 *)0x0;
  (**(code **)(param_1 + 8))(&local_5,1,1,*(undefined4 *)(param_1 + 0x18));
  (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x18),0,0,0);
  if (local_5 == -1) {
    FUN_0056d380(&local_1e0,0,0x1c8);
    local_1e0 = FUN_00683b90(local_2a4);
    local_2a4[0] = &DAT_005f6160;
    iVar2 = __setjmp3(local_220,0);
    if (iVar2 != 0) {
LAB_005f63dd:
      FUN_006835a0(&local_1e0);
      return 0xffffffff;
    }
    FUN_006834c0(&local_1e0,0x5a,0x1c8);
    FUN_005f6180(&local_1e0,param_1);
    if (param_4 == 1) {
      FUN_00683150(&local_1e0,0xe1,0xffff);
    }
    FUN_006835b0(&local_1e0,1);
    if (param_4 == 1) {
      if ((((((local_cc == 0) || (*(char *)(local_cc + 4) != -0x1f)) ||
            (uVar8 = *(uint *)(local_cc + 0xc), uVar8 < 6)) ||
           ((pcVar1 = *(char **)(local_cc + 0x10), *pcVar1 != 'E' || (pcVar1[1] != 'x')))) ||
          ((pcVar1[2] != 'i' || ((pcVar1[3] != 'f' || (pcVar1[4] != '\0')))))) ||
         (pcVar1[5] != '\0')) goto LAB_005f63dd;
      if (param_5 == 0) {
        FUN_006835a0(&local_1e0);
        return uVar8;
      }
      if (uVar8 <= param_6) {
        FUN_0056d420(param_5,pcVar1,uVar8);
        FUN_006835a0(&local_1e0);
        return uVar8;
      }
    }
    else {
      if (param_3 != 0) {
        *(undefined4 *)(param_2 + 0x428) = local_1c4;
        *(undefined4 *)(param_2 + 0x42c) = local_1c0;
        *(undefined4 *)(param_2 + 0x430) = 0;
LAB_005f670e:
        *(undefined1 **)(param_2 + 0x434) = local_10;
        if (local_c == 1) {
          FUN_005445c0(param_2);
        }
        else if (local_c == 3) {
          FUN_00544560(param_2);
        }
        FUN_006835a0(&local_1e0);
        return 0;
      }
      FUN_00683940(&local_1e0);
      local_c = 3;
      if (local_178 != 4) {
        local_c = local_178;
      }
      iVar2 = local_184 * local_c;
      uVar8 = local_184 * local_178;
      local_18 = iVar2;
      local_14 = uVar8;
      piVar3 = (int *)(**(code **)(local_1dc + 8))(&local_1e0,1,uVar8,1);
      puVar4 = (undefined1 *)
               FUN_0056e030(local_180 * iVar2,s_D__DxLib_Develop_Source_Library__00a058f8,0x4d1);
      local_10 = puVar4;
      if (puVar4 != (undefined1 *)0x0) {
        if (local_168 < local_180) {
          do {
            FUN_00683af0(&local_1e0,piVar3,1);
            uVar5 = 0;
            puVar7 = puVar4;
            if (uVar8 != 0) {
              do {
                if (local_178 == 1) {
                  puVar4 = puVar7 + 1;
                  uVar6 = uVar5 + 1;
                  *puVar7 = *(undefined1 *)(uVar5 + *piVar3);
                }
                else if (local_178 == 3) {
                  *puVar7 = *(undefined1 *)(uVar5 + 2 + *piVar3);
                  puVar4 = puVar7 + 3;
                  uVar6 = uVar5 + 3;
                  puVar7[1] = *(undefined1 *)(uVar5 + 1 + *piVar3);
                  puVar7[2] = *(undefined1 *)(uVar5 + *piVar3);
                }
                else {
                  uVar6 = uVar5;
                  puVar4 = puVar7;
                  if (local_178 == 4) {
                    puVar4 = puVar7 + 3;
                    *puVar7 = (char)(((uint)*(byte *)(uVar5 + *piVar3 + 3) *
                                     (uint)*(byte *)(uVar5 + *piVar3 + 2)) / 0xff);
                    puVar7[1] = (char)(((uint)*(byte *)(uVar5 + *piVar3 + 3) *
                                       (uint)*(byte *)(uVar5 + *piVar3 + 1)) / 0xff);
                    uVar6 = uVar5 + 4;
                    puVar7[2] = (char)(((uint)((byte *)(uVar5 + *piVar3))[3] *
                                       (uint)*(byte *)(uVar5 + *piVar3)) / 0xff);
                    uVar8 = local_14;
                  }
                }
                uVar5 = uVar6;
                puVar7 = puVar4;
              } while (uVar6 < uVar8);
            }
          } while (local_168 < local_180);
        }
        FUN_00683880(&local_1e0);
        *(int *)(param_2 + 0x428) = local_184;
        *(uint *)(param_2 + 0x42c) = local_180;
        *(int *)(param_2 + 0x430) = local_18;
        goto LAB_005f670e;
      }
    }
    FUN_006835a0(&local_1e0);
  }
  return 0xffffffff;
}

